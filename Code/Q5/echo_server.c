/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "echo.h"
#include <stdio.h>
#include <rpc/rpc.h>
/* 
 * routine notice the _1 the version number 
 * notice the client handle, not sued here but needs to be 
 * a parameter 
 */
 
word *
echo_1_svc(word *argp, struct svc_req *rqstp)
{
	static word  result;
	printf("Received: %s\n", argp);
	result = *argp;
	return &result;
}