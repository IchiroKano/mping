#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define BUFSIZE 64

char *throwPing(char *);
char *getTime( char *, char * );

int main(int argc, char *argv[])
{
  int i=0;
  int j=0;
  int intMax=0;
  int intCount[16];
  char cmd[BUFSIZE];
  char strTemp[BUFSIZE];
  char strResult[BUFSIZE];
  char *strReturn;
  time_t t;

  if( argc < 2 ) {
    printf( " mping v1.1\n Syntax: mping <IPaddress1> <IPaddress2> ..\n" );
    exit(-1);
  }

  intMax = argc - 1;
  for(i=0; i<16; i++) intCount[i] = 0;
  printf("-----------------------------------------------\n");
  printf("A mping targets %d IP address:\n", intMax);
  printf("-----------------------------------------------\n");


  do {
    if( j == 0 ) {
      time(&t);
      printf( " %s", ctime(&t) );
      for( i = 0; i < intMax; i++ ) {
        printf( "%16s", argv[i+1] );
      }
      printf( "\n" );
      for( i = 0; i < intMax; i++ ) {
        printf( "%16d", intCount[i+1] );
      }
      printf(" <- NG out of %d\n", intCount[0] );
    }
    if( j++ == 9 ) j = 0;

    intCount[0]++;
    for ( i = 0; i < intMax; i++ ) {
      snprintf(cmd, BUFSIZE, "ping -c 1 %s", argv[i+1]);
      strReturn = throwPing( cmd );
      if( strReturn != "NULL" ){
        printf( "%16s", strReturn );
      } else {
        printf( "      *** NG ***" );
        intCount[i+1]++;
      }
    }
    printf("\n");
    sleep(1);
  } while(1);

  return 0;
}

char *throwPing( char *strCmd )
{
  FILE *fp;
  char buf[BUFSIZE];
  char *token;

    if((fp = popen(strCmd, "r")) == NULL) {
      printf("Can not exec ping. ");
      return "NULL";
    }
    fgets(buf, BUFSIZE, fp);
    fgets(buf, BUFSIZE, fp);
    pclose(fp);

    if( strstr(buf, "ttl=") != NULL) {
      token = getTime( buf, "=" );
      return token;
    } else {
      return "NULL";
    }

  return "NULL";
}

char *getTime( char strTest[BUFSIZE], char strTrim[BUFSIZE] )
{
  char *token;
  unsigned int len;

  token = strtok( strTest, strTrim );

  while( token != NULL ) {
    if(strstr(token,"ms")){
        len = strlen( token );
        token[len-1] = '\0';
        return token;
    }
    token = strtok( NULL, strTrim );
  }
  return "NULL";
}

