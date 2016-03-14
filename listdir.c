#include <dirent.h>
#include <stdio.h>
DIR *od;
struct dirent *dirp;
int main() {
  od = opendir(".");
  for (;;){
    dirp = readdir(od);
    if (dirp == NULL)
      return;

  printf("struct elem is %s\n", dirp->d_name);
}
}
