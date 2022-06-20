/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:23:34 by bahaas            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/20 16:42:26 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRACEROUTE_H
#define FT_TRACEROUTE_H
=======
/*   Updated: 2022/06/14 16:21:52 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
>>>>>>> ed0dbd0c2c36c70da37806b44eaac5c5e3f3d62d

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

typedef struct s_params
{
    char *user_requested_address;
    char *address;
    int ttl;
    int max_ttl;
    int interval;
    int probes;
    int flags;
    pid_t pid;
    int seq;
    int socket_fd;
} t_params;

<<<<<<< HEAD
extern t_params params;

#endif
=======
t_params params;
>>>>>>> ed0dbd0c2c36c70da37806b44eaac5c5e3f3d62d
