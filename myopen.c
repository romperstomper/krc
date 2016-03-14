#include <stdio.h>
#include <stdlib.h>

FILE *fp;

int main() {
fp = fopen("/home/gary/6.002/foo", "r");
if (fp == 0) {
	printf("Error could not open file");
	exit (1);
}
	fprintf(fp, "\n");
fclose(fp);
return(0);
}
