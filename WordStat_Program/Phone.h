#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H

#define MAXSTRING 51

namespace sdds {

struct phoneVariables {

  char name[MAXSTRING];
  char area[MAXSTRING];
  char prefix[MAXSTRING];
  char number[MAXSTRING];
  int totalPhoneRecords;
};

void phoneDir(const char *programTitle, const char *fileName);

} // namespace sdds

#endif
