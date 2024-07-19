#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

namespace sdds {
const int max_length = 51;
class Container {
  char m_Content[max_length];
  int m_Capacity;
  int m_Content_Volume;

public:
  Container(const char *, int, int = 0);
  int operator+=(int);
  int operator-=(int);
  operator bool() const;
  void clear(int capacity, const char *contents);
  std::ostream &print(std::ostream &);
  std::istream &read(std::istream &);

protected:
  void setEmpty();
  int capacity();
  int volume();
  void set(const char *content, int capacity, int content_volume);
};

std::ostream &operator<<(std::ostream &ostream, Container &container);
std::istream &operator>>(std::istream &istream, Container &container);

} // namespace sdds

#endif
