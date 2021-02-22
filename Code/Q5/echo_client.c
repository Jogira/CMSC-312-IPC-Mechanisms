/* written by client - calls client stub, xdr client, xdr xerver, server stub, server routine */ 
#include "echo.h"
#include <memory.h> /* for memset */

/* local routine client */
/* prototype can be whatever you want */
void echo_prog_1(char *host)
{
            CLIENT *clnt;
            word  *result_1;
            word echo_1_arg1;

#ifndef DEBUG
            clnt = clnt_create (host, ECHO_PROG, ECHO_VERS, "udp");
            if (clnt == NULL) {
                        clnt_pcreateerror (host);
                        exit (1);
            }
#endif  /* DEBUG */
			scanf("%[^\n]", echo_1_arg1.a);
           
            result_1 = echo_1(&echo_1_arg1, clnt);
            if (result_1 == (word *) NULL) {
                        clnt_perror (clnt, "call failed");
            }
            else
            {
                        printf("Echo: %s\n",result_1);
            }
#ifndef DEBUG
            clnt_destroy (clnt);
#endif  /* DEBUG */
}
/* here is main */
int main (int argc, char *argv[])
{
            char *host;
   /* check correct syntax */
            if (argc < 2) {
                        printf ("usage: %s server_host\n", argv[0]);
                        exit (1);
            }
            host = argv[1];
            echo_prog_1 (host);
exit (0);
}