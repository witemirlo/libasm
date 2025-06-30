#include "ft_tests.h"

static void ft_strdup_check(void)
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

	char *og_strdup, *my_strdup;
	int fd, i;

	printf("Tests from %s:\n", __func__);
	for (i = 0; tests[i] != NULL; i++) {
		og_strdup = strdup(tests[i]);
		my_strdup = ft_strdup(tests[i]);

		if (strlen(og_strdup) != strlen(my_strdup))
			fd = 2;
		else if (strcmp(og_strdup, my_strdup) != 0)
			fd = 2;
		else
			fd = 1;

		dprintf(fd, "%s test %2d: expected %s, received %s\n",
				msg[fd - 1], i, og_strdup, my_strdup);

		free(og_strdup);
		free(my_strdup);
	}
}

void ft_strdup_test(void)
{
	ft_strdup_check();
}
