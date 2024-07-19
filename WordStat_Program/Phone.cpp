#include "Phone.h"
#include "cStrTools.h"
#include <cstdio>
#include <iomanip>
#include <iostream>

/*
When running, after showing the title, the program should prompt for a partial
name entry. After receiving the partial name the program should search through
the names in the file and if a name is found containing the partial entry, the
matching phone recored is displayed. Nothing is displayed if no match is found.
If the user enters '!' the program exits.
If the data file could not be opened the program exits displaying an error
message A thank you message is displayed at the end of the program.

*/

using namespace std;

namespace sdds {

void phoneDir(const char *programTitle, const char *fileName) {

  cout << programTitle << " phone direcotry search" << endl;
  cout << "-------------------------------------------------------" << endl;

  FILE *filePointer = nullptr;
  phoneVariables pvArray[40] = {
      {0}}; // declare array of phoneVariables and intitalize to 0
  int index = -1;
  bool terminate = false;
  char userName[MAXSTRING] = {0};
  int j = 0;

  filePointer = fopen(fileName, "r");

  if (filePointer == nullptr) {
    cout << fileName << " file not found!" << endl;
    cout << "Thank you for using " << programTitle << " directory." << endl;

  } else // file read sucessfully
  {
    index = 0; // set index to 0 before entering while loop

    while (!feof(filePointer)) // loop runs if the end of file is not reached
    {
      fscanf(filePointer, "%[^\t]\t%s\t%s\t%s\n", pvArray[index].name,
             pvArray[index].area, pvArray[index].prefix, pvArray[index].number);

      // after scanning increment index by 1
      index++;
    }

    // set value of index to struct memeber totalPhoneRecords
    pvArray->totalPhoneRecords = index;

    do // after exiting while loop and reading and storing whole file prompt for
       // user input
    {
      cout << "Enter a partial name to search (no spaces) or enter '!' to exit"
           << endl;
      cout << "> ";
      cin >> userName;

      if (userName[0] == '!') {
        terminate = true; // set condition to exit do while loop
        cout << "Thank you for using Star Wars directory." << endl;

      } else // check if userName is valid
      {
        for (j = 0; j <= pvArray->totalPhoneRecords;
             j++) // loop through entire pvArray one by one to see if user input
                  // is found
        {
          if (strStr_ci(pvArray[j].name, userName) != nullptr) {
            cout << pvArray[j].name << ": (" << pvArray[j].area << ") "
                 << pvArray[j].prefix << "-" << pvArray[j].number << endl;
          }
        }
      }

    } while (!terminate); // end of do while statement

  } // end of outer else statement

  fclose(filePointer);
} // end of phoneDir function

} // namespace sdds
