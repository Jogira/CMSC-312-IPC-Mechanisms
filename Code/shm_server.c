#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h> /* for exit */


/* 
 * shm-server - not sure of the origin of code segment.
 * Old source, not sure of the origin
 *  possibly: David Marshalls course : http://www.cs.cf.ac.uk/Dave/C/CE.html
 * or Steve Holmes : http://www2.its.strath.ac.uk/courses/c/
 */



#define SHMSZ     27


int 
main()
{
    char c;
    int shmid;
    key_t key;
	int changed = 0;
    char *shm = '0';
	char *s = (char *) malloc(100);


    /*
     * We'll name our shared memory segment
     * "5678".
     */
    key = 50002007;

    /*
     * Create the segment.
     */
    if( (shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0 )
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
     * Now put some things into the memory for the
     * other process to read.
     */
    s = shm;

    // for(i= 0; i <= 7; i++ )
        // *s++ = share[i]; /* post fix */
    // *s = (char) NULL;
	

    /*
     * Finally, we wait until the other process 
     * changes the first character of our memory
     * to '*', indicating that it has read what 
     * we put there.
     */
    //while( *shm != '*' )
     //   sleep(1);
	
	*shm = '0';
	
		
    while( *shm != '3' && changed != 3)
    {
        if( *shm == '2' && changed != 2)
        {
			printf("\nStatus: 2    Memory");
			changed = 2;
        }
		if (*shm == '1'  && changed != 1)
		{
		    printf("\nStatus: 1    Shared");
			changed = 1;
        }
        //sleep(1);
    }
	changed = 3;
	printf("\nStatus: 3    Goodbye\n");
    shmctl(shmid,IPC_RMID,NULL); 	
    return 0;
}
