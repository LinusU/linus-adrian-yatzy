
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

void yatzy_ui_endgame_show(struct yatzy_game *game) {

  int i;
  WINDOW *win;

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
    mvwaddnstr(win, y, 9, game->players[i]->name, 28);
    mvwprintw(win, y, 38, "%3d", yatzy_player_total_score(game->players[i]));
  }

  wgetch(win);
  delwin(win);

  echo();
  curs_set(1);
  refresh();
}

#undef W
#undef H
