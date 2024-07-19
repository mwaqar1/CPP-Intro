#include "DNA.h"
#include "cStrTools.h"
#include <cstdio>
#include <iostream>

#define MAX_LENGTH 10001

#define MAX_INT 2147483647

using namespace std;

namespace sdds {

int totalSequences;
DNA *dnaPtr = nullptr;
DNA *unsortedDNAs = nullptr;
DNA *sortedDNAs = nullptr;
int matchCount = 0;

bool beginSearch(const char *filename) {
  bool fileOpened = false;
  char line[1100];
  char c;
  char idStr[10];
  int j;

  totalSequences = 0;

  // Read the entire file to find out how many lines are there.
  FILE *filePointer = fopen(filename, "r");

  if (filePointer != nullptr) {
    cout << "DNA search program" << endl;

    // The file was opened successfully
    fileOpened = true;
    while (fgets(line, 1100, filePointer) != nullptr) {
      totalSequences++;
    }

    // use that number to dynamically allocate an array of type DNA
    dnaPtr = new DNA[totalSequences];

    // re-read the file to get each line and fill up my array
    fseek(filePointer, 0, SEEK_SET);

    for (int i = 0; i < totalSequences; i++) {
      fgets(line, 1100, filePointer);
      j = 0;
      c = line[0];
      while (c != ',') {
        idStr[j] = c;
        j++;
        c = line[j];
      }

      idStr[j] = 0;

      dnaPtr[i].dnaId = atoi(idStr);

      // increase the index so that it comes to the start of dna sequence
      j++;

      int dnaLength = strLen(&line[j]);

      // allocate memory in the array for storing the dna sequence
      dnaPtr[i].dnaSequence = new char[dnaLength + 1];

      strCpy(dnaPtr[i].dnaSequence, &line[j]);

      dnaPtr[i].dnaSequence[dnaLength - 1] = 0;
    }

    fclose(filePointer);

    // close file.
  }

  return fileOpened;
}

bool read(const char *subDNA) {
  int i, j = 0;
  bool found = false;
  matchCount = 0;

  for (i = 0; i < totalSequences; i++) {
    if (strStr(dnaPtr[i].dnaSequence, subDNA) != nullptr) {
      found = true;
      matchCount++;
    }
  }

  if (found) {
    unsortedDNAs = new DNA[matchCount];

    for (i = 0; i < totalSequences; i++) {
      if (strStr(dnaPtr[i].dnaSequence, subDNA) != nullptr) {
        unsortedDNAs[j].dnaId = dnaPtr[i].dnaId;
        unsortedDNAs[j].dnaSequence = dnaPtr[i].dnaSequence;
        j++;
      }
    }
  }

  return found;
}

void sort() {
  int i, smallestIdIndex, j;
  int min;

  // This array will store the sorted results
  sortedDNAs = new DNA[matchCount];

  for (j = 0; j < matchCount; j++) {
    // setting min to maximum integer value
    min = MAX_INT;

    for (i = 0; i < matchCount; i++) {
      if (min > unsortedDNAs[i].dnaId) {
        min = unsortedDNAs[i].dnaId;
        smallestIdIndex = i;
      }
    }

    // copy the minimum found to sorted array
    sortedDNAs[j].dnaId = unsortedDNAs[smallestIdIndex].dnaId;
    sortedDNAs[j].dnaSequence = unsortedDNAs[smallestIdIndex].dnaSequence;

    // remove the minimum from unsorted array
    unsortedDNAs[smallestIdIndex].dnaId = MAX_INT;
  }
}

void displayMatches() {
  int i;

  cout << matchCount << " matches found:" << endl;

  for (i = 0; i < matchCount; i++) {
    cout << i + 1 << ") " << sortedDNAs[i].dnaId << ":" << endl;
    cout << sortedDNAs[i].dnaSequence << endl;
    cout << "=================================================================="
            "===="
         << endl;
  }
}

void deallocate() {
  if (unsortedDNAs != nullptr) {
    delete[] unsortedDNAs;
    delete[] sortedDNAs;

    unsortedDNAs = nullptr;
    sortedDNAs = nullptr;
  }
}

void endSearch() {
  int i;

  // delete the array of dna sequences
  for (i = 0; i < totalSequences; i++) {
    delete[] dnaPtr[i].dnaSequence;
  }

  cout << "DNA Search Program Closed." << endl;

  delete[] dnaPtr;

  dnaPtr = nullptr;
}
} // namespace sdds
