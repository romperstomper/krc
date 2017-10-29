#include <stdio.h>
int game[81] = {0};

void printgame (int *game){
  printf("game state is:\n");
  for (int i=1;i <=81; i++){
    printf("%d ", game[i]);
    if (i % 9 == 0){
      printf("\n");
    }
  }
}
int main(int argc, char **argv){
  printgame(game);
}
