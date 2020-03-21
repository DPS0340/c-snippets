#include <stdio.h>

int main(void) {
  int i = 5;
  int* pi = &i;

  printf("i: %d\naddress of i: %p\n", i, (void*) pi);

  return 0;
}