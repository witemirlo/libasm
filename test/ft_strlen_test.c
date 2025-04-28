#include "ft_tests.h"

void ft_strlen_check(void)
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

void check_NULL(void)
{
	int pid1, pid2, ret1, ret2, fd;

	strlen(0x1);
	pid1 = fork();
	if (pid1 == 0) {
		int i = strlen(NULL);
		exit(i);
	}
	waitpid(pid1, &ret1, 0);
	if (WIFSIGNALED(ret1))
		ret1 = WCOREDUMP(ret1);
	else
		ret1 = WEXITSTATUS(ret1);

	pid2 = fork();
	if (pid2 == 0) {
		int i = ft_strlen(NULL);
		exit(i);
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

void ft_strlen_test(void)
{
	ft_strlen_check();
	check_NULL();
}
