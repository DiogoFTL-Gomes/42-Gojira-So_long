/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:24:19 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/07 10:32:51 by ddiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	if (size <= i)
		return (size + ft_strlen(src));
	j = 0;
	while (i < size - 1 && src[j] != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}

/*
#include <stdio.h>
#include "libft.h"

int main()
{
	// cc -Wall -Wextra -Werror testador.c libft.a

	printf("\n\nFT_STRLCAT\n");

	printf("Testando ft_strlcat com buffer suficiente\n");
	char dst1[20] = "Hello, ";
	const char *src1 = "world!";
	size_t size1 = 20;
	printf("Resultado de ft_strlcat: %zu\n", ft_strlcat(dst1, src1, size1));
	printf("Conteúdo de dst: %s\n", dst1);
		// Esperado: 'Hello, world!'

	printf("Testando ft_strlcat com buffer maior que a string de origem\n");
	char dst2[20] = "Short ";
	const char *src2 = "string";
	size_t size2 = 20;
	printf("Resultado de ft_strlcat: %zu\n", ft_strlcat(dst2, src2, size2));
	printf("Conteúdo de dst: %s\n", dst2);
		// Esperado: 'Short string'

	printf("Testando ft_strlcat com buffer menor que a string de origem\n");
	char dst3[8] = "Hello, ";
	const char *src3 = "world!";
	size_t size3 = 8;
	printf("Resultado de ft_strlcat: %zu\n", ft_strlcat(dst3, src3, size3));
	printf("Conteúdo de dst: %s\n", dst3);
		// Esperado: 'Hello, w' (apenas a parte cabível na string)

	printf("Testando ft_strlcat com buffer exatamente do tamanho necessário\n");
	char dst4[13] = "Hello, ";
	const char *src4 = "world!";
	size_t size4 = 13;
	printf("Resultado de ft_strlcat: %zu\n", ft_strlcat(dst4, src4, size4));
	printf("Conteúdo de dst: %s\n", dst4);
		// Esperado: 'Hello, world!'

	printf("Testando ft_strlcat com buffer de tamanho 0\n");
	char dst5[1] = "";
	const char *src5 = "No copy";
	size_t size5 = 0;
	printf("Resultado de ft_strlcat: %zu\n", ft_strlcat(dst5, src5, size5));
	printf("Conteúdo de dst: '%s'\n", dst5);
		// Esperado: '' (não copia nada)

	return 0;
}

*/