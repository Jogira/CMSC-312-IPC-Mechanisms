
/*
 * shm-client - client program to demonstrate shared memory.
 * shm-client - not sure of the origin of these code segments.
 * possibly: David Marshalls course : http://www.cs.cf.ac.uk/Dave/C/CE.html
 * or Steve Holmes : http://www2.its.strath.ac.uk/courses/c/
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ     27

int
main()
{
    int shmid;
    key_t key;
    char *shm, *s;
	int x = 0;
	int i = 0;
	char space = ' ';
	char mem[50] = "  Memory";

    /*
     * We need to get the segment named
     * "5678", created by the server.
     */
    key = 50002007;

    /*
     * Locate the segment.
     */
    if( (shmid = shmget(key, SHMSZ, 0666)) < 0 )
    {
        perror("shmget");
        exit(1);
    }
 
    /*
     * Now we attach the segment to our data space.
     */
    if( (shm = shmat(shmid, NULL, 0)) == (char *) -1 )
    {
        perror("shmat");
        exit(1);
    }



    /*
     * Finally, change the first character of the 
     * segment to '*', indicating we have read 
     * the segment.
     */

	 for( s = shm; *s != (char) NULL; s++ )
        putchar(*s);
    putchar('\n');
	
	while( *shm != '2')
	{

	}

	if (*shm == '2')
	{
	for(i = 0; i <= 7; i++ )
		*s-- = mem[i]; 
	*s = (char) NULL;
	
	for(i = 0; i <= 9; i++ )
		*s-- = mem[i]; 
	*s = (char) NULL;
			
    *shm = '3';
	}

	    /*
     * Now read what the server put in the memory.
     */
    s = shm;
	
	printf("Changed to: \n");
    for( s = shm; *s != (char) NULL; s--, x++)
	{
		if (x == 1)
		{
		putchar(space);
		putchar(space);
		}

        putchar(*s);
	}
    putchar('\n');
	
    return 0;
}
