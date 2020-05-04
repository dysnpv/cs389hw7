/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

#include <stdlib.h>
#include <cstring>

const int ascii_zero = 48;

// The atoi version
/*
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
    for (unsigned i = 0; i < nlines; i++) {
    nums[i] = atoi(lines[i]);
  }
}
*/

// The naive version
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

// The optimized version
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    int l = std::strlen(lines[i]);
    if(l == 3)
      nums[i] = lines[i][0] * 100 + lines[i][1] * 10 + lines[i][2] - ascii_zero * 111;
    else if (l == 4)
      nums[i] = lines[i][0] * 1000 + lines[i][1]  * 100 + lines[i][2] * 10 + lines[i][3] - ascii_zero * 1111;
    else if (l == 5)
      nums[i] = lines[i][0] * 10000 + lines[i][1] * 1000 + lines[i][2] * 100 + lines[i][3] * 10 + lines[i][4] - ascii_zero * 11111;
    else 
      nums[i] = lines[i][0] * 100000 + lines[i][1]  * 10000 + lines[i][2] * 1000 + lines[i][3] * 100 + lines[i][4] * 10 + lines[i][5] - ascii_zero * 111111;
  }
}