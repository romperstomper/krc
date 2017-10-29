#include <stdio.h>
#include <stdlib.h>
int game[81] = {0};

void printgame (int *game){
  printf("print game:\n");
  for (int i=0;i <81; i++){
    if (i % 9 == 0){
      printf("\n");
    }
    printf("%d ", game[i]);
  }
}
void readgamefile (int *game){
  char ch;
  FILE *fp;
  int i = 0;
  fp = fopen("input-sudoku.txt","r");
  printf("input file is:\n");
  while( ( ch = fgetc(fp) ) != EOF ){
    i++;
    printf("%c", ch);
  }
  printf("%d", i);
}
int main(int argc, char **argv){
  readgamefile(game);
}
