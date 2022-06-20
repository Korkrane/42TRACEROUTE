/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:25:08 by bahaas            #+#    #+#             */
/*   Updated: 2022/06/20 20:59:23 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_traceroute.h"

void init()
{
    params.ttl = 1;
    params.max_ttl = 30;
    // params.interval = 0;
    params.probes = 3;
    params.seq = 1;
    params.socket_fd = -1;
    params.packet_size = PACKET_SIZE;
    params.pid = getpid();
}