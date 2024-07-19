#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {
#define MAX_NAME_LEN 20
#define MAX_PEOPLE 1000
#define MAX_SPEED 320

class Train {
  char nameofTrain[MAX_NAME_LEN];
  int numofPeople;
  double speedOfTrain;

public:
  void set(const char *, int, double);
  int getNumberOfPeople() const;
  const char *getName() const;
  double getSpeed() const;
  bool isSafeEmpty() const;
  void display() const;
  bool loadPeople(int people);
  bool changeSpeed(double speedChange);
};

int transfer(Train &first, Train &second);

} // namespace sdds

#endif
