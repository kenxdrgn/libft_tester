/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:34:22 by jliew             #+#    #+#             */
/*   Updated: 2020/07/10 23:22:08 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libft.h"

void			gen_rand_2strings(char *dst1, char *dst2, int n)
{
	for (int i = 0; i < n; i++)	
	{
		int c = rand() % 95 + 32;
		*dst1++ = c;
		*dst2++ = c;
	}
	*dst1 = '\0';
	*dst2 = '\0';
}

void			gen_rand_string(char *dst, int n)
{
	for (int i = 0; i < n; i++)
		*dst++ = rand() % 95 + 32;
	*dst = '\0';
}

int				main(int argc, char **argv)
{
	srand(time(0));

	if (argc == 1)
    {
		printf("---------------------------------------------------------\n");
		printf(" size_t ft_strlcat(char *dst, const char *src, size_t n)\n");
		printf("---------------------------------------------------------\n");
        printf("usage [auto]:\n1. a --run\n2. a --run <test_cases>\n3. a --run <test_cases> --print\n");
        printf("usage [manual]:\n1. a <string dst> <string src> <int n>\n");
        return (42);
    }
	else if (!strcmp(argv[1], "--run"))
	{
		char	src[101];
		char	dst1[201];
		char	dst2[201];
		int		print = 0;
		int		failed = 0;
		char	cpy_dst[101];
		int		test_cases = 1000000;

		if (argc >= 3)
			test_cases = atoi(argv[2]);
		if (argc >= 4 && !strcmp(argv[3], "--print"))
			print = 1;
		printf("Running test(s): ft_strlcat\n");
		for (int i = 0; i < test_cases; i++)
		{
			int n = rand() % 201;
			int dn = rand() % 101;
			int sn = rand() % 101;
			gen_rand_2strings(dst1, dst2, dn);
			gen_rand_string(src, sn);
			strcpy(cpy_dst, dst1);
			size_t st = strlcat(dst1, src, n);
			size_t ft = ft_strlcat(dst2, src, n);

			if (st != ft || strcmp(dst1, dst2))
			{
				failed++;
				printf("FAILED case:\nsrc: %s\ndst: %s\nn: %d\nst: %lu | %s\nft: %lu | %s\n", src, cpy_dst, n, st, dst1, ft, dst2);
			}
			if (print)
				printf("[%d] test case:\nsrc: %s\ndst: %s\nn: %d\nst: %lu | %s\nft: %lu | %s\n", i + 1, src, cpy_dst, n, st, dst1, ft, dst2);
		}
		double rate = ((test_cases - failed) / (double)test_cases) * 100;
		printf("%2.f%%: Checks: %d, Failures: %d\n", rate, test_cases, failed);
	}
	else
	{
		int n;
		char *src;
		char *dst;

		dst = argv[1];
		src = argv[2];
		n = atoi(argv[3]);
		char dst1[100];
		char dst2[100];
		memset(dst1, 0, sizeof(dst1));
		memset(dst2, 0, sizeof(dst2));
		strcpy(dst1, dst);
		strcpy(dst2, dst);
		printf("st: %lu | %s\n", strlcat(dst1, src, n), dst1);
		printf("ft: %lu | %s\n", ft_strlcat(dst2, src, n), dst2);
	}
}
