
#define W 45
#define H 24

const char ENDGAME[H][W] = {
  "  < < < < < < C H R I S T M A S > > > > > >  ",
  "_____________________________________________",
  "                                             ",
  "                  S C O R E                  ",
  "                 ___________                 ",
  "                                             ",
  "                                             ",
  "                                             ",
  "                                             ",
  "                                             ",
  "                                             ",
  "                                             ",
  "                                             ",
  "                                             ",
  "                                             ",
  "                                             ",
  "                                             ",
  "                                             ",
  "                                             ",
  "                                             ",
  "                                             ",
  "_____________________________________________",
  "                                             ",
  "  < < < < < < C H R I S T M A S > > > > > >  "
};

struct yatzy_ui_endgame {
  int score;
  char *name;
};

void yatzy_ui_endgame_show(struct yatzy_game *game) {

  int i;
  WINDOW *win;
  struct yatzy_ui_endgame tmp;
  struct yatzy_ui_endgame list[game->totalPlayers];

  for (i=0; i<game->totalPlayers; i++) {
    list[i].score = yatzy_player_total_score(game->players[i]);
    list[i].name = game->players[i]->name;
  }

  bool sorted = false;
  while (sorted == false) {
    sorted = true;

    for (i=1; i<game->totalPlayers; i++) {
      if (list[i - 1].score < list[i].score) {
        memcpy(&tmp, &list[i], sizeof(struct yatzy_ui_endgame));
        memcpy(&list[i], &list[i - 1], sizeof(struct yatzy_ui_endgame));
        memcpy(&list[i - 1], &tmp, sizeof(struct yatzy_ui_endgame));
        sorted = false;
      }
    }

  }

  noecho();
  curs_set(0);

  win = newwin(H + 2, W + 2, 0, 0);
  wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);

  for (i=0; i<H; i++) {
    wmove(win, i + 1, 1);
    waddnstr(win, ENDGAME[i], W);
  }

  for (i=0; i<game->totalPlayers; i++) {
    int y = 7 + (i * 2);
    mvwprintw(win, y, 6, "%d.", (i + 1));
    mvwaddnstr(win, y, 9, list[i].name, 28);
    mvwprintw(win, y, 38, "%3d", list[i].score);
  }

  wgetch(win);
  delwin(win);

  echo();
  curs_set(1);
  refresh();
}

#undef W
#undef H
