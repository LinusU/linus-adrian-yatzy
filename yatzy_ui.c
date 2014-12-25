
#include <ncurses.h>

void yatzy_ui_ask_for_players(struct yatzy_game *game) {

  int i;
  WINDOW *win;
  char names[6][20] = {0};

  win = newwin(8, 30, 0, 0);
  wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);

  for (i=0; i<6; i++) {
    wmove(win, i + 1, 2);
    wprintw(win, "Player %d: %s", i + 1, names[i]);
  }

  for (i=0; i<6; i++) {
    wmove(win, i + 1, 12);
    wgetstr(win, names[i]);

    if (names[i][0] == '\0') {
      break;
    }
  }

  for (i=0; i<6; i++) {
    if (names[i][0] == '\0') {
      break;
    }

    yatzy_game_add_player(game, yatzy_player_create(names[i]));
  }

  delwin(win);
}

void yatzy_ui_print_die(WINDOW *win, int y, int x, int accessor, int die, bool lock) {

  mvwprintw(win, y + 0, x, "+-----+");
  mvwprintw(win, y + 1, x, "|     |");
  mvwprintw(win, y + 2, x, "|     |");
  mvwprintw(win, y + 3, x, "|     |");
  mvwprintw(win, y + 4, x, "+-----+");

  wattron(win, A_BOLD);
  mvwprintw(win, y + 6, x + 3, "%d", accessor);
  wattroff(win, A_BOLD);

  if (lock == false) {
    mvwprintw(win, y + 2, x + 2, " ? ");
    return ;
  }

  switch (die) {
  case 1:
    mvwprintw(win, y + 2, x + 2, " o ");
    break;
  case 2:
    mvwprintw(win, y + 1, x + 2, "  o");
    mvwprintw(win, y + 3, x + 2, "o  ");
    break;
  case 3:
    mvwprintw(win, y + 1, x + 2, "  o");
    mvwprintw(win, y + 2, x + 2, " o ");
    mvwprintw(win, y + 3, x + 2, "o  ");
    break;
  case 4:
    mvwprintw(win, y + 1, x + 2, "o o");
    mvwprintw(win, y + 3, x + 2, "o o");
    break;
  case 5:
    mvwprintw(win, y + 1, x + 2, "o o");
    mvwprintw(win, y + 2, x + 2, " o ");
    mvwprintw(win, y + 3, x + 2, "o o");
    break;
  case 6:
    mvwprintw(win, y + 1, x + 2, "o o");
    mvwprintw(win, y + 2, x + 2, "o o");
    mvwprintw(win, y + 3, x + 2, "o o");
    break;
  }

}

void yatzy_ui_print_first_letter_bold(WINDOW *win, int y, int x, const char *text) {
  char first[2] = {text[0], 0};

  wattron(win, A_BOLD);
  mvwprintw(win, y, x, first);

  wattroff(win, A_BOLD);
  mvwprintw(win, y, x + 1, &(text[1]));
}

