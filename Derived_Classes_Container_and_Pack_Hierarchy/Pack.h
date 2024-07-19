#ifndef PACK_H
#define PACK_H

#include "Container.h"

namespace sdds {
class Pack : public Container {
  int m_Size;               // The max number of containers this pack can hold.
  int m_Units;              // The current number of containers in this pack.
  int m_Container_Capacity; // The max number of containers this pack can hold.
  bool hasSpace();

public:
  Pack(const char *, int, int = 330, int = 0);
  int operator+=(int);
  int operator-=(int);
  int unit();
  int noOfUnits();
  int size();
  void clear(int size, int units, const char *contents);
  std::ostream &print(std::ostream &);
  operator bool() const;
  std::istream &read(std::istream &);
};
std::ostream &operator<<(std::ostream &ostream, Pack &pack);
std::istream &operator>>(std::istream &istream, Pack &pack);

} // namespace sdds

#endif
