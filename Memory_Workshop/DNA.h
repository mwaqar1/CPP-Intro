#ifndef SSD_DNA_H
#define SSD_DNA_H

namespace sdds {

struct DNA {
  int dnaId;
  char *dnaSequence;
};

bool beginSearch(const char *filename);
bool read(const char *subDNA);
void sort();
void displayMatches();
void deallocate();
void endSearch();

} // namespace sdds
#endif
