/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: inet_pton_loose.c                                              */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2024/02/13 16:51:48                                            */
/*   Updated:  2024/02/13 19:56:13                                            */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
#pragma GCC diagnostic ignored "-Wgnu-designator"
#pragma GCC diagnostic ignored "-Wlanguage-extension-token"
;

static int inet_pton_loose(typeof(AF_INET) family, char const *presentation, void *buffer)
{
	if (family != AF_INET && family != AF_INET6)
	{
		errno = EAFNOSUPPORT;
		return (-1);
	}
	if (inet_pton(family, presentation, buffer) == 1)
	{
		return (1);
	}
	if (family == AF_INET)
	{
		struct in_addr aux;

		if (inet_aton(presentation, &aux) == 1)
		{
			memcpy(((uint8_t *)buffer), &aux, sizeof(aux));
			return (1);
		}
	}
	else if (family == AF_INET6)
	{
		struct in_addr aux;

		memcpy(buffer, (uint8_t[]){[0 ... 9] = 0, [10 ... 11] = 0xff}, 12);
		if (inet_aton(presentation, &aux) == 1)
		{
			memcpy(((uint8_t *)buffer) + 12, &aux, sizeof(aux));
			return (1);
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("loose_inet_pton: Usage: ./a.out \"AF_INET|AF_INET6\" \"string to convert\"\n");
		return (EXIT_FAILURE);
	}
	if (strcmp("AF_INET", argv[1]) == 0)
	{
		struct in_addr address;

		if (inet_pton_loose(AF_INET, argv[2], &address) == 0)
		{
			printf("loose_inet_pton: Invalid string given\n");
			return (EXIT_FAILURE);
		}
		printf("%hhu.%hhu.%hhu.%hhu\n", *((uint8_t *)&address.s_addr), *(((uint8_t *)&address.s_addr) + 1),
			   *(((uint8_t *)&address.s_addr) + 2), *(((uint8_t *)&address.s_addr) + 3));
		return (EXIT_SUCCESS);
	}
	if (strcmp("AF_INET6", argv[1]) == 0)
	{
		struct in6_addr address;

		if (inet_pton_loose(AF_INET6, argv[2], &address) == 0)
		{
			printf("loose_inet_pton: Invalid string given\n");
			return (EXIT_FAILURE);
		}
		printf("%02hhx%02hhx:%02hhu%02hhx:%02hhu%02hhx:%02hhu%02hhx:%02hhu%02hhx:%02hhx%02hhx:%02hhx%02hhx:"
			   "%02hhx%02hhx\n",
			   address.s6_addr[0], address.s6_addr[1], address.s6_addr[2], address.s6_addr[3], address.s6_addr[4],
			   address.s6_addr[5], address.s6_addr[6], address.s6_addr[7], address.s6_addr[8], address.s6_addr[9],
			   address.s6_addr[10], address.s6_addr[11], address.s6_addr[12], address.s6_addr[13], address.s6_addr[14],
			   address.s6_addr[15]);
		return (EXIT_SUCCESS);
	}
	printf("loose_inet_pton: Invalid family given as address family\n");
	return (EXIT_FAILURE);
}

#pragma GCC diagnostic pop
