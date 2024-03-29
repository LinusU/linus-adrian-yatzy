
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define _XOPEN_SOURCE_EXTENDED 1
#include <ncurses.h>

#include "yatzy_player.c"
#include "yatzy_game.c"
#include "yatzy_hand_score.c"
#include "yatzy_hand.c"
#include "yatzy_ui.c"
#include "yatzy_ui_splash.c"
#include "yatzy_ui_endgame.c"
#include "yatzy_ui_scoreboard.c"

int main(int argc, char *argv[]) {

  setlocale(LC_CTYPE, "UTF-8");

  srand(time(NULL));
  initscr();

  yatzy_ui_splash_show();

  WINDOW *scoreboard;

  struct yatzy_game *game;
  game = yatzy_game_create();

  yatzy_ui_ask_for_players(game);

  scoreboard = yatzy_ui_scoreboard_create(game);

  for (int turn=0; turn<15; turn++) {
    for (game->currentPlayer = 0; game->currentPlayer < game->totalPlayers; game->currentPlayer++) {
      yatzy_ui_scoreboard_refresh(scoreboard, game);
      yatzy_ui_play_hand(game, game->players[game->currentPlayer]);
      yatzy_player_update_bonus(game->players[game->currentPlayer]);
    }
  }

  yatzy_ui_scoreboard_refresh(scoreboard, game);
  yatzy_ui_endgame_show(game);

  endwin();

  return 0;
}
