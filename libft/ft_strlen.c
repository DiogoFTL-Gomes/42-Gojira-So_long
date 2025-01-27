/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:58:33 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/07 10:32:20 by ddiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

/*
#include <stdio.h>
#include "libft.h"

int main()
{
	// cc -Wall -Wextra -Werror testador.c libft.a

	printf("\n\nFT_STRLEN\n");
	printf("Testes com strings comuns\n");
	printf("Testando 'banana': %zu\n", ft_strlen("banana")); 
		// Esperado: 6
	printf("Testando '42 Lisboa': %zu\n", ft_strlen("42 Lisboa")); 
		// Esperado: 10
	printf("Testando '': %zu\n", ft_strlen("")); 
		// Esperado: 0

	printf("Testes com strings com espaços e caracteres especiais\n");
	printf("Testando 'abc 123!': %zu\n", ft_strlen("abc 123!")); 
		// Esperado: 10
	printf("Testando 'Hello, World!': %zu\n", ft_strlen("Hello, World!")); 
		// Esperado: 13

	return 0;
}

*/