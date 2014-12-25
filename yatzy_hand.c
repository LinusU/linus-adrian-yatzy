
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

void yatzy_hand_print(struct yatzy_hand *hand) {

  int i;
  char lines[5][44] = {
    "+-----+  +-----+  +-----+  +-----+  +-----+\n",
    "|     |  |     |  |     |  |     |  |     |\n",
    "|     |  |     |  |     |  |     |  |     |\n",
    "|     |  |     |  |     |  |     |  |     |\n",
    "+-----+  +-----+  +-----+  +-----+  +-----+\0"
  };

  for (i=0; i<5; i++) {

    int offset = 9 * i;

    if (hand->lock[i] == false) {
      lines[2][offset + 3] = '?';
      continue ;
    }

    switch (hand->die[i]) {
      case 0:
        lines[2][offset + 3] = 'o';
        break;
      case 1:
        lines[1][offset + 4] = 'o';
        lines[3][offset + 2] = 'o';
        break;
      case 2:
        lines[1][offset + 4] = 'o';
        lines[2][offset + 3] = 'o';
        lines[3][offset + 2] = 'o';
        break;
      case 3:
        lines[1][offset + 4] = 'o';
        lines[3][offset + 4] = 'o';
        lines[1][offset + 2] = 'o';
        lines[3][offset + 2] = 'o';
        break;
      case 4:
        lines[1][offset + 4] = 'o';
        lines[3][offset + 4] = 'o';
        lines[2][offset + 3] = 'o';
        lines[1][offset + 2] = 'o';
        lines[3][offset + 2] = 'o';
        break;
      case 5:
        lines[1][offset + 4] = 'o';
        lines[2][offset + 4] = 'o';
        lines[3][offset + 4] = 'o';
        lines[1][offset + 2] = 'o';
        lines[2][offset + 2] = 'o';
        lines[3][offset + 2] = 'o';
        break;
    }

  }

  printf("%s\n", (char *) lines);

}

struct yatzy_hand* yatzy_hand_run() {

  struct yatzy_hand *hand;

  hand = yatzy_hand_create();

  while (1) {
    int key;

    yatzy_hand_print(hand);

    key = getchar();

    if (key == '\n') {
      break;
    }

    if (key >= 48 && key < 53) {
      hand->lock[key - 48] ^= true;
    }

  }



  return hand;
}
