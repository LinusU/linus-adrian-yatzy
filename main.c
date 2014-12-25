
#include <stdlib.h>
#include <time.h>

#include <ncurses.h>

#include "yatzy_player.c"
#include "yatzy_game.c"
#include "yatzy_hand.c"
#include "yatzy_ui.c"
#include "yatzy_ui_scoreboard.c"

int main(int argc, char *argv[]) {

  srand(time(NULL));
  initscr();

  WINDOW *scoreboard;

  struct yatzy_game *game;
  game = yatzy_game_create();

  yatzy_ui_ask_for_players(game);
  // yatzy_game_add_player(game, yatzy_player_create("LU"));
  // yatzy_game_add_player(game, yatzy_player_create("AE"));

  scoreboard = yatzy_ui_scoreboard_create(game);

  for (int turn=0; turn<15; turn++) {
    for (game->currentPlayer = 0; game->currentPlayer < game->totalPlayers; game->currentPlayer++) {
      yatzy_ui_scoreboard_refresh(scoreboard, game);
      yatzy_ui_play_hand(game, game->players[game->currentPlayer]);
      yatzy_player_update_bonus(game->players[game->currentPlayer]);
    }
  }

  yatzy_ui_scoreboard_refresh(scoreboard, game);
  wgetch(scoreboard);

  endwin();

  return 0;
}
