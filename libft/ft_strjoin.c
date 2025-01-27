/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:49:32 by darkless12        #+#    #+#             */
/*   Updated: 2024/11/07 10:33:06 by ddiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*copy;

	size = ft_strlen(s1) + ft_strlen(s2);
	copy = (char *)malloc((size + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	copy[0] = 0;
	ft_strlcat(copy, s1, ft_strlen(s1) + 1);
	ft_strlcat(copy, s2, size + 1);
	return (copy);
}

/*
#include <stdio.h>
#include "libft.h"

int main()
{
	// cc -Wall -Wextra -Werror testador.c libft.a

	printf("\n\nFT_STRJOIN\n");
	// Teste 1: Concatenação de duas strings normais
	char const *str1 = "42 ";
	char const *str2 = "Lisboa";
	char *joined1 = ft_strjoin(str1, str2);
	
	printf("Teste 1: Concatenação de duas strings normais\n");
	if (joined1)
	{
		printf("Resultado: %s\n", joined1);  // Esperado: "42 Lisboa"
		free(joined1);
	}
	else
	{
		printf("Erro ao alocar memória!\n");
	}

	// Teste 2: String vazia + string normal
	char const *str3 = "";
	char const *str4 = "Lisboa";
	char *joined2 = ft_strjoin(str3, str4);
	
	printf("\nTeste 2: Concatenação de string vazia com string normal\n");
	if (joined2)
	{
		printf("Resultado: %s\n", joined2);  // Esperado: "Lisboa"
		free(joined2);
	}
	else
	{
		printf("Erro ao alocar memória!\n");
	}

	// Teste 3: String normal + string vazia
	char const *str5 = "42";
	char const *str6 = "";
	char *joined3 = ft_strjoin(str5, str6);
	
	printf("\nTeste 3: Concatenação de string normal com string vazia\n");
	if (joined3)
	{
		printf("Resultado: %s\n", joined3);  // Esperado: "42"
		free(joined3);
	}
	else
	{
		printf("Erro ao alocar memória!\n");
	}

	// Teste 4: Duas strings vazias
	char const *str7 = "";
	char const *str8 = "";
	char *joined4 = ft_strjoin(str7, str8);
	
	printf("\nTeste 4: Concatenação de duas strings vazias\n");
	if (joined4)
	{
		printf("Resultado: '%s'\n", joined4);  // Esperado: ""
		free(joined4);
	}
	else
	{
		printf("Erro ao alocar memória!\n");
	}

	return 0;
}

*/