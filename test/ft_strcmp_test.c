#include "ft_tests.h"

void ft_strcmp_test(void)
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

        int fd, i, j, og_strcmp, my_strcmp;

	printf("Tests from %s:\n", __func__);
	for (i = 0; tests[i] != NULL; i++) {
                for (j = 0; tests[j] != NULL; j++) {
                        og_strcmp = strcmp(tests[i], tests[j]);
                        my_strcmp = ft_strcmp(tests[i], tests[j]);

                        if (og_strcmp != my_strcmp)
                                fd = 2;
                        else
                                fd = 1;

                        dprintf(fd, "%s test %d.%d: expected %3d, received %3d\n",
                                        msg[fd - 1], i, j, og_strcmp, my_strcmp);
                }
	}
}
