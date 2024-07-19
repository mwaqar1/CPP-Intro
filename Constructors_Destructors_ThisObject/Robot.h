#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H

namespace sdds {

class Robot {
  char *name;
  char *location;
  double weight;
  double width;
  double height;
  double member_speed;
  bool deployedStatus;

public:
  /*Constructors*/
  Robot();
  Robot(const char *name, const char *location, double weight, double width,
        double height, double speed, bool deployedStatus);

  /*Destructor*/
  ~Robot();

  /*Modifier functions*/

  // 1. sets the robot information(same order as the constructor)
  Robot &set(const char *name, const char *location, double weight,
             double width, double height, double speed, bool deployedStatus);

  // 2. setLocation : to set the robot location
  void setLocation(const char *location);

  // 3. setDeployed : to set the robot deployment status(true or false)
  void setDeployed(bool deployedStatus);

  /*Querie functions*/

  // 1.returns the robot name
  const char *getName() const;

  // 2. returns the robot location
  const char *getLocation() const;

  // 3. returns if a robot is deployed
  bool isDeployed() const;

  // 4. retrurns if the robot information is valid
  bool isValid() const;

  // 5. returns the speed of the robot
  double speed() const;

  /*Display function*/
  void display() const;
};

int conrtolRooomReport(const Robot robot[], int num_robots);

} // namespace sdds

#endif
