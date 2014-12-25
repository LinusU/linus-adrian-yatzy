#include <stdlib.h>
#include <time.h>

int throws_yatzy(void) {
  int throws[5];

  srand(time(NULL));

  for (int i=0; i<5; i++) {
    throws[i]=(rand() % 6 +1);
  }

return throws;

};