void yatzy_ui_play_hand(struct yatzy_game *game, struct yatzy_player *player) {

  int i;
  WINDOW *win;
  struct yatzy_hand *hand;

  noecho();
  curs_set(0);

  hand = yatzy_hand_create();

  win = newwin(26, 47, 0, 0);
  wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);

  mvwprintw(win, 1, 2, "%s's hand", player->name);

  int tries = 2;

  do {

    int ch;

    for (i=0; i<5; i++) {
      yatzy_ui_print_die(win, 3, 2 + i * 9, i + 1, hand->die[i], hand->lock[i]);
    }

    if (tries > 0) {
      mvwprintw(win, 1, 47 - 17, "%d more shuffles", tries);
    } else {
      mvwprintw(win, 1, 47 - 17, "           done");
      break;
    }

    wrefresh(win);
    ch = wgetch(win);

    if (ch >= 49 && ch < 54) {
      hand->lock[ch - 49] ^= true;
    }

    if (ch == 10) {

      bool modified = false;

      for (i=0; i<5; i++) {
        if (hand->lock[i] == false) {
          modified = true;
          hand->die[i] = rand_dice();
          hand->lock[i] = true;
        }
      }

      if (modified == true) {
        tries--;
      } else {
        tries = 0;
      }

    }

  } while (true);

  // Hide numbers under dice
  for (i=0; i<5; i++) {
    mvwprintw(win, 9, 5 + i * 9, " ");
  }

  if(player->ones == -1) { yatzy_ui_print_first_letter_bold(win,  9, 2, "1 - Ones"); }
  if(player->twos == -1) { yatzy_ui_print_first_letter_bold(win, 10, 2, "2 - Twos"); }
  if(player->threes == -1) { yatzy_ui_print_first_letter_bold(win, 11, 2, "3 - Threes"); }
  if(player->fours == -1) { yatzy_ui_print_first_letter_bold(win, 12, 2, "4 - Fours"); }
  if(player->fives == -1) { yatzy_ui_print_first_letter_bold(win, 13, 2, "5 - Fives"); }
  if(player->sixes == -1) { yatzy_ui_print_first_letter_bold(win, 14, 2, "6 - Sixes"); }

  if (player->pair1 == -1) { yatzy_ui_print_first_letter_bold(win, 16, 2, "Q - 1 Pair"); }
  if (player->pair2 == -1) { yatzy_ui_print_first_letter_bold(win, 17, 2, "W - 2 Pairs"); }
  if (player->kind3 == -1) { yatzy_ui_print_first_letter_bold(win, 18, 2, "E - 3 of a kind"); }
  if (player->kind4 == -1) { yatzy_ui_print_first_letter_bold(win, 19, 2, "R - 4 of a kind"); }
  if (player->straight1 == -1) { yatzy_ui_print_first_letter_bold(win, 20, 2, "T - Small straight"); }
  if (player->straight2 == -1) { yatzy_ui_print_first_letter_bold(win, 21, 2, "Y - Large straight"); }
  if (player->house == -1) { yatzy_ui_print_first_letter_bold(win, 22, 2, "U - Full house"); }
  if (player->chance == -1) { yatzy_ui_print_first_letter_bold(win, 23, 2, "I - Chance"); }
  if (player->yatzy == -1) { yatzy_ui_print_first_letter_bold(win, 24, 2, "O - YATZY"); }

  bool again = false;

  do {
    int ch = wgetch(win);
    enum yatzy_combination combination;

    again = false;

    switch (ch) {
      case '1': combination = ONES; break;
      case '2': combination = TWOS; break;
      case '3': combination = THREES; break;
      case '4': combination = FOURS; break;
      case '5': combination = FIVES; break;
      case '6': combination = SIXES; break;
      case 'Q': case 'q': combination = PAIR1; break;
      case 'W': case 'w': combination = PAIR2; break;
      case 'E': case 'e': combination = KIND3; break;
      case 'R': case 'r': combination = KIND4; break;
      case 'T': case 't': combination = STRAIGHT1; break;
      case 'Y': case 'y': combination = STRAIGHT2; break;
      case 'U': case 'u': combination = HOUSE; break;
      case 'I': case 'i': combination = CHANCE; break;
      case 'O': case 'o': combination = YATZY; break;
      default: again = true;
    }

    if (again == true) {
      continue;
    }

    int currentScore;

    switch (ch) {
      case '1': currentScore = player->ones; break;
      case '2': currentScore = player->twos; break;
      case '3': currentScore = player->threes; break;
      case '4': currentScore = player->fours; break;
      case '5': currentScore = player->fives; break;
      case '6': currentScore = player->sixes; break;
      case 'Q': case 'q': currentScore = player->pair1; break;
      case 'W': case 'w': currentScore = player->pair2; break;
      case 'E': case 'e': currentScore = player->kind3; break;
      case 'R': case 'r': currentScore = player->kind4; break;
      case 'T': case 't': currentScore = player->straight1; break;
      case 'Y': case 'y': currentScore = player->straight2; break;
      case 'U': case 'u': currentScore = player->house; break;
      case 'I': case 'i': currentScore = player->chance; break;
      case 'O': case 'o': currentScore = player->yatzy; break;
    }

    if (currentScore != -1) {
      again = true;
      continue;
    }

    int score = yatzy_hand_combination_score(hand, combination);

    switch (ch) {
      case '1': player->ones = score; break;
      case '2': player->twos = score; break;
      case '3': player->threes = score; break;
      case '4': player->fours = score; break;
      case '5': player->fives = score; break;
      case '6': player->sixes = score; break;
      case 'Q': case 'q': player->pair1 = score; break;
      case 'W': case 'w': player->pair2 = score; break;
      case 'E': case 'e': player->kind3 = score; break;
      case 'R': case 'r': player->kind4 = score; break;
      case 'T': case 't': player->straight1 = score; break;
      case 'Y': case 'y': player->straight2 = score; break;
      case 'U': case 'u': player->house = score; break;
      case 'I': case 'i': player->chance = score; break;
      case 'O': case 'o': player->yatzy = score; break;
    }

  } while (again);

  echo();
  curs_set(1);
  delwin(win);
}
