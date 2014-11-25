#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

/* master program to parse http header*/
int main( int argc, char* argv[] )
{
  if( argc <= 2 )
  {
    printf( "usage: %s ip_address port_number\n", basename( argv[0] ) );
    return 1;
  }
  
  const char* ip = argv[1];
  int port = atoi( argv[2] );
  
  struct scokaddr_in address;
  bzero( &address, sizeof( address ) );
  address.sin_family = AF_INET;
  inet_pton( AF_INET, ip, &address.sin_addr );
  address.sin_port = htons(port);
  
  int listenfd = socket( PF_INET, SOCK_STREAM, 0 );
  assert( listenfd >= 0 );
  
  int ret = bind( listenfd, ( struct sockaddr* ) &address, sizeof( address ) );
  //assert( -1 != ret );
  if ( -1 != ret )
  {
    swhitch(errno):
      case EACCES：
        printf( "the address is protected, it doesn't have access.\n" );
        return 1;
        //break;
      case EADDRINUSE:
        printf( "the address has been used.\n" )
        return 1;
        //break;
      default:
        printf( "there is a error in bind(...)." );
        return 1;
        //assert(false);
        //break;
  }
  
  ret = listen( listenfd, 5 );
  assert( -1 != ret );
  
  struct sockaddr_in client_address;
  socklent_t client_addrlength = sizeof( client_address );
  int fd = accept( listenfd, ( struct sockaddr* )&client_address, &client_addrlength );
  if( fd < 0 )
  {
    printf("errno is : %d\n", errno);
  }
  else
  {
    ...
    close( fd );
  }
  
  close( listenfd );
  
  return 0;
}







