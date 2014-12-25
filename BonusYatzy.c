#include <stdlib.h>
#include <stdio.h>

int Bonus_yatzy(struct yatzy_player *player) {

  int total = 0;
  int bonus = 0;

  total += player->ones;
  total += player->twos;
  total += player->threes;
  total += player->fours;
  total += player->fives;
  total += player->sixes;

  if (total>=63) {
    bonus = 50;
  }

return bonus;

}
