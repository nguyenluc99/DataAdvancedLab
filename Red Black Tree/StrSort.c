/* Strsort.c - sort lines of input lexicographically using JRB's. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "fields.h"

int main()
{
  JRB b;
  JRB bn;
  IS is;
    printf("start1");
  is = new_inputstruct(NULL);
  b = make_jrb();
    printf("start2");
  
  while (get_line(is) >= 0) {
    printf("start3");
    (void) jrb_insert_str(b, strdup(is->text1), new_jval_v(NULL));
  }
    printf("start4");

  jrb_traverse(bn, b) {
    printf("start5");
    printf("%s", jval_s(bn->key));
  }
    printf("start6");
  exit(0);
}