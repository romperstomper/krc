#include<stdio.h>

int main(){
  int x, *iptr;
  x = 10;
  iptr = &x;
  printf("iptr points to %d\n", *iptr);
  printf("iptr address %p\n", (void*)iptr);
}
