/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:43:32 by ebonutto          #+#    #+#             */
/*   Updated: 2025/05/17 11:51:58 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

int	main( void )
{
	void *hello = malloc(30);
	printf("%p\n", hello);
	printf("%lu\n", (uintptr_t)hello);
	free(hello);
	return (0);
}
