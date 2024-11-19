#include<ctype.h>

#ifndef CHAR_UTILS_H_
#define CHAR_UTILS_H_

/*
** will return ' ' when char is not valid (not a letter)
** will return lowercase value when we come across a valid string
** will also do the 'j' and 'i' subsitution
*/
char parse_char(char input);

#endif // CHAR_UTILS_H_
