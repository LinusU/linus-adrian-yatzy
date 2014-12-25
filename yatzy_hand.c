
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
  return 1 + (rand() % 6);
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

  int i, count[6] = {};

  for (i=0; i<5; i++) {
    count[hand->die[i] - 1]++;
  }

  if (combination >= ONES && combination <= SIXES) {
    return count[combination - ONES] * (combination - ONES + 1);
  }

  switch (combination) {
    case PAIR1:      return yatzy_hand_score_pair1(hand->die, count);
    case PAIR2:      return yatzy_hand_score_pair2(hand->die, count);
    case KIND3:      return yatzy_hand_score_kind3(hand->die, count);
    case KIND4:      return yatzy_hand_score_kind4(hand->die, count);
    case STRAIGHT1:  return yatzy_hand_score_straight1(hand->die, count);
    case STRAIGHT2:  return yatzy_hand_score_straight2(hand->die, count);
    case HOUSE:      return yatzy_hand_score_house(hand->die, count);
    case CHANCE:     return yatzy_hand_score_chance(hand->die, count);
    case YATZY:      return yatzy_hand_score_yatzy(hand->die, count);
    default:         return 0;
  }

}
