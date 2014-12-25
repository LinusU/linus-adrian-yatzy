
int CheckNumberOfDices_yatzy(int array[]) {
  int NumberOfDice[6]={0};

  for (int i=1; i<7, i++) {
    for (int j=0; j<5; j++) {
      if (array[j]==i) {
        NumberOfDice[i-1]=NumberOfDice[i-1]+1;
      }
    }
  }
  return NumberOfDice;
}

int PlainNumbers_yatzy(int array[], enum yatzy_combination combination) {
  int Combo[] = CheckNumberOfDices_yatzy(array[]);

  if (combination == ONES) {
    return (Combo[0]);
  }
  if (combination == TWOS) {
    return (Combo[1]*2);
  }
  if (combination == THREES) {
    return (Combo[2]*3);
  }
  if (combination == FOURS) {
    return (Combo[3]*4);
  }
  if (combination == FIVES) {
    return (Combo[4]*5);
  }
  if (combination == SIXES) {
    return (Combo[5]*6);
  }
}
