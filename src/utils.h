#ifndef UTILS_H
#define UTILS_H

#include <cstdint>

#define sint uint8_t
#define ssint uint16_t

#define l(i, j, k, w) for(sint i=j; i<k; i+=w)
#define l1(i, j) for(sint i=0; i<j; ++i)
#define f19(i) for(sint i=1; i<10; ++i)
#define f9(i) for(sint i=0; i<9; ++i)
#define fg(i, j) for(sint i=0; i<3; ++i) for(sint j=0; j<3; ++j)

using namespace std;

#endif
