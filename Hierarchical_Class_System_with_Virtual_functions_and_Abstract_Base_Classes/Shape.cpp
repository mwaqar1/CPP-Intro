#include "Shape.h"

using namespace std;

namespace sdds {

Shape::~Shape() {}
ostream &operator<<(ostream &ostr, Shape &shape) {
  shape.draw(ostr);
  return ostr;
}

istream &operator>>(istream &istr, Shape &shape) {
  shape.getSpecs(istr);
  return istr;
}
} // namespace sdds
