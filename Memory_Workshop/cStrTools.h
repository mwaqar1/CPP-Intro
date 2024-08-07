#ifndef SDDS_CSTRTOOLS_H
#define SDDS_CSTRTOOLS_H

namespace sdds {

char toLower(char ch);
int strCmp(const char *s1, const char *s2);
int strnCmp(const char *s1, const char *s2, int len);
void strCpy(char *des, const char *src);
int strLen(const char *str);
const char *strStr(const char *str, const char *find);
const char *strStr_ci(const char *str, const char *find);
int isAlpha(char ch);
int isSpace(char ch);
void trim(char word[]);
void toLowerCaseAndCopy(char des[], const char source[]);
void read(char *cString, unsigned int maxSize, char delimiter = '\n');

} // namespace sdds

#endif
