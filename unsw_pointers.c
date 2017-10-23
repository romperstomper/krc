#include <stdio.h>
void inctask (int *a) {
  printf("value at a: %d\n", *a);
  (*a)++;
}
int main (int argc, char *argv[]){
  int x = 2;
  int *n;
  int *p = &x;
  n = &x;
  printf("value at x: %d\n", x);
  printf("value at *p: %p\n", p);
  inctask(p);
  printf("after inc: %d\n", x);
  printf("n is: %p\n", n);
}
