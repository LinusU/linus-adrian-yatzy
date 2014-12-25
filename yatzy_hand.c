
#include <stdlib.h>
#include <stdbool.h>

struct yatzy_hand {
  int die[5];
  bool lock[5];
};

enum yatzy_combination {
  ONES,
  TWOS,
  THREES,
  FOURS,
  FIVES,
  SIXES,
  BONUS,
  PAIR1,
  PAIR2,
  KIND3,
  KIND4,
  STRAIGHT1,
  STRAIGHT2,
  HOUSE,
  CHANCE,
  YATZY
};

int rand_dice() {
  return rand() % 6;
}

struct yatzy_hand* yatzy_hand_create() {
  debug("yatzy_hand_create");

  struct yatzy_hand *hand;

  hand = malloc(sizeof(struct yatzy_hand));

  hand->die[0] = rand_dice();
  hand->die[1] = rand_dice();
  hand->die[2] = rand_dice();
  hand->die[3] = rand_dice();
  hand->die[4] = rand_dice();

  hand->lock[0] = true;
  hand->lock[1] = true;
  hand->lock[2] = true;
  hand->lock[3] = true;
  hand->lock[4] = true;

  return hand;
}

int yatzy_hand_combination_score(struct yatzy_hand *hand, enum yatzy_combination combination) {

  // TODO

















  return 0;
}
