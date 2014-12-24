
struct yatzy_player {

  int ones;
  int twos;
  int threes;
  int fours;
  int fives;
  int sixes;

  int bonus;

  int pair1;
  int pair2;
  int kind3;
  int kind4;
  int straight1;
  int straight2;
  int house;
  int chance;
  int yatzy;

};

struct yatzy_game {
  int currentPlayer;
  struct yatzy_player players[];
};
