#include <stdlib.h>
#include "c-sum.h"

void sum_abs_(int *in, int *num, int *res) {
   int i;
   *res = 0;
   for (i=0; i < *num; ++i) {
       *res += abs(in[i]);
   }
   return;
}
 
