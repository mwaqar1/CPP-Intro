#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds {
class Rectangle : public LblShape {
  int m_height = 0;
  int m_width = 0;

public:
  void draw();
  void getSpecs(std::istream &);
  void draw(std::ostream &) const;
  Rectangle();
  Rectangle(const char *, int, int);
  ~Rectangle(){};
};
} // namespace sdds

#endif
