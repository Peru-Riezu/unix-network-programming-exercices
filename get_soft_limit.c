/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: get_soft_limit.c                                               */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2024/02/21 11:44:24                                            */
/*   Updated:  2024/02/21 12:38:38                                            */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

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
	struct rlimit	limits;
	int				pick;

	printf("Please input the number associated whit the resource whose limits you want to check:\n"
		   "\t1 RLIMIT_AS The maximum size, in bytes, of the process's virtual memory (address space).\n"
		   "\t2 RLIMIT_CORE The  maximum size of a core file (see core(5)) in bytes that the process may dump.\n"
		   "\t3 RLIMIT_CPU In seconds, on the amount of CPU time that the  process  can  consume.\n"
		   "\t4 RLIMIT_DATA The process's data segment.\n"
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
		   "pick: ");
	scanf("%d",&pick);

	switch (pick)
	{
		case 1:
		{
			pick = RLIMIT_AS;
			break;
		}
		case 2:
		{
			pick = RLIMIT_CORE;
			break;
		}
		case 3:
		{
			pick = RLIMIT_CPU;
			break;
		}
		case 4:
		{
			pick = RLIMIT_DATA;
			break;
		}
		case 5:
		{
			pick = RLIMIT_FSIZE;
			break;
		}
		case 6:
		{
			pick = RLIMIT_MEMLOCK;
			break;
		}
		case 7:
		{
			pick = RLIMIT_MSGQUEUE;
			break;
		}
		case 8:
		{
			pick = RLIMIT_NICE;
			break;
		}
		case 9:
		{
			pick = RLIMIT_NOFILE;
			break;
		}
		case 10:
		{
			pick = RLIMIT_NPROC;
			break;
		}
		case 11:
		{
			pick = RLIMIT_RSS;
			break;
		}
		case 12:
		{
			pick = RLIMIT_RTPRIO;
			break;
		}
		case 13:
		{
			pick = RLIMIT_RTTIME;
			break;
		}
		case 14:
		{
			pick = RLIMIT_SIGPENDING;
			break;
		}
		case 15:
		{
			pick = RLIMIT_STACK;
			break;
		}
		default:
			printf("Error: invalid input.\n");
			return (EXIT_FAILURE);
	}

	getrlimit(pick, &limits);
	printf("Limits for resource:\n\tsoft: %lu\n\thard: %lu\n", limits.rlim_cur, limits.rlim_max);
}

#pragma GCC diagnostic pop
