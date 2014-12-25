
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

#include "BonusYatzy.c"

struct yatzy_player* yatzy_player_create(char *name) {

  struct yatzy_player *player;

  player = (struct yatzy_player*) malloc(sizeof(struct yatzy_player));

  player->name = (char*) malloc(strlen(name) + 1);
  strcpy(player->name, name);

  player->ones = -1;
  player->twos = -1;
  player->threes = -1;
  player->fours = -1;
  player->fives = -1;
  player->sixes = -1;

  player->bonus = 0;

  player->pair1 = -1;
  player->pair2 = -1;
  player->kind3 = -1;
  player->kind4 = -1;
  player->straight1 = -1;
  player->straight2 = -1;
  player->house = -1;
  player->chance = -1;
  player->yatzy = -1;

  return player;
}

void yatzy_player_update_bonus(struct yatzy_player *player) {
  player->bonus = Bonus_yatzy(player);
}

int yatzy_player_upper_score(struct yatzy_player* player) {

  int total = 0;

  if (player->ones > 0) { total += player->ones; }
  if (player->twos > 0) { total += player->twos; }
  if (player->threes > 0) { total += player->threes; }
  if (player->fours > 0) { total += player->fours; }
  if (player->fives > 0) { total += player->fives; }
  if (player->sixes > 0) { total += player->sixes; }

  return total;
}

int yatzy_player_total_score(struct yatzy_player* player) {

  int total = yatzy_player_upper_score(player);

  total += player->bonus;

  if (player->pair1 > 0) { total += player->pair1; }
  if (player->pair2 > 0) { total += player->pair2; }
  if (player->kind3 > 0) { total += player->kind3; }
  if (player->kind4 > 0) { total += player->kind4; }
  if (player->straight1 > 0) { total += player->straight1; }
  if (player->straight2 > 0) { total += player->straight2; }
  if (player->house > 0) { total += player->house; }
  if (player->chance > 0) { total += player->chance; }
  if (player->yatzy > 0) { total += player->yatzy; }

  return total;
}
