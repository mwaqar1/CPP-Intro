#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds {

class Shape {
public:
  virtual void draw(std::ostream &) const = 0;
  virtual void getSpecs(std::istream &) = 0;
  virtual ~Shape();
};

std::ostream &operator<<(std::ostream &, Shape &shape);
std::istream &operator>>(std::istream &, Shape &shape);

} // namespace sdds

#endif // SDDS_SHAPE_H
