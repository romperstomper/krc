#include<stdio.h>

int tokenise(char str[], int start, char result[]){
  while (str[start] != '\0'){
      result[start] = str[start];
      printf("result is %s", result);
      start++;}
  if (str[start] == '\0'){
    return -1;
  }
  return start+1;
}  
int main(){
  const int MAX_STRING = 256;
  char buffer[MAX_STRING];
  char result[MAX_STRING];
  /* read in */
  printf("please enter some text\n");
  fgets(buffer, MAX_STRING, stdin);
  printf("read:\n%s\n", buffer);
  while (tokenise(buffer, 0, result) != -1){
    tokenise(buffer, 0, result);
  }

  printf("result is\n%s\n", result);
  return 0;
}

