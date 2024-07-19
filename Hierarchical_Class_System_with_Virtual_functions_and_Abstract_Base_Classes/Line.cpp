#include "Line.h"
#include <cstring>

using namespace std;

namespace sdds {

Line::Line() { m_length = 0; }

Line::Line(const char *pString, int length) : LblShape(pString) {
  m_length = length;
}

void Line::getSpecs(istream &istr) {
  int length;
  LblShape::getSpecs(istr);
  istr >> length;
  extractChar(istr, '\n');
  m_length = length;
}

void Line::draw(ostream &ostr) const {
  if (label() != nullptr) {
    if (m_length > 0) {
      ostr << label() << endl;
      for (int i = 0; i < m_length; i++) {
        ostr << "=";
      }
    }
  }
}

}; // namespace sdds
