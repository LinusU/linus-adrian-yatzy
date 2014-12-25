
#include <stdlib.h>
#include <stdbool.h>

#include "Chance_yatzy.c"
#include "CheckForPair.c"
#include "FourOfAKind.c"
#include "House_yatzy.c"
#include "PlainNumbers_yatzy.c"
#include "Straight_yatzy.c"
#include "ThreeOfAKind.c"
#include "TwoPairs_yatzy.c"
#include "YatzyScore.c"


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

  if (combination >= ONES && combination <= SIXES) {
    return PlainNumbers_yatzy(hand->die, combination);
  }
  if (combination == BONUS) {
    return 0;
  }
  if (combination == PAIR1) {
    return Pair_yatzy(hand->die);
  }
  if (combination == PAIR2) {
    return TwoPair_yatzy(hand->die);
  }
  if (combination == KIND3) {
    return ThreeOfAKind_yatzy(hand->die);
  }
  if (combination == KIND4) {
    return FourOfAKind_yatzy(hand->die);
  }
  if (combination == STRAIGHT1 && combination == STRAIGHT2) {
    return Straight_yatzy(hand->die);
  }
  if (combination == HOUSE) {
    return House_yatze(hand->die);
  }
  if (combination == CHANCE) {
    return Chance_yatzy(hand->die);
  }
  if (combination == YATZY) {
    return Yatzy_yatzy(hand->die);
  }

  return 0;
}
