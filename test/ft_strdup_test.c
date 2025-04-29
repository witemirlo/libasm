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
		else if (memcmp(og_strdup, my_strdup, strlen(og_strdup)) != 0)
			fd = 2;
		else
			fd = 1;

		dprintf(fd, "%s test %2d: expected %s, received %s\n",
				msg[fd - 1], i, og_strdup, my_strdup);

		free(og_strdup);
		free(my_strdup);
	}
}

static void check_NULL(void)
{
	int pid1, pid2, ret1, ret2, fd;

	pid1 = fork();
	if (pid1 == 0) {
		char* tmp = strdup(NULL);
		exit((int)tmp);
	}
	waitpid(pid1, &ret1, 0);
	if (WIFSIGNALED(ret1))
		ret1 = WCOREDUMP(ret1);
	else
		ret1 = WEXITSTATUS(ret1);

	pid2 = fork();
	if (pid2 == 0) {
		char* tmp = ft_strdup(NULL);
		exit((int)tmp);
	}

	waitpid(pid2, &ret2, 0);
	if (WIFSIGNALED(ret2))
		ret2 = WCOREDUMP(ret2);
	else
		ret2 = WEXITSTATUS(ret2);

	if (ret1 != ret2)
		fd = 2;
	else
		fd = 1;

	dprintf(fd, "%s test NULL check: expected %2d, received %2d\n",
			msg[fd - 1], ret1, ret2);
}

void ft_strdup_test(void)
{
	ft_strdup_check();
	check_NULL();
}
