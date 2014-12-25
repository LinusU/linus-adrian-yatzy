
int PlainNumbers_yatzy(int array[], enum yatzy_combination combination) {

  int target, result, i;

  switch (combination) {
    case ONES: target = 1; break;
    case TWOS: target = 2; break;
    case THREES: target = 3; break;
    case FOURS: target = 4; break;
    case FIVES: target = 5; break;
    case SIXES: target = 6; break;
    default: target = 0;
  }

  result = 0;

  for (i=0; i<5; i++) {
    if (array[i] == target) {
      result += target;
    }
  }

  return result;
}
