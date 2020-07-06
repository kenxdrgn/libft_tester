/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:43:15 by jliew             #+#    #+#             */
/*   Updated: 2020/07/02 15:12:36 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "time.h"
#include "ctype.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"

int		ft_isprint(int c);

int		main(int argc, char **argv)
{
	if (argc == 1)
    {
		printf("-----------------------\n");
		printf(" int ft_isprint(int c)\n");
		printf("-----------------------\n");
        printf("usage [auto]:\n1. a --run\n2. a --run --print\n");
        printf("usage [manual]:\n1. a <int c>\n");
        return (42);
    }
	else if (!strcmp(argv[1], "--run"))
	{
		long cnt = 0;
		long failed = 0;

		printf("Running small test(s): ft_isprint\n");
		for (int i = 0; i <= 127; i++)
		{
			cnt++;
			if (isprint(i) != ft_isprint(i))
			{
				failed++;
				printf("FAILED case: %d , st: %d, ft: %d\n", i, isprint(i), ft_isprint(i));
			}
			if (argc == 3 && !strcmp(argv[2], "--print"))
				printf("%ld: test case: %c , st: %i, ft: %i\n", cnt, i, isprint(i), ft_isprint(i));
		}
		double rate = ((cnt - failed) / (double)cnt) * 100;
		printf("%.2f%%: Checks: %ld, Failures: %ld\n", rate, cnt, failed);

		cnt = 0;
		failed = 0;
		printf("Running full test(s): ft_isprint\n");
		for (long i = INT_MIN; i <= INT_MAX; i++)
		{
			cnt++;
			if (isprint(i) != ft_isprint(i))
			{
				failed++;
				printf("FAILED case: %ld , st: %d, ft: %d\n", i, isprint(i), ft_isprint(i));
			}
		}
		rate = ((cnt - failed) / (double)cnt) * 100;
		printf("%.2f%%: Checks: %ld, Failures: %ld\n", rate, cnt, failed);
	}
	else if (strlen(argv[1]) == 1)
	{
		printf("st: %i\n", isprint((argv[1][0])));
		printf("ft: %i\n", ft_isprint((argv[1][0])));
	}
	else
	{
		printf("st: %i\n", isprint(atoi(argv[1])));
		printf("ft: %i\n", ft_isprint(atoi(argv[1])));
	}
}
