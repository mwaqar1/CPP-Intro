#include "Rectangle.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

namespace sdds {
Rectangle::Rectangle() {
  m_height = 0;
  m_width = 0;
}

Rectangle::Rectangle(const char *lbl, int width, int height) : LblShape(lbl) {
  int label_length = strlen(label());

  if ((height < 3) || (width < label_length + 2)) {
    m_height = 0;
    m_width = 0;
    setSafe();
  } else {
    m_height = height;
    m_width = width;
  }
}

void Rectangle::getSpecs(istream &istr) {
  int height, width;
  LblShape::getSpecs(istr);
  istr >> width;
  extractChar(istr, ',');
  istr >> height;
  extractChar(istr, '\n');

  m_height = height;
  m_width = width;
}

void Rectangle::draw(ostream &ostr) const {
  if ((m_height > 0) && (label()) && (m_width > 0)) {
    int i, j;
    ostr << "+";
    for (i = 0; i < m_width - 2; i++) {
      ostr << "-";
    }

    ostr << "+" << endl
         << "|" << left << setw(m_width - 2) << label() << "|" << endl;

    for (i = 0; i < m_height - 3; i++) {
      ostr << "|";
      for (j = 0; j < m_width - 2; j++) {
        ostr << " ";
      }
      ostr << "|" << endl;
    }

    ostr << "+";
    for (i = 0; i < m_width - 2; i++) {
      ostr << "-";
    }
    ostr << "+";
  }
}

} // namespace sdds
