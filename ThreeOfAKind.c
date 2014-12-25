#include <stdlib.h>
#include <stdio.h>

int ThreeOfAKind_yatzy(int array[]) {
  int ThreeScore=0;
  for (int i=1; i<7; i++) {
    int apa=0;
    for (int j=0; j<5; j++) {
      if (array[j]==i) {
        apa++;
        if (apa>=3) {
          ThreeScore=i*3;
        }
      }
    }
  }
return ThreeScore;
}
