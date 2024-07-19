#define _CRT_SECURE_NO_WARNINGS
#include "Robot.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

namespace sdds {
/*Constructors*/

Robot::Robot() {
  name = nullptr;
  location = nullptr;
  width = 0.0;
  weight = 0.0;
  height = 0.0;
  member_speed = 0.0;
  deployedStatus = false;
}

Robot::Robot(const char *name, const char *location, double weight,
             double width, double height, double member_speed,
             bool deployedStatus) {
  this->name = nullptr;
  this->location = nullptr;
  this->width = 0.0;
  this->weight = 0.0;
  this->height = 0.0;
  this->member_speed = 0.0;
  this->deployedStatus = false;

  set(name, location, weight, width, height, member_speed, deployedStatus);
}

/*Destructor*/

Robot::~Robot() {
  if (this->name != nullptr) {
    delete[] this->name;
  }
  if (this->location != nullptr) {
    delete[] this->location;
  }
}

/*Modifier functions*/

Robot &Robot::set(const char *name, const char *location, double weight,
                  double width, double height, double member_speed,
                  bool deployedStatus) {
  if (name != nullptr) {
    if (this->name != nullptr) {
      delete[] this->name;
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
  }

  if (location != nullptr) {
    if (this->location != nullptr) {
      delete[] this->location;
    }

    this->location = new char[strlen(location) + 1];
    strcpy(this->location, location);
  }
  if (weight > 0.0) {
    this->weight = weight;
  }

  if (width > 0.0) {
    this->width = width;
  }

  if (height > 0.0) {
    this->height = height;
  }
  if (member_speed > 0.0) {
    this->member_speed = member_speed;
  }

  this->deployedStatus = deployedStatus;

  return *this;
}

void Robot::setLocation(const char *location) {
  if (location != nullptr) {
    if (this->location != nullptr) {
      delete[] this->location;
    }

    this->location = new char[strlen(location) + 1];
    strcpy(this->location, location);
  }
}

void Robot::setDeployed(bool deployedStatus) {
  this->deployedStatus = deployedStatus;
}

/*Querie functions*/

// 1.returns the robot name
const char *Robot::getName() const { return name; }

// 2. returns the robot location
const char *Robot::getLocation() const { return location; }

// 3. returns if a robot is deployed
bool Robot::isDeployed() const { return deployedStatus; }

// 4. retrurns if the robot information is valid
bool Robot::isValid() const {
  bool valid = false;

  if (name != nullptr && location != nullptr && weight > 0.0 && width > 0.0 &&
      height > 0.0 && member_speed > 0.0) {
    valid = true;
  }

  return valid;
}

// 5. returns the speed of the robot
double Robot::speed() const { return member_speed; }

/*Display function*/
void Robot::display() const {
  // cout << name << "  " << location << "  " << weight << "  " << width << "  "
  // << height << " " << member_speed << " " << deployedStatus << endl;
  char tmpStr[4];

  if (deployedStatus) {
    strcpy(tmpStr, "YES");
  } else {
    strcpy(tmpStr, "NO");
  }

  cout << "| " << setw(11) << left << name;
  cout << "| " << setw(15) << left << location;
  cout << " | " << setw(6) << fixed << right << setprecision(1) << weight;
  cout << " | " << setw(6) << fixed << right << setprecision(1) << width;
  cout << " | " << setw(6) << fixed << right << setprecision(1) << height;
  cout << " | " << setw(6) << fixed << right << setprecision(1) << member_speed;
  cout << " | " << setw(8) << left << tmpStr;
  cout << " |" << endl;
}

/*Global function*/

/*
    This function receives an array of robots and prints a report of their
   information and a summary that prints the total number of deployed robots and
   the information of the fastest robot in the array.

    If during the printout of the array an invalid robot is detected, printing
   stops and the index of the invalid robot in the array is returned.

    If no Invalid robot is detected, the summary is printed and the value -1 is
   returned.

    Function execution sample for an array of robots with the fourth robot being
   invalid:
 */

int conrtolRooomReport(const Robot robot[], int num_robots) {
  int i;
  int returnIndex = -1;
  int deployed = 0;
  int maxIndex = 0;

  double currentMax;
  double max = robot[0].speed(); // set max to the first robot's speed

  cout << "                        ------ Robot Control Room -----" << endl;
  cout << "                    ---------------------------------------" << endl;
  cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed "
          "| Deployed |"
       << endl;
  cout << "|------------+-----------------+--------+--------+--------+--------+"
          "----------|"
       << endl;

  for (i = 0; i < num_robots; i++) {

    if (robot[i].isValid()) {
      currentMax =
          robot[i]
              .speed(); // store all the valid robot speeds into a local array

      // cout << speedArray[i];

      robot[i].display();

      if (robot[i].isDeployed()) {
        deployed++;
      }

      if (max < currentMax) // validate the speeds and find the fastest robot
      {
        max = currentMax;
        maxIndex = i;
      }
    } else {
      returnIndex = i;
      break;
    }
  }
  if (returnIndex == -1) {
    cout << "|" << setfill('=') << setw(77) << "=" << "|" << endl;
    cout << "| SUMMARY:" << setfill(' ') << setw(68) << " " << "|" << endl;
    cout << "| " << setw(3) << left << deployed << "robots are deployed."
         << setfill(' ') << setw(53) << " " << "|" << endl;
    cout << "| The fastest robot is:" << setfill(' ') << setw(55) << " " << "|"
         << endl;
    cout << "| Robot ID   | Location        | Weight |  Width | Height |  "
            "Speed | Deployed |"
         << endl;
    cout << "|------------+-----------------+--------+--------+--------+-------"
            "-+----------|"
         << endl;
    robot[maxIndex].display();
    cout << "|" << setfill('=') << setw(77) << "=" << "|" << endl;
  }

  return returnIndex;
}

} // namespace sdds
