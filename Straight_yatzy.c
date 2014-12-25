#include <stdlib.h>
#include <stdio.h>

int Straight_yatzy(int array[], int targetScore) {

  int StraightScore = 0;

  for (int k=0; k<5; k++) {
    StraightScore += array[k];
  }

  if (StraightScore != targetScore) {
    return 0;
  }

  for (int i = 0; i<5; i++) {
    for (int j = 0; j<5; j++) {
      if (i != j && array[i] == array[j]) {
        return 0;
      }
    }
  }

  return StraightScore;
}
