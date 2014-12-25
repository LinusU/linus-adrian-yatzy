#include <stdlib.h>
#include <stdio.h>

int Pair_yatzy(int array[]) {
  int PairPoints=0;

  for (int i=1; i<7; i++) {
    int apa=0;
    for (int j=0; j<5; j++) {
      if (array[j]==i) {
        apa=apa+1;
        if (apa>=2) {
          PairPoints=2*i;
        }
      }
    }
  }

return PairPoints;
}
