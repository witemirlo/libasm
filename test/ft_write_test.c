#include "ft_tests.h"

typedef struct s_pair {
	char*  str;
	size_t size;

} t_pair;

typedef struct s_data {
	int     my_errno;
	ssize_t my_return;
	int     og_errno;
	ssize_t og_return;
} t_data;

static t_data test(int fd, void const* buffer, size_t size)
{
	int back = dup(fd);
	int redir = open("/dev/null", O_WRONLY, 0);
	t_data ret = {0};

	if (fd != -1)
		dup2(redir, fd);

	errno = 0;
	ret.og_return = write(fd, buffer, size);
	ret.og_errno = errno;

	errno = 0;
	ret.my_return = ft_write(fd, buffer, size);
	ret.my_errno = errno;

	close(redir);
	if (back != -1) {
		dup2(back, fd);
		close(back);
	}

	return ret;
}

static t_data test_stdout(void const* buffer, size_t size)
{
	return test(1, buffer, size);
}

static t_data test_stderr(void const* buffer, size_t size)
{
	return test(2, buffer, size);
}

static t_data test_badfd(void const* buffer, size_t size)
{
	return test(-1, buffer, size);
}

static t_data test_file(void const* buffer, size_t size)
{
	int fd = open("tmp", O_CREAT | O_WRONLY, 0);

	t_data ret = test(fd, buffer, size);

	close(fd);
	unlink("tmp");
	return ret;
}

void ft_write_test(void)
{
	t_pair const tests[] = {
		(t_pair){.str = "Hello, World!", .size = 13},
		(t_pair){.str = "a", .size = 1},
		(t_pair){.str = "", .size = 0},
		(t_pair){.str = "\t\v\t\v\a\b\33\1", .size = 8},
		(t_pair){.str = "\0\0\0\0\0", .size = 5},
		(t_pair){.str = "😀", .size = sizeof("😀")},
		(t_pair){.str = "😀\r\t\00\000🐀🐀🐀🐀🐀🐀\v\v\v\r\r\n\\n\n🐀", .size = (sizeof("😀") * 8) + 13},
		(t_pair){.str = "𝔊𝔬𝔱𝔥𝔦𝔠", .size = sizeof("𝔊𝔬𝔱𝔥𝔦𝔠")},
		(t_pair){.str = "oldɯǝɾǝ un sǝ ǝʇsǝ", .size = sizeof("oldɯǝɾǝ un sǝ ǝʇsǝ")},
		(t_pair){.str = "⠞⠓⠊⠎⠀⠊⠎⠀⠁⠝⠀⠑⠭⠁⠍⠏⠇⠑", .size = sizeof("⠞⠓⠊⠎⠀⠊⠎⠀⠁⠝⠀⠑⠭⠁⠍⠏⠇⠑")},
		(t_pair){0}
	};

	t_data (*tests_func[])(const void*, size_t) = {test_stdout, test_stderr, test_badfd, test_file, NULL};
	t_data ret;

	int fd, i, j;

	printf("Tests from %s:\n", __func__);
	for (i = 0; tests[i].str != NULL; i++) {
		for (j = 0; tests_func[j] != NULL; j++) {
			ret = (tests_func[j])(tests[i].str, tests[i].size);

			if (ret.og_errno != ret.my_errno || ret.og_return != ret.my_return)
				fd = 2;
			else
				fd = 1;

			dprintf(fd, "%s test %d.%d: expected [errno: %2d, return: %2ld], "
			                         "received [errno: %2d, return: %2ld]\n",
					msg[fd - 1], i, j, ret.og_errno, ret.og_return, ret.my_errno, ret.my_return);
		}
	}
}
