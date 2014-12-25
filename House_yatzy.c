#include <stdbool.h>

int House_yatze(int array[]) {

  int i, j;
  int score = 0;
  bool has2 = false, has3 = false;

  for (i=1; i<7; i++) {
    int count = 0;

    for (j=0; j<5; j++) {
      if (array[j] == i) { count++; }
    }

    if (count == 2) { has2 = true; }
    if (count == 3) { has3 = true; }
  }

  if (has2 && has3) {
    for (i=0; i<5; i++) {
      score += array[i];
    }
  }

  return score;
}
