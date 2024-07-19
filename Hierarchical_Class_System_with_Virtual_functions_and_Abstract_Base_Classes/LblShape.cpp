#include "LblShape.h"
#include <cstring>
#include <iostream>

using namespace std;
namespace sdds {

LblShape::LblShape() { m_label = nullptr; }

LblShape::LblShape(const char *label) { set(label); }

void LblShape::set(const char *label) {
  if (label != nullptr) {
    m_label = new char[strlen(label) + 1];
    strcpy(m_label, label);
  }
}

LblShape::~LblShape() {
  if (m_label != nullptr) {
    delete[] m_label;
    m_label = nullptr;
  }
}

void LblShape::getSpecs(istream &istr) {
  char line[50];
  istr.get(line, 50, ',');
  extractChar(istr, ',');
  setSafe();
  set(line);
}

void LblShape::extractChar(istream &istr, char ch) const {
  char next;
  next = istr.peek();

  if (ch == next) {
    istr.ignore();
  } else {
    istr.ignore(1000, ch);
    next = istr.peek();
  }
}

} // namespace sdds
