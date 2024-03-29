
#include <stdio.h>
#include <stdbool.h>

#define debug(...)
// #define debug(...) fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n");

struct yatzy_game {
  int totalPlayers;
  int currentPlayer;
  struct yatzy_player **players;
};

struct yatzy_game* yatzy_game_create() {
  debug("yatzy_game_create");

  struct yatzy_game *game;

  game = malloc(sizeof(struct yatzy_game));

  game->totalPlayers = 0;
  game->currentPlayer = 0;
  game->players = NULL;

  return game;
}

void yatzy_game_add_player(struct yatzy_game *game, struct yatzy_player *player) {

  int n = game->totalPlayers;

  game->totalPlayers++;
  game->players = realloc(game->players, game->totalPlayers * sizeof(void *));
  game->players[n] = player;

}

void yatzy_game_print_scorecard(struct yatzy_game *game) {

  printf(

    "+-------------------+----+----+\n"
    "+ Player            + %s  + %s  +\n"
    "+-------------------+----+----+\n"
    "+ Ones              + %2d + %2d +\n"
    "+ Twos              + %2d + %2d +\n"
    "+ Threes            + %2d + %2d +\n"
    "+ Fours             + %2d + %2d +\n"
    "+ Fives             + %2d + %2d +\n"
    "+ Sixes             + %2d + %2d +\n"
    "+-------------------+----+----+\n"


    ,
    game->players[0]->name,
    game->players[1]->name,

    game->players[0]->ones,
    game->players[1]->ones,
    game->players[0]->twos,
    game->players[1]->twos,
    game->players[0]->threes,
    game->players[1]->threes,
    game->players[0]->fours,
    game->players[1]->fours,
    game->players[0]->fives,
    game->players[1]->fives,
    game->players[0]->sixes,
    game->players[1]->sixes

  );

}
