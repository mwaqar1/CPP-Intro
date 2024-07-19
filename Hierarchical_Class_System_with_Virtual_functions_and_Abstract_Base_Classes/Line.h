
#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"
#include <iostream>

namespace sdds {

class Line : public LblShape {

  int m_length = 0;

public:
  Line();
  Line(const char *pString, int length);
  void draw(std::ostream &) const;
  void getSpecs(std::istream &);
  ~Line(){};
};

} // namespace sdds

#endif // SDDS_LINE_H
