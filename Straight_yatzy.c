#include <stdlib.h>
#include <stdio.h>

int Straight_yatzy(int array[]) {

  int StraightScore = 0;

  for (int k=0; k<5; k++) {
    StraightScore += array[k];
  }
  if (StraightScore == 15 || StraightScore == 20) {
    for (int i = 0; i<5; i++) {
      for (int j = 0; j<5; j++) {
        if (array[i] == array[j]) {
          StraightScore = 0;
        }
      }
    }
  }

  return StraightScore;
}
