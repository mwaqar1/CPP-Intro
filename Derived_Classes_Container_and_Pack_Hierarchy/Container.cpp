#include "Container.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
void Container::setEmpty() {
  strcpy(m_Content, "");
  m_Capacity = 0;
  m_Content_Volume = 0;
}

Container::Container(const char *content, int capacity, int content_volume) {
  set(content, capacity, content_volume);
}

void Container::set(const char *content, int capacity, int content_volume) {
  if (strlen(content) > 0 && strlen(content) < (max_length) &&
      content_volume <= capacity) {
    strcpy(m_Content, content);
    m_Capacity = capacity;
    m_Content_Volume = content_volume;
  } else {
    setEmpty();
  }
}

int Container::capacity() { return m_Capacity; }

int Container::volume() { return m_Content_Volume; }

int Container::operator+=(int new_content) {
  int available_capacity = m_Capacity - m_Content_Volume;
  int return_value;

  if (new_content >= available_capacity) {
    m_Content_Volume = m_Capacity;
    return_value = available_capacity;
  } else {
    m_Content_Volume += new_content;
    return_value = new_content;
  }

  return return_value;
}

int Container::operator-=(int new_content) {
  int new_capacity = m_Content_Volume - new_content;
  int return_value;

  if (new_capacity >= 0) {
    m_Content_Volume = new_capacity;
    return_value = new_content;
  } else {
    return_value = m_Content_Volume;
    m_Content_Volume = 0;
  }

  return return_value;
}

Container::operator bool() const {
  return (strlen(m_Content) > 0) && (m_Content_Volume <= m_Capacity);
}

void Container::clear(int capacity, const char *contents) {
  if (capacity > 0 && strlen(contents) > 0 && strlen(contents) < max_length) {
    strcpy(m_Content, contents);
    m_Capacity = capacity;
  }
}

ostream &Container::print(ostream &ostr) {
  if (*this) {
    ostr << m_Content << ": (" << m_Content_Volume << "cc/" << m_Capacity
         << ")";
  } else {
    ostr << "****: (**cc/***)";
  }

  return ostr;
}

istream &Container::read(istream &istr) {
  int capacity;
  int added;
  int ch;

  if (*this) {
    cout << "Add to ";
    this->print(cout);
    cout << endl << "> ";
    do {
      istr >> capacity;
      if ((capacity > 0) && (capacity <= 220000)) {
        added = *this += capacity;
        cout << "Added " << added << " CCs" << endl;

      } else {
        cout << "Invalid Integer, retry: ";
      }

    } while ((capacity < 1) || (capacity > 220000));

  } else {
    do {
      cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
      ch = getchar();
      ch = getchar();
    } while (ch != 10);
  }

  return istr;
}

ostream &operator<<(std::ostream &ostream, Container &container) {
  return container.print(cout);
}

istream &operator>>(istream &istream, Container &container) {
  return container.read(cin);
}

} // namespace sdds
