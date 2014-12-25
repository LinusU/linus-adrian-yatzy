
int yatzy_hand_score_pair1(int dice[], int count[]) {

  for (int i=6; i>0; i--) {
    if (count[i - 1] >= 2) {
      return (i * 2);
    }
  }

  return 0;
}

int yatzy_hand_score_pair2(int dice[], int count[]) {

  int score = 0;
  int pairs = 0;

  for (int i=6; i>0; i--) {
    if (count[i - 1] >= 2) {
      score += (i * 2);
      pairs++;
    }
  }

  return (pairs == 2 ? score : 0);
}

int yatzy_hand_score_kind3(int dice[], int count[]) {

  for (int i=6; i>0; i--) {
    if (count[i - 1] >= 3) {
      return (i * 3);
    }
  }

  return 0;
}

int yatzy_hand_score_kind4(int dice[], int count[]) {

  for (int i=6; i>0; i--) {
    if (count[i - 1] >= 4) {
      return (i * 4);
    }
  }

  return 0;
}

int yatzy_hand_score_straight1(int dice[], int count[]) {
  int target[] = {1, 1, 1, 1, 1, 0};

  if (memcmp(count, target, sizeof(target)) == 0) {
    return 15;
  }

  return 0;
}

int yatzy_hand_score_straight2(int dice[], int count[]) {
  int target[] = {0, 1, 1, 1, 1, 1};

  if (memcmp(count, target, sizeof(target)) == 0) {
    return 20;
  }

  return 0;
}

int yatzy_hand_score_house(int dice[], int count[]) {

  bool has2 = false, has3 = false;

  for (int i=0; i<6; i++) {
    if (count[i] == 2) { has2 = true; }
    if (count[i] == 3) { has3 = true; }
  }

  if (!has2 || !has3) {
    return 0;
  }

  return (dice[0] + dice[1] + dice[2] + dice[3] + dice[4]);
}

int yatzy_hand_score_chance(int dice[], int count[]) {
  return (dice[0] + dice[1] + dice[2] + dice[3] + dice[4]);
}

int yatzy_hand_score_yatzy(int dice[], int count[]) {

  for (int i=6; i>0; i--) {
    if (count[i - 1] >= 5) {
      return 50;
    }
  }

  return 0;
}
