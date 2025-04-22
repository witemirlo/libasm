#include "ft_tests.h"

void ft_strlen_test(void)
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

	size_t og_strlen, my_strlen;
	int fd, i;

	for (i = 0; tests[i] != NULL; i++) {
		og_strlen = strlen(tests[i]);
		my_strlen = ft_strlen(tests[i]);

		if (memcmp(&my_strlen, &og_strlen, sizeof(size_t)) != 0)
			fd = 2;
		else
			fd = 1;

		dprintf(fd, "%s %s %d: expected `%ld`, received `%ld`\n",
				msg[fd - 1], __func__, i, og_strlen, my_strlen);
	}
}


