
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

  yatzy_ui_ask_for_players(game);


  // refresh();
  // getch();
  endwin();

  //
  // // struct yatzy_player *linus;
  //
  // // linus = yatzy_player_create("Linus");
  //
  // yatzy_game_ask_for_players(game);
  //
  // // printf("The first player is: %s", game->players[0]->name);
  //
  // yatzy_game_print_scorecard(game);
  //
  // struct yatzy_hand *hand;
  //
  // hand = yatzy_hand_run();

  return 0;
}
