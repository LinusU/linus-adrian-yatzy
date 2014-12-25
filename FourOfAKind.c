#include <stdlib.h>
#include <stdio.h>

int FourOfAKind_yatzy(int array[]) {
  int FourScore=0;
  for (int i=1; i<7; i++) {
    int apa=0;
    for (int j=0; j<5; j++) {
      if (array[j]==i) {
        apa++;
        if (apa>=4) {
          FourScore=i*4;
        }
      }
    }
  }
return FourScore;
}
