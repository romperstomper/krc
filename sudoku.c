#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define TRUE 1
#define FALSE 0
int game[81] = {0};

void printgame (int *game){
  printf("Game State:\n");
  for (int i=0;i <81; i++){
    if (i % 9 == 0){
      printf("\n");
    }
    printf("%d ", game[i]);
  }
  printf("\n");
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
int getsquare(int *game, int cell, int x){
  int sqrow = cell/27;
  int sqcol = (cell % 9)/3;
  for(int i=0;i<=80;i++){
    if((i/27 == sqrow)&&((i%9)/3==sqcol)){
      if (i==x){
      return FALSE; 
      }
    }
  }
  return TRUE;
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
  int sqRow = cell / ( 9 * 3 );
  int sqCol = (cell % 9) / 3 ;

  int checkCell = 0 ;
  for(int i= 0; i<=80;i++){
    if((i / ( 9 * 3 ) == sqRow) && (( (i % 9) / 3 )== sqCol)){

      if( game[i] == x){
    return FALSE;
   }
  }
 }

  return 1;
}
int getnextcell(int *game){
  for (int i=0;i<=80;i++){
    if (game[i]==0){
      return i; 
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
  if (!hasemptycell(game)) {
    return TRUE;
  }
  int cell = getnextcell(game);
  for (int i=1;i<=9;i++){
    if (islegal(game, cell, i)){
      game[cell] = i;
      if(solveable(game)){
        return TRUE;
      }
      game[cell] = 0;
    }
  }
  return FALSE;
}
int main(int argc, char **argv){
  readgamefile(game);
  printgame(game);
  solveable(game);
  printgame(game);
  return 0;
}
