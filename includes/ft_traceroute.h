/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:23:34 by bahaas            #+#    #+#             */
/*   Updated: 2022/06/20 21:13:06 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRACEROUTE_H
#define FT_TRACEROUTE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <errno.h>
#include <math.h>

#include <netinet/ip_icmp.h> //include icmphdr struct and ICMP_* var
#include <netinet/in.h>      //include icmphdr struct and ICMP_* var
#include "../libft/libft.h"

#define SOCKET_ERROR "ft_ping: socket: operation not permitted"
#define SETSOCKOPT_ERROR "ft_ping: setsockopt: error while setting socket options"

#define PACKET_SIZE 60

typedef struct s_params
{
    char *user_requested_address;
    char *reversed_address;
    char *address;
    int ttl;
    int max_ttl;
    int interval;
    int probes;
    int flags;
    pid_t pid;
    int seq;
    int socket_fd;
    struct sockaddr_in sockaddr;
    int packet_size;
} t_params;

extern t_params params;

/** init.c **/
void init();

/** socket.c **/
void createSocket();

/** print.c **/
void printTracerouteInfo();

#endif
