#include <stdio.h>
#include <rpc/rpc.h>
#include <rpcsvc/rusers.h>


/* uses callrpc */
int main(int argc, char **argv)
{
  long nusers;
  enum clnt_stat stat;

  if( argc<=1 )
  {
    printf( "Usage:  %s hostname\n", argv[0] );
    exit(1);
  }

  stat=callrpc( argv[1], RUSERSPROG, RUSERSVERS_3, RUSERSPROC_NUM,
               (xdrproc_t) xdr_void, NULL,
               (xdrproc_t) xdr_u_long, (char*)&nusers);
  if( stat != RPC_SUCCESS )
  {
    clnt_perrno(stat);
    printf("\n");
    exit(1);
  }
  printf( "There are %d users on %s\n", nusers, argv[1] );
}
