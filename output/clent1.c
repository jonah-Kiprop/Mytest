#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include "b1.h"
int main(int argc, char **argv)
{
  int sockfd = 0,n = 0;
  //char recvBuff[1024];
  char * recvBuff;
  struct sockaddr_in serv_addr;
 
 // memset(recvBuff, '0' ,sizeof(recvBuff));
  /**
    -declare socket function to get socket descriptor
  -create socket
  */
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
      printf("\n Error : Could not create socket \n");
      return 1;
    }
 
  serv_addr.sin_family = AF_INET;//connect with different machine
  serv_addr.sin_port = htons(5000); //define the port number
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // declare IP address
  /**
    -connect function
    -send connect request to server and wait for server to accept
    -input parameters:
        -socket desription obtained above
        -socket address defined on top
        -length of the address
  */
  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
      printf("\n Error : Connect Failed \n");
      return 1;
    }
  /**
    -read function
    input parameters:
        -socket descriptors retrieved on top
        -content of data received
        -length of output string
  */
  while((n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
      recvBuff[n] = 0;
      /******************decode the received file here ********************************/
   /*   char opt = (char) 0;
    int retcode = 0;
    int linesize = B64_DEF_LINE_SIZE;
   // char *infilename = "C.bin";
    char *outfilename = "A.pdf";
    char *output;
    char * buff;
    FILE *fp;
    fp = fopen("C.bin","wb+");
    fputs(recvBuff,fp);
    fclose(fp);
      char *infilename = "C.bin";
   retcode = b64( 'd', infilename, outfilename, sizeof(recvBuff)-1);
   //snprintf(output,"The converted version is %s\n",out);
  // printf(output);
 // sprintf(buff, "The compressed file is %d",outfilename);
  // printf("The output is %s\n",outfile);
    //return( retcode );*/

     /* if(fputs(recvBuff, stdout) == EOF)
    {
      printf("\n Error : Fputs error");
    }
      //printf("\n");
*/
      FILE *fp;
      fp = fopen("C.bin","wb+");
      fputs(recvBuff,fp);
      fclose(fp);
      /*****now decode the binary file to any format **************/
      int retcode;
      // int linesize = B64_DEF_LINE_SIZE;
       char * infilename  = "C.bin";
      char * outfilename = "A.pdf";
      retcode = b64('d',infilename,outfilename,sizeof(recvBuff)-1);

      // return (retcode);
      //int retcode;
     // char *infilename = "C.bin", *outfilename = "A.pdf";
      //retcode = decode(char * infilename, char * outfilename);
    }
 
  if( n < 0)
    {
      printf("\n Read Error \n");
    }
 
    /*int retcode;
      int linesize = B64_DEF_LINE_SIZE;
      char * infilename  = "C.bin";
      char * outfilename = "A.pdf";
      retcode = b64('d',infilename,outfilename,1000000);
      return (retcode);*/

  return 0;
}



