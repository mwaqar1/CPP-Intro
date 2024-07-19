#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds {

class LblShape : public Shape {
  char *m_label;
  void set(const char *label);

protected:
  void extractChar(std::istream &istr, char ch) const;

  const char *label() const { return m_label; }

  void setSafe() {
    if (m_label != nullptr) {
      delete[] m_label;
      m_label = nullptr;
    }
  }

public:
  LblShape();
  LblShape(const char *label);
  void getSpecs(std::istream &);
  void draw(std::ostream &);
  ~LblShape();
  void operator&();
};

} // namespace sdds

#endif // SDDS_LBLSHAPE_H
