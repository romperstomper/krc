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
    if (game[i] == x){
      return 0; 
    } 
  }
  int col = (cell % 9);
  for (int i=col;i<=80;i+=9){
    if (game[i] == x){
      return 0; 
    } 
  }
  game[cell] = x;
  return 1;
}
int getnextcell(int *game){
  for (int i=0;i<=80;i++){
    if (game[i]==0){
      return i; 
    }
  }
}
void printnextcell(int *game){
  for (int i=0;i<=80;i++){
    if (game[i]==0){
    printf("nextemptycell %d\n", i); 
    }
  }
}
int hasemptycell(int *game){
  for (int i=0;i<=80;i++){
    if (game[i]==0){
      return 1; 
    }
  }
  return 0;
}

int solveable(int *game){
  if (hasemptycell(game)){
    int tryvalue = 1;
    int cell = getnextcell(game);
    while (tryvalue <=9){
      if (!islegal(game, cell, tryvalue)){
        tryvalue++;
      } else {
      solveable(game);
      }
    }
  } else {
  return 1;
  }
}
int main(int argc, char **argv){
  readgamefile(game);
  printgame(game);
  solveable(game);
  printnextcell(game);
  printgame(game);
  return 0;
}
