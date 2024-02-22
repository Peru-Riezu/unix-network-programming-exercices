/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: get_resource_limit.c                                           */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2024/02/21 11:44:24                                            */
/*   Updated:  2024/02/22 05:42:34                                            */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

#ifndef RLIMIT_AS
# define RLIMIT_AS -1
#endif
#ifndef RLIMIT_CORE
# define RLIMIT_CORE -1
#endif
#ifndef RLIMIT_CPU
# define RLIMIT_CPU -1
#endif
#ifndef RLIMIT_DATA
# define RLIMIT_DATA -1
#endif
#ifndef RLIMIT_FSIZE
# define RLIMIT_FSIZE -1
#endif
#ifndef RLIMIT_MEMLOCK
# define RLIMIT_MEMLOCK -1
#endif
#ifndef RLIMIT_MSGQUEUE
# define RLIMIT_MSGQUEUE -1
#endif
#ifndef RLIMIT_NICE
# define RLIMIT_NICE -1
#endif
#ifndef RLIMIT_NOFILE
# define RLIMIT_NOFILE -1
#endif
#ifndef RLIMIT_NPROC
# define RLIMIT_NPROC -1
#endif
#ifndef RLIMIT_RSS
# define RLIMIT_RSS -1
#endif
#ifndef RLIMIT_RTPRIO
# define RLIMIT_RTPRIO -1
#endif
#ifndef RLIMIT_RTTIME
# define RLIMIT_RTTIME -1
#endif
#ifndef RLIMIT_SIGPENDING
# define RLIMIT_SIGPENDING -1
#endif
#ifndef RLIMIT_STACK
# define RLIMIT_STACK -1
#endif

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

int main(void)
{
	struct rlimit limits;
	int           table[] = {[1] = RLIMIT_AS,      [2] = RLIMIT_CORE,        [3] = RLIMIT_CPU,      [4] = RLIMIT_DATA,
							 [5] = RLIMIT_FSIZE,   [6] = RLIMIT_MEMLOCK,     [7] = RLIMIT_MSGQUEUE, [8] = RLIMIT_NICE,
							 [9] = RLIMIT_NOFILE,  [10] = RLIMIT_NPROC,      [11] = RLIMIT_RSS,     [12] = RLIMIT_RTPRIO,
							 [13] = RLIMIT_RTTIME, [14] = RLIMIT_SIGPENDING, [15] = RLIMIT_STACK};
	int           pick;

	printf("Please input the number associated whit the resource whose limits you want to check\n"
		   "(the descriptions of the meanings of the limits are only acurate in linux):\n"
		   "\t1 RLIMIT_AS The maximum size, in bytes, of the process's virtual memory (address space).\n"
		   "\t2 RLIMIT_CORE The  maximum size of a core file (see core(5)) in bytes that the process may dump.\n"
		   "\t3 RLIMIT_CPU In seconds, on the amount of CPU time that the  process  can  consume.\n"
		   "\t4 RLIMIT_DATA The limit in the process's data segment.\n"
		   "\t5 RLIMIT_FSIZE The maximum size in bytes of files that the process may create.\n"
		   "\t6 RLIMIT_MEMLOCK The maximum number of bytes of memory that may be locked into RAM.\n"
		   "\t7 RLIMIT_MSGQUEUE The number of bytes that can be allocated for POSIX message queues\n"
		   "\t8 RLIMIT_NICE Ceiling to which the process's nice value can be raised using setpriority(2) or nice(2).\n"
		   "\t9 RLIMIT_NOFILE Value one greater than the maximum file descriptor  number  that  can  be  opened  by  "
		   "this process.\n"
		   "\t10 RLIMIT_NPROC Limit on the number of extant process (or, more precisely on Linux, threads).\n"
		   "\t11 RLIMIT_RSS Limit (in bytes) on the process's resident set (the number of  virtual  pages  resident  "
		   "in  RAM).\n"
		   "\t12 RLIMIT_RTPRIO Ceiling on the real-time priority that may be set using sched_setscheduler(2) and "
		   "sched_setparam(2).\n"
		   "\t13 RLIMIT_RTTIME Limit (in microseconds) on the amount of CPU time that a process scheduled under a\n"
		   "\t\treal-time scheduling policy may consume without making a blocking system call.\n"
		   "\t14 RLIMIT_SIGPENDING This is a limit on the number of signals that may be queued.\n"
		   "\t15 RLIMIT_STACK The maximum size of the process stack, in bytes.\n"
		   "\npick: ");
	scanf("%d", &pick);

	if (pick < 1 || pick > 15)
	{
		printf("\nError: invalid input given.\n");
		return (EXIT_FAILURE);
	}
	pick = table[pick];
	if (pick == -1)
	{
		printf("\nError: resource limit does not exist in this system.\n");
		return (EXIT_FAILURE);
	}

	getrlimit(pick, &limits);
	printf("\nLimits for resource:\n\tsoft: %lu\n\thard: %lu\n", limits.rlim_cur, limits.rlim_max);
}

#pragma GCC diagnostic pop
