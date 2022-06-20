/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:28:32 by bahaas            #+#    #+#             */
/*   Updated: 2022/06/20 15:47:53 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_traceroute.h"

int help()
{
    fprintf(stderr, "\nUsage\n  ft_traceroute [options] <destination>\n"
                    "\nOptions:\n"
                    "  <destinaton>\t     dns name or ip address\n"
                    "  -h\t\t     print help and exit\n"
                    "  -v\t\t     verbose output\n");
    return 0;
}

void init()
{
    params.ttl = 1;
    params.max_ttl = 30;
    //params.interval = 0;
    params.probes = 3;
    params.seq = 1;
    params.socket_fd = -1;

    params.pid = getpid();
}

void error_output(char *message)
{
    fprintf(stderr, "%s\n", message);
}

void error_output_and_exit(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void	create_socket(void)
{
	int				socket_fd;
	struct timeval	timeout;

	timeout.tv_sec = 1;
	timeout.tv_usec = 0;
	// if ((socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1)
	// 	error_output_and_exit(SOCKET_ERROR);
	// if ((setsockopt(socket_fd, IPPROTO_IP, IP_TTL, &(params.ttl), sizeof(params.ttl))) == -1)
	// 	error_output_and_exit(SETSOCKOPT_ERROR);
	// if ((setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, (const void *)&timeout, sizeof(timeout))) == -1)
	// 	error_output_and_exit(SETSOCKOPT_ERROR);
	params.socket_fd = socket_fd;
}


int parsing(int ac, char **av)
{
    if(ac < 2)
        return(help());
    for (int i = 1; i < ac; i++)
    {
        // if (av[i][0] == '-')
        // {
        //     int flag = 1;
        //     for (int j = 1; av[i][j] && flag; j++)
        //     {
        //         switch (av[i][j])
        //         {

        //         case 'q':
        //             break;
        //         case 'h':
        //             return (help());
        //         case 's':
        //             break;
        //         default:
        //             printf("ft_traceroute: Invalid option -- '%c'\n", av[i][j]);
        //             return (help());
        //         }
        //     }
        // }
        if(ft_strcmp("--help", av[i]))
            return(help());
        else
        {
            params.user_requested_address = av[i];
            //_checkOpt(); // for params
            return true;
        }
    }
    return true;
}

int main(int ac, char **av)
{
    if(parsing(ac, av))
    {
        init();
        //if(params.address)
        //    create_socket();
        //if (params.socket_fd != -1)
        //{
        //    ping_loop();
        //}
    }
    return 0;
}