#include "char_utils.h"


char parse_char(char input) {
  if (!isalnum(input))
      return ' ';

  if (isupper(input))
    input = tolower(input);

  // does our subsitution
  if (input == 'j')
      input = 'i';

  return input;
}
