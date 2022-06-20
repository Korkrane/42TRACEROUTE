/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:28:32 by bahaas            #+#    #+#             */
/*   Updated: 2022/06/20 21:39:55 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_traceroute.h"

t_params params;

static bool help()
{
    fprintf(stderr, "Usage:\n  ft_traceroute: [options] host [ packetlen ]\n"
                    "Options:\n"
                    "  <destinaton>\t     dns name or ip address\n"
                    "  -h\t\t     print help and exit\n"
                    "  -v\t\t     verbose output\n"
                    "Arguments:\n"
                    "+    host          The host to traceroute to\n"
                    "     packetlen     The full packet length (default is the length of an IP\n                   header plus 40) .Can be ignored or increased to a minimal\n                   allowed value\n");
        return false;
}

void setAddress(char *host_name, int pos)
{
    struct addrinfo hints;
    struct addrinfo *res = NULL;
    char address[INET_ADDRSTRLEN];

    ft_bzero(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;
    if (getaddrinfo(host_name, NULL, &hints, &res) != 0)
    {
        fprintf(stderr, "%s: Name or service not known\n", host_name);
        fprintf(stderr, "Cannot handle \"host\" cmdline arg `%s' on position 1 (argc %d)\n", host_name, pos);
        exit(2);
    }
    params.reversed_address = res->ai_canonname;
    ft_memcpy(&params.sockaddr, res->ai_addr, sizeof(struct sockaddr_in));
    inet_ntop(AF_INET, &(params.sockaddr.sin_addr), address, INET_ADDRSTRLEN);
    printf("address: %s\n", address);
    printf("reversed: %s\n", res->ai_canonname);
    params.address = ft_strdup(address);
}

void setPacketLen(char **av, int pos)
{
    if (av[pos] && !ft_isnbr(av[pos]))
    {
        fprintf(stderr, "Cannot handle \"packetlen\" cmdline arg `%s' on position 2 (argc %d)\n", av[pos], pos);
        exit(2);
    }
    else if(av[pos])
    {
        int size = ft_atoi(av[pos]);
        //printf("packetlen %d\n", size);

        if(size <= 0)
        {
            fprintf(stderr, "Bad option `%s' on position %d\n", av[pos], pos);
            exit(2);
        }
        else if(size < 28)
            params.packet_size = 20; // sizeof(iphdr)
        else if(size > 9999)
        {
                fprintf(stderr, "too big packet len %d specified\n", size);
                exit(2);
        }
        else
            params.packet_size = size;
    }
    //printf("icmp %zu\n", sizeof(struct icmp));
    //printf("icmphdr %zu\n", sizeof(struct icmphdr));
    //printf("iphdr %zu\n", sizeof(struct iphdr));
    //printf("ip %zu\n", sizeof(struct ip));
}

void traceroute()
{

}

// adding -i -m -p -s -q -N -t -l... flags

// -m modify max_ttl (hops) 0: first hop out of range
//                            -1: max hops cannot be more than 255
//                            without value: cannot handle -m option with arg 'next arg' argc 2
//sudo traceroute -m:                    Option `- m ' (argc 1) requires an argument: `-m max_ttl'

// sudo traceroute -m 280
//Specify "host" missing argument.
// -n do not get hostname only ip for each hop
// -f first__ttl , mv the sequence to a specific one
//-z wait time between each prob on each hops :)
static bool parsing(int ac, char **av)
{
    if(ac < 2)
        return(help());
    for (int i = 1; i < ac; i++)
    {
        if(ft_strcmp("--help", av[i]) == 0)
            return(help());
        else
        {
            params.user_requested_address = av[i];
            setAddress(params.user_requested_address, i);
            setPacketLen(av, i + 1);
            return true;
        }
    }
    return true;
}

int main(int ac, char **av)
{
    init();
    if(parsing(ac, av))
    {
        //createSocket();
        printTracerouteInfo();
        traceroute();
    }
    return 0;
}