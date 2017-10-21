#include <stdio.h>
void task (int x) {
  printf("task x: %d\n", x);
}
int main (int argc, char argv){
  int x = 2;
  int *p = &x;
/*  int *p */
  printf("value at x: %d\n", x);
  printf("value at *p: %p\n", p);
  task(*p);

}
