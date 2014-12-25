#include <stdlib.h>
#include <stdio.h>

int Bonus_yatzy(struct yatzy_player *player) {

  int total = 0;

  total += player->ones;
  total += player->twos;
  total += player->threes;
  total += player->fours;
  total += player->fives;
  total += player->sixes;

  return (total >= 63 ? 50 : 0);
}
