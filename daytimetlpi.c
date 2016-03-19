#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char *argv[]){
  char *reqLenStr;
  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int sockfd, n, cfd;
  int MAXLINE = 100;
  char recvline[MAXLINE + 1];
  struct sockaddr_in servaddr; /*IPv4 socket address*/
  if (argc != 3)
    printf("usage: a.out <IPADDR> <PORT>");

  /* Call getaddrinfo() to obtain a list of addresses that we can try
   connecting to*/
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;
  hints.ai_family = AF_UNSPEC; /*allows ip 4 or ip 6*/
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_NUMERICSERV;

  if (getaddrinfo(argv[1], argv[2], &hints, &result) !=0)
    printf("getaddrinfo error");

  for (rp = result; rp !=NULL; rp->ai_next){
    cfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (cfd == -1)
      continue; /*on error try next address*/
    if (connect(cfd, rp->ai_addr, rp->ai_addrlen) != -1)
      break; /*success!*/
    close(cfd); /*something went wrong, close and try next address*/
  }

  while ( (n = read(cfd, recvline, MAXLINE)) > 0) {
    recvline[n] = 0;  /*null terminate */
    if (fputs(recvline, stdout) == EOF)
      printf("fputs error");
  }
  if (n<0)
    printf("read error");
  exit(0);
}

