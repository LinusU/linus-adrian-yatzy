
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

void yatzy_ui_show_scoreboard(struct yatzy_game *game) {

  WINDOW *win;

  win = newwin(24, 32, 0, 0);
  wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);

  mvwprintw(win,  1, 1, "Player");

  mvwprintw(win,  3, 1, "Ones");
  mvwprintw(win,  4, 1, "Twos");
  mvwprintw(win,  5, 1, "Threes");
  mvwprintw(win,  6, 1, "Fours");
  mvwprintw(win,  7, 1, "Fives");
  mvwprintw(win,  8, 1, "Sixes");

  mvwprintw(win, 10, 1, "Bonus");

  mvwprintw(win, 12, 1, "1 Pair");
  mvwprintw(win, 13, 1, "2 Pairs");
  mvwprintw(win, 14, 1, "3 of a kind");
  mvwprintw(win, 15, 1, "4 of a kind");
  mvwprintw(win, 16, 1, "Small straight");
  mvwprintw(win, 17, 1, "Large straight");
  mvwprintw(win, 18, 1, "Full house");
  mvwprintw(win, 19, 1, "Chance");
  mvwprintw(win, 20, 1, "YATZY");

  mvwprintw(win, 22, 1, "Total");

  int i;

  for (i=0; i<game->totalPlayers; i++) {

    int offset = 20 + (i * 4);

    mvwprintw(win,  1, offset + 1, "%s", game->players[i]->name);

    mvwprintw(win,  3, offset + 1, "%2d", game->players[i]->ones);
    mvwprintw(win,  4, offset + 1, "%2d", game->players[i]->twos);
    mvwprintw(win,  5, offset + 1, "%2d", game->players[i]->threes);
    mvwprintw(win,  6, offset + 1, "%2d", game->players[i]->fours);
    mvwprintw(win,  7, offset + 1, "%2d", game->players[i]->fives);
    mvwprintw(win,  8, offset + 1, "%2d", game->players[i]->sixes);

    mvwprintw(win, 10, offset + 1, "%2d", game->players[i]->bonus);

    mvwprintw(win, 12, offset + 1, "%2d", game->players[i]->pair1);
    mvwprintw(win, 13, offset + 1, "%2d", game->players[i]->pair2);
    mvwprintw(win, 14, offset + 1, "%2d", game->players[i]->kind3);
    mvwprintw(win, 15, offset + 1, "%2d", game->players[i]->kind4);
    mvwprintw(win, 16, offset + 1, "%2d", game->players[i]->straight1);
    mvwprintw(win, 17, offset + 1, "%2d", game->players[i]->straight2);
    mvwprintw(win, 18, offset + 1, "%2d", game->players[i]->house);
    mvwprintw(win, 19, offset + 1, "%2d", game->players[i]->chance);
    mvwprintw(win, 20, offset + 1, "%2d", game->players[i]->yatzy);

    mvwprintw(win, 22, offset + 1, "%2d", yatzy_player_total_score(game->players[i]));

  }

  wrefresh(win);
  wgetch(win);
  delwin(win);
}

void yatzy_ui_print_die(WINDOW *win, int y, int x, int die, bool lock) {

  mvwprintw(win, y + 0, x, "+-----+");
  mvwprintw(win, y + 1, x, "|     |");
  mvwprintw(win, y + 2, x, "|     |");
  mvwprintw(win, y + 3, x, "|     |");
  mvwprintw(win, y + 4, x, "+-----+");

  if (lock == false) {
    mvwprintw(win, y + 2, x + 2, " ? ");
    return ;
  }

  switch (die) {
  case 0:
    mvwprintw(win, y + 2, x + 2, " o ");
    break;
  case 1:
    mvwprintw(win, y + 1, x + 2, "  o");
    mvwprintw(win, y + 3, x + 2, "o  ");
    break;
  case 2:
    mvwprintw(win, y + 1, x + 2, "  o");
    mvwprintw(win, y + 2, x + 2, " o ");
    mvwprintw(win, y + 3, x + 2, "o  ");
    break;
  case 3:
    mvwprintw(win, y + 1, x + 2, "o o");
    mvwprintw(win, y + 3, x + 2, "o o");
    break;
  case 4:
    mvwprintw(win, y + 1, x + 2, "o o");
    mvwprintw(win, y + 2, x + 2, " o ");
    mvwprintw(win, y + 3, x + 2, "o o");
    break;
  case 5:
    mvwprintw(win, y + 1, x + 2, "o o");
    mvwprintw(win, y + 2, x + 2, "o o");
    mvwprintw(win, y + 3, x + 2, "o o");
    break;
  }

}

void yatzy_ui_play_hand(struct yatzy_game *game, struct yatzy_player *player) {

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

    int i, ch;

    for (i=0; i<5; i++) {
      yatzy_ui_print_die(win, 3, 2 + i * 9, hand->die[i], hand->lock[i]);
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

  mvwprintw(win,  9, 2, "1 - Ones");
  mvwprintw(win, 10, 2, "2 - Twos");
  mvwprintw(win, 11, 2, "3 - Threes");
  mvwprintw(win, 12, 2, "4 - Fours");
  mvwprintw(win, 13, 2, "5 - Fives");
  mvwprintw(win, 14, 2, "6 - Sixes");

  mvwprintw(win, 16, 2, "Q - 1 Pair");
  mvwprintw(win, 17, 2, "W - 2 Pairs");
  mvwprintw(win, 18, 2, "E - 3 of a kind");
  mvwprintw(win, 19, 2, "R - 4 of a kind");
  mvwprintw(win, 20, 2, "T - Small straight");
  mvwprintw(win, 21, 2, "Y - Large straight");
  mvwprintw(win, 22, 2, "U - Full house");
  mvwprintw(win, 23, 2, "I - Chance");
  mvwprintw(win, 24, 2, "O - YATZY");

  wgetch(win);

  echo();
  curs_set(1);
  delwin(win);
}
