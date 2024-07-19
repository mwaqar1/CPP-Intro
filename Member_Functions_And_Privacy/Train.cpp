#define _CRT_SECURE_NO_WARNINGS
#include "Train.h"
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {

void Train::set(const char *unameofTrain, int unumOfPeople,
                double uspeedOfTrain) {

  if (unameofTrain != nullptr && (strcmp(unameofTrain, "")) &&
      (unumOfPeople >= 0 && unumOfPeople <= MAX_PEOPLE) &&
      (uspeedOfTrain >= 0 && uspeedOfTrain <= MAX_SPEED)) {

    strncpy(nameofTrain, unameofTrain, MAX_NAME_LEN);

    numofPeople = unumOfPeople;

    speedOfTrain = uspeedOfTrain;
  } else {

    strcpy(nameofTrain, "");

    numofPeople = -1;

    speedOfTrain = -1;
  }
}
int Train::getNumberOfPeople() const { return numofPeople; }

const char *Train::getName() const { return nameofTrain; }

double Train::getSpeed() const { return speedOfTrain; }

bool Train::isSafeEmpty() const {
  bool isSafe = false;

  if ((!strcmp(nameofTrain, "")) && (numofPeople == -1) &&
      (speedOfTrain == -1)) {

    isSafe = true;
  }

  return isSafe;
}

void Train::display() const {
  bool returnSafe;

  returnSafe = isSafeEmpty();

  if (returnSafe) {
    cout << "Safe Empty State!" << endl;

  } else {

    char tmpStr[20];
    sprintf(tmpStr, "%0.2lf", speedOfTrain);

    cout << "NAME OF THE TRAIN : " << nameofTrain << endl;
    cout << "NUMBER OF PEOPLE  : " << numofPeople << endl;
    cout << "SPEED             : " << tmpStr << " km/h" << endl;
  }
}

bool Train::loadPeople(int people) {
  bool status = false;

  if (!isSafeEmpty()) {
    int tmpNumPeople = numofPeople;
    tmpNumPeople = tmpNumPeople + people;
    status = true;

    if (tmpNumPeople < 0) {
      numofPeople = 0;
    } else if (tmpNumPeople > MAX_PEOPLE) {
      numofPeople = MAX_PEOPLE;
    } else {
      numofPeople = tmpNumPeople;
    }
  }

  return status;
}

bool Train::changeSpeed(double speedChange) {
  bool status = false;

  if (!isSafeEmpty()) {
    double tmpSpeed = speedOfTrain;
    tmpSpeed = tmpSpeed + speedChange;
    status = true;

    if (tmpSpeed < 0) {
      speedOfTrain = 0;
    } else if (tmpSpeed > MAX_SPEED) {
      speedOfTrain = MAX_SPEED;
    } else {
      speedOfTrain = tmpSpeed;
    }
  }

  return status;
}

int transfer(Train &first, Train &second) {
  int peopleMoved = -1;
  int peopleNotTransferred;

  if (!second.isSafeEmpty() && !first.isSafeEmpty()) {

    int numPeopleFirst = first.getNumberOfPeople();
    int numPeopleSecond = second.getNumberOfPeople();
    int numPeopleFirstAfterTransfer = numPeopleFirst + numPeopleSecond;

    if (numPeopleFirstAfterTransfer < 0) {
      numPeopleFirstAfterTransfer = 0;
      peopleMoved = numPeopleSecond;
    } else if (numPeopleFirstAfterTransfer > MAX_PEOPLE) {
      peopleNotTransferred = numPeopleFirstAfterTransfer - MAX_PEOPLE;

      first.loadPeople(numPeopleSecond - peopleNotTransferred);
      second.loadPeople(peopleNotTransferred - numPeopleSecond);

      peopleMoved = numPeopleSecond - peopleNotTransferred;
    } else {
      first.loadPeople(numPeopleSecond);
      second.loadPeople(-numPeopleSecond);
      peopleMoved = numPeopleSecond;
    }
  }

  return peopleMoved;
}
} // namespace sdds
