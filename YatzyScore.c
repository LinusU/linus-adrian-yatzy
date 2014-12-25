#include <stdlib.h>
#include <stdio.h>

int Yatzy_yatzy(int array[]) {
  int YatzyScore=0;
  for (int i=1; i<7; i++) {
    int apa=0;
    for (int j=0; j<5; j++) {
      if (array[j]==i) {
        apa++;
        if (apa==5) {
          YatzyScore=50;
        }
      }
    }
  }
  return YatzyScore;
}
