/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:11:03 by bahaas            #+#    #+#             */
/*   Updated: 2022/06/20 21:13:30 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_traceroute.h"

void printTracerouteInfo()
{
    printf("traceroute to %s(%s), %d hops max, %d bytes packets\n",
           params.reversed_address,
           params.address,
           params.max_ttl,
          params.packet_size);
}