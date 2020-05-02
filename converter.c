/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

#include <stdlib.h>
#include <cstring>


void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
    for (unsigned i = 0; i < nlines; i++) {
    nums[i] = atoi(lines[i]);
  }
}


/*
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    int l = std::strlen(lines[i]);
    nums[i] = 0;
    for (int j = 0; j < l ; j ++)
      nums[i] = nums[i] * 10 + lines[i][j] - '0';
  }
}
*/