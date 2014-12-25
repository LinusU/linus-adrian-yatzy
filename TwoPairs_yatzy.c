#include <stdlib.h>
#include <stdio.h>

int TwoPair_yatzy(int array[]) {
  int TwoPairScore2 = 0;
  int TwoPairScore1 = 0;
  int apo = 0;

  for (int i=1; i<7; i++) {
    int apa=0;
    for (int j=0; j<5; j++) {
      if (array[j]==i) {
        apa=apa+1;
        if (apa==2) {
          TwoPairScore1 = 2*i;
          apo = i;
        }
      }
    }
  }

  if (TwoPairScore1 == 0) {
    return 0;
  }

  for (int k=1; k<apo; k++) {
    int apa2=0;
    for (int l=0; l<5; l++) {
      if (array[l]==k) {
        apa2=apa2+1;
        if (apa2==2) {
          TwoPairScore2 = 2*k;
        }
      }
    }
  }
  if (TwoPairScore2 == 0) {
    return 0;
  }


  return (TwoPairScore1 + TwoPairScore2);
}
