
#include <stdlib.h>
#include <string.h>

struct yatzy_player {

  char *name;

  int ones;
  int twos;
  int threes;
  int fours;
  int fives;
  int sixes;

  int bonus;

  int pair1;
  int pair2;
  int kind3;
  int kind4;
  int straight1;
  int straight2;
  int house;
  int chance;
  int yatzy;

};

struct yatzy_player* yatzy_player_create(char *name) {

  struct yatzy_player *player;

  player = (struct yatzy_player*) malloc(sizeof(struct yatzy_player));

  memset(player, 0, sizeof(struct yatzy_player));

  player->name = (char*) malloc(strlen(name) + 1);

  strcpy(player->name, name);

  return player;
}

int yatzy_player_total_score(struct yatzy_player* player) {

  // FIXME

  return 0;
}
