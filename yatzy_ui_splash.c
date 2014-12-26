
#define W 45
#define H 16

const char SPLASH[H][W] = {
  "                                             ",
  "   ---------------------------------------   ",
  "  < < < < < < C H R I S T M A S > > > > > >  ",
  "   ---------------------------------------   ",
  "   __   __   ___    _____   ____  __   __    ",
  "   \\ \\_/ /  / _ \\  |_   _| |__  | \\ \\_/ /    ",
  "    \\   /  / |_| \\   | |     / /   \\   /     ",
  "     | |   | ___ |   | |    / /_    | |      ",
  "     |_|   |_| |_|   |_|   |____|   |_|      ",
  "                                             ",
  "   ---------------------------------------   ",
  "  < < < < < < C H R I S T M A S > > > > > >  ",
  "   ---------------------------------------   ",
  "                                             ",
  "           PUSH ANY KEY TO START             ",
  "                                             "
};

void yatzy_ui_splash_show() {

  int i;
  WINDOW *win;

  noecho();
  curs_set(0);

  win = newwin(H + 2, W + 2, 0, 0);
  wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);

  for (i=0; i<H; i++) {
    wmove(win, i + 1, 1);
    waddnstr(win, SPLASH[i], W);
  }

  wgetch(win);
  delwin(win);

  echo();
  curs_set(1);
  refresh();
}

#undef W
#undef H
