
#include <stdlib.h>
#include <time.h>

#include <ncurses.h>

#include "yatzy_player.c"
#include "yatzy_game.c"
#include "yatzy_hand.c"
#include "yatzy_ui.c"

int main(int argc, char *argv[]) {

  srand(time(NULL));
  initscr();

  struct yatzy_game *game;
  game = yatzy_game_create();

  // yatzy_ui_ask_for_players(game);
  yatzy_game_add_player(game, yatzy_player_create("LU"));
  yatzy_game_add_player(game, yatzy_player_create("AE"));


  yatzy_ui_show_scoreboard(game);

  yatzy_ui_play_hand(game, game->players[0]);


  // refresh();
  // getch();
  endwin();

  return 0;
}
