#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int game[81] = {0};

void printgame (int *game){
  printf("print game:\n");
  for (int i=0;i <81; i++){
    if (i % 9 == 0){
      printf("\n");
    }
    printf("%d ", game[i]);
  }
  printf("\n");
}
void readgamefile (int *game){
  char ch;
  FILE *fp;
  int i = 0;
  fp = fopen("input-sudoku.txt","r");
  while( ( ch = fgetc(fp) ) != EOF ){
    int num = ch - '0';
    if (ch == 44){  //comma
      continue;
    }
    if (ch == 10){ //linefeed
      continue;
    }
    game[i] = num;
    i++;
  }
}
int islegal(int *game, int cell, int x){
  int rownum = (cell / 9);
  int rowstart = rownum * 9;
  int rowend = rowstart + 8;
  for (int i=rowstart;i<=rowend;i++){
    printf("game[i]: %d\n", game[i]);
    if (game[i] == x){
      printf("bad\n");
      return 0; 
    } 
  game[cell] = x;
  printf("good\n");
  return 1;
  }
  printf("rownum: %d\n", rownum);
  printf("rowstart: %d\n", rowstart);
  printf("rowend: %d\n", rowend);
  printf("\n");
}
int main(int argc, char **argv){
  readgamefile(game);
  printgame(game);
  int res = islegal(game, 1, 7);
  printf("result: %d\n", res);
  printgame(game);
  //islegal(game, 12, 9);
}
