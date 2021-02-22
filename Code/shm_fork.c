#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ   27

int main(void) {

    int shmid;
    key_t key;
    char *shm, *s;
	char share[50] = "Shared";
	char mem[50] = " Memory";
	pid_t processAID;
	pid_t processBID;
	pid_t processCID;

    /*
     * We need to get the segment named
     * "5678", created by the server.
     */
	key = 50002007;

	
	  /*
     * Locate the segment.
     */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
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

	processAID = fork();
	
	if (processAID == 0)
	{
		usleep(300000);
		printf(" Goodbye.");
	}
	
	else 
	{
		processBID = fork();
		if (processBID == 0)
		{
			usleep(1000);
			shm = share;
			while (*shm != '\0')
			{
				printf("%c", *shm++);
			}
		}
		else 
		{
			processCID = fork();
			if (processCID == 0)
			{
				usleep(20000);
				shm = mem;
			while (*shm != '\0')
			 {
				printf("%c", *shm++);
			 }
			}
		}
	}
	
	
 
}
