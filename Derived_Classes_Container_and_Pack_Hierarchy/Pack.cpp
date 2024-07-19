#include "Pack.h"
#include <iostream>

using namespace std;

namespace sdds {
Pack::Pack(const char *contents, int size, int container_capacity, int units)
    : Container(contents, size * container_capacity,
                units * container_capacity) {
  if ((units > 0 && units < size) || Container::operator bool()) {
    m_Size = size;
    m_Units = units;
    m_Container_Capacity = container_capacity;
  } else {
    Container::setEmpty();
    m_Size = 0;
    m_Units = 0;
    m_Container_Capacity = 0;
  }
}

int Pack::operator+=(int new_content) {
  int new_volume = new_content * m_Container_Capacity;
  int return_value = Container::operator+=(new_volume);
  return_value = return_value / m_Container_Capacity;
  m_Units += new_content;
  if (m_Units > m_Size) {
    m_Units = m_Size;
  }

  return return_value;
}

int Pack::operator-=(int new_content) {
  int new_volume = new_content * m_Container_Capacity;
  int return_value = Container::operator-=(new_volume);
  return_value = return_value / m_Container_Capacity;
  m_Units -= new_content;
  if (m_Units < 0) {
    m_Units = 0;
  }

  return return_value;
}

int Pack::unit() { return m_Container_Capacity; }

int Pack::noOfUnits() { return m_Units; }

int Pack::size() { return m_Size; }

void Pack::clear(int size, int units, const char *contents) {
  if (units > 0) {
    Container::clear(units * size, contents);
    m_Size = size;
    m_Container_Capacity = units;
  }
}
Pack::operator bool() const { return Container::operator bool(); }

ostream &Pack::print(ostream &ostr) {
  if (*this) {
    Container::print(ostr);
    ostr << ", " << m_Units << " in a pack of " << size();
  }
  return ostr;
}
#if 0
    istream& Pack::read(istream& istr)
    {
        int capacity;
        int added;
        int ch;

        if (*this && hasSpace())
        {
            cout << "Add to ";
            this->print(cout);
            cout << endl << "> ";
            int upper_limit = (size() - m_Units);
                
            do
            {
                istr >> capacity;
                if ((capacity > 0) && capacity <= upper_limit)
                {
                    added = *this += capacity;
                    cout << "Added " << added << endl;

                }
                else
                {
                    cout << "Value out of range [1<=val<=" << upper_limit << "]: ";
                }

            } while ((capacity < 1) || (capacity > upper_limit));
            
        }
        else
        {
            do
            {          
                cout << "Pack is full!, press <ENTER> to continue...";
                ch = getchar();
                ch = getchar();
            } while (ch != 10);
            
        }

        return istr;
    }
#endif
istream &Pack::read(istream &istr) {
  int capacity;
  int added;
  int ch;

  if (!(*this)) {
    do {
      cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
      ch = getchar();
      // ch = getchar();
    } while (ch != 10);
  } else if (hasSpace()) {
    cout << "Add to ";
    this->print(cout);
    cout << endl << "> ";
    int upper_limit = (size() - m_Units);

    do {
      istr >> capacity;
      if ((capacity > 0) && capacity <= upper_limit) {
        added = *this += capacity;
        cout << "Added " << added << endl;

      } else {
        cout << "Value out of range [1<=val<=" << upper_limit << "]: ";
      }

    } while ((capacity < 1) || (capacity > upper_limit));

  } else {
    do {
      cout << "Pack is full!, press <ENTER> to continue...";
      ch = getchar();
      ch = getchar();
    } while (ch != 10);
  }

  return istr;
}

ostream &operator<<(std::ostream &ostream, Pack &pack) {
  return pack.print(cout);
}

istream &operator>>(istream &istr, Pack &pack) {
  // char ch;
  // int max_capacity = pack.size();
  // int current_capacity = pack.noOfUnits();
  // if (max_capacity == current_capacity && max_capacity > 0)
  // {
  //     do
  //     {
  //         cout << "Pack is full!, press <ENTER> to continue...";
  //         ch = getchar();
  //         ch = getchar();
  //     } while (ch != 10);
  // }
  // else
  // {
  pack.read(istr);
  //     }

  return istr;
}

bool Pack::hasSpace() { return (m_Units < m_Size && m_Size > 0); }
} // namespace sdds
