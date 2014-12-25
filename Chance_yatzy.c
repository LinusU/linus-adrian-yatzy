#include <stdlib.h>
#include <stdio.h>

int Chance_yatzy(int array[]) {
  int ChanceScore = 0;

  for (int i=0; i<5; i++) {
    ChanceScore += array[i];
  }

  return ChanceScore;
}
