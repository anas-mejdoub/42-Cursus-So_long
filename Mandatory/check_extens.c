/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:26:31 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/25 12:48:00 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_extension(char *filename)
{
    char *extension = ft_strrchr(filename, '.');
    if (!ft_strncmp(extension, ".ber", 5))
        return (1);
    write(2, "invalid extension !\n", 21);
    exit(1);
}

void printf_err()
{
    write(2, "invalid map !\n", 15);
	exit(1);
}