#include "ft_tests.h"

void ft_strcpy_check(void)
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

	char *og_strcpy, *my_strcpy;
	char *og_address, *my_address;
	int fd, i;
	size_t size;

	printf("Tests from %s:\n", __func__);
	for (i = 0; tests[i] != NULL; i++) {
		size = strlen(tests[i]) + 1;

		og_strcpy = malloc(size * sizeof(char));
		og_strcpy[size -1] = '*';
		og_address = og_strcpy;

		my_strcpy = malloc(size * sizeof(char));
		my_strcpy[size -1] = '*';
		my_address = my_strcpy;

		og_strcpy = strcpy(og_strcpy, tests[i]);
		my_strcpy = ft_strcpy(my_strcpy, tests[i]);

		if (memcmp(og_strcpy, my_strcpy, (sizeof(char) * size)) != 0
		    || my_strcpy != my_address)
			fd = 2;
		else
			fd = 1;

		dprintf(fd, "%s test %2d:\n"
			    "\tstrcpy:    returned address: %p, original address: %p\n"
			    "\tft_strcpy: returned address: %p, original address: %p\n"
			    "\tstrcpy:    '%s'\n"
			    "\tft_strcpy: '%s'\n",
				msg[fd - 1], i,
				og_strcpy, og_address,
				my_strcpy, my_address,
				og_strcpy,
				my_strcpy);

		free(og_strcpy);
		free(my_strcpy);
	}
}

ft_strcpy_check_arg_NULL()
{
	int pid1, pid2, ret1, ret2, fd;
	char ar[100];

	pid1 = fork();
	if (pid1 == 0) {
		char* tmp = strcpy(ar, NULL);
		exit((int)tmp);
	}
	waitpid(pid1, &ret1, 0);
	if (WIFSIGNALED(ret1))
		ret1 = WCOREDUMP(ret1);
	else
		ret1 = WEXITSTATUS(ret1);

	pid2 = fork();
	if (pid2 == 0) {
		char* tmp = ft_strcpy(ar, NULL);
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

	dprintf(fd, "%s test arg NULL check: expected %2d, received %2d\n",
			msg[fd - 1], ret1, ret2);
}

ft_strcpy_check_NULL_arg()
{
	int pid1, pid2, ret1, ret2, fd;
	char ar[] = "hi!";

	pid1 = fork();
	if (pid1 == 0) {
		char* tmp = strcpy(NULL, ar);
		exit((int)tmp);
	}
	waitpid(pid1, &ret1, 0);
	if (WIFSIGNALED(ret1))
		ret1 = WCOREDUMP(ret1);
	else
		ret1 = WEXITSTATUS(ret1);

	pid2 = fork();
	if (pid2 == 0) {
		char* tmp = ft_strcpy(NULL, ar);
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

	dprintf(fd, "%s test NULL arg check: expected %2d, received %2d\n",
			msg[fd - 1], ret1, ret2);
}

ft_strcpy_check_NULL_NULL()
{
	int pid1, pid2, ret1, ret2, fd;

	pid1 = fork();
	if (pid1 == 0) {
		char* tmp = strcpy(NULL, NULL);
		exit((int)tmp);
	}
	waitpid(pid1, &ret1, 0);
	if (WIFSIGNALED(ret1))
		ret1 = WCOREDUMP(ret1);
	else
		ret1 = WEXITSTATUS(ret1);

	pid2 = fork();
	if (pid2 == 0) {
		char* tmp = ft_strcpy(NULL, NULL);
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

	dprintf(fd, "%s test NULL NULL check: expected %2d, received %2d\n",
			msg[fd - 1], ret1, ret2);
}

void ft_strcpy_test(void)
{
	ft_strcpy_check();
	ft_strcpy_check_arg_NULL();
	ft_strcpy_check_NULL_arg();
	ft_strcpy_check_NULL_NULL();
}
