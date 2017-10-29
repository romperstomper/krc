#include <stdio.h>
#include <stdlib.h>
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
int readgamefile (int *game){
  char ch;
  FILE *fp;
  int i = 0;
  fp = fopen("input-sudoku.txt","r");
  while( ( ch = fgetc(fp) ) != EOF )
    printf("%s ", ch);
    game[i] = ch;
    i++;
}
int main(int argc, char **argv){
  readgamefile(game);
  printgame(game);
}
