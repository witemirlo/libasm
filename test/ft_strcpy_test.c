#include "ft_tests.h"

void ft_strcpy_test(void)
{
	char const *tests[] = {
		"Hello, World!",
		"a",
		"",
		"\t\v\t\v\a\b\33\1",
		"\0\0\0\0\0",
		"😀",
		NULL
	};

	char *og_strcpy, *my_strcpy;
	char *og_address, *my_address;
	int fd, i;

	printf("Tests from %s:\n", __func__);
	for (i = 0; tests[i] != NULL; i++) {
		og_strcpy = calloc(strlen(tests[i]) + 1, sizeof(char));
		og_address = og_strcpy;

		my_strcpy = calloc(strlen(tests[i]) + 1, sizeof(char));
		my_address = my_strcpy;

		og_strcpy = strcpy(og_strcpy, tests[i]);
		my_strcpy = ft_strcpy(my_strcpy, tests[i]);

		if (memcmp(og_strcpy, my_strcpy, (sizeof(char) * strlen(tests[i]))) != 0
		    || my_strcpy != my_address)
			fd = 2;
		else
			fd = 1;

		dprintf(fd, "%s test %2d:\n"
			    "\tstrcpy: returned address: %p, original address: %p\n"
			    "\tft_strcpy: returned address: %p, original address: %p\n",
				msg[fd - 1], i, og_strcpy, og_address, my_strcpy, my_address);

		free(og_strcpy);
		free(my_strcpy);
	}
}
