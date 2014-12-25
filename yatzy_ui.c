
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
