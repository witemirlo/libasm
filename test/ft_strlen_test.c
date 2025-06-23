#include "ft_tests.h"

static void ft_strlen_check(void)
{
	char const *tests[] = {
		"Hello, World!",
		"a",
		"",
		"\t\v\t\v\a\b\33\1",
		"\0\0\0\0\0",
		"😀",
		"😀\r\t\00\000🐀🐀🐀🐀🐀🐀\v\v\v\r\r\n\\n\n🐀",
		"𝔊𝔬𝔱𝔥𝔦𝔠",
		"oldɯǝɾǝ un sǝ ǝʇsǝ",
		"⠞⠓⠊⠎⠀⠊⠎⠀⠁⠝⠀⠑⠭⠁⠍⠏⠇⠑",
		NULL
	};

	size_t og_strlen, my_strlen;
	int fd, i;

	printf("Tests from %s:\n", __func__);
	for (i = 0; tests[i] != NULL; i++) {
		og_strlen = strlen(tests[i]);
		my_strlen = ft_strlen(tests[i]);

		if (og_strlen != my_strlen)
			fd = 2;
		else
			fd = 1;

		dprintf(fd, "%s test %2d: expected %2ld, received %2ld\n",
				msg[fd - 1], i, og_strlen, my_strlen);
	}
}

void ft_strlen_test(void)
{
	ft_strlen_check();
}
