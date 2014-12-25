
char STRIKE[] = {113, 113, 113, 0};

WINDOW* yatzy_ui_scoreboard_create() {

  WINDOW *win;

  win = newwin(25, 43, 0, 48);
  wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);

  return win;
}

void yatzy_ui_scoreboard_destroy(WINDOW *win) {
  delwin(win);
}

void yatzy_ui_scoreboard_print_score(WINDOW *win, int y, int x, int score) {
  switch (score) {
    case -1: mvwprintw(win, y, x, "   "); break;
    case  0: mvwhline(win, y, x, 0, 3); break;
    default: mvwprintw(win, y, x, "%3d", score); break;
  }
}

void yatzy_ui_scoreboard_refresh(WINDOW *win, struct yatzy_game *game) {

  noecho();
  curs_set(0);

  mvwprintw(win,  1, 1, "Player");

  mvwprintw(win,  3, 1, "Ones");
  mvwprintw(win,  4, 1, "Twos");
  mvwprintw(win,  5, 1, "Threes");
  mvwprintw(win,  6, 1, "Fours");
  mvwprintw(win,  7, 1, "Fives");
  mvwprintw(win,  8, 1, "Sixes");

  mvwprintw(win, 10, 1, "Total");
  mvwprintw(win, 11, 1, "Bonus");

  mvwprintw(win, 13, 1, "1 Pair");
  mvwprintw(win, 14, 1, "2 Pairs");
  mvwprintw(win, 15, 1, "3 of a kind");
  mvwprintw(win, 16, 1, "4 of a kind");
  mvwprintw(win, 17, 1, "Small straight");
  mvwprintw(win, 18, 1, "Large straight");
  mvwprintw(win, 19, 1, "Full house");
  mvwprintw(win, 20, 1, "Chance");
  mvwprintw(win, 21, 1, "YATZY");

  mvwprintw(win, 23, 1, "Total");

  int i;

  for (i=0; i<game->totalPlayers; i++) {

    char shortName[4];
    int offset = 18 + (i * 4);

    memset(shortName + 3, 0, 1);
    memcpy(shortName + 0, game->players[i]->name, 3);

    mvwvline(win, 1, offset, 0, 23);

    mvwprintw(win,  1, offset + 1, "%s", shortName);

    yatzy_ui_scoreboard_print_score(win,  3, offset + 1, game->players[i]->ones);
    yatzy_ui_scoreboard_print_score(win,  4, offset + 1, game->players[i]->twos);
    yatzy_ui_scoreboard_print_score(win,  5, offset + 1, game->players[i]->threes);
    yatzy_ui_scoreboard_print_score(win,  6, offset + 1, game->players[i]->fours);
    yatzy_ui_scoreboard_print_score(win,  7, offset + 1, game->players[i]->fives);
    yatzy_ui_scoreboard_print_score(win,  8, offset + 1, game->players[i]->sixes);

    mvwprintw(win, 10, offset + 1, "%3d", yatzy_player_upper_score(game->players[i]));
    mvwprintw(win, 11, offset + 1, "%3d", game->players[i]->bonus);

    yatzy_ui_scoreboard_print_score(win, 13, offset + 1, game->players[i]->pair1);
    yatzy_ui_scoreboard_print_score(win, 14, offset + 1, game->players[i]->pair2);
    yatzy_ui_scoreboard_print_score(win, 15, offset + 1, game->players[i]->kind3);
    yatzy_ui_scoreboard_print_score(win, 16, offset + 1, game->players[i]->kind4);
    yatzy_ui_scoreboard_print_score(win, 17, offset + 1, game->players[i]->straight1);
    yatzy_ui_scoreboard_print_score(win, 18, offset + 1, game->players[i]->straight2);
    yatzy_ui_scoreboard_print_score(win, 19, offset + 1, game->players[i]->house);
    yatzy_ui_scoreboard_print_score(win, 20, offset + 1, game->players[i]->chance);
    yatzy_ui_scoreboard_print_score(win, 21, offset + 1, game->players[i]->yatzy);

    mvwprintw(win, 23, offset + 1, "%3d", yatzy_player_total_score(game->players[i]));

  }

  wrefresh(win);

  echo();
  curs_set(1);
}
