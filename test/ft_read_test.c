#include "ft_tests.h"

typedef struct s_pair {
	char*  str;
	size_t size;

} t_pair;

typedef struct s_data {
	int     my_errno;
	ssize_t my_return;
	char    my_buffer[BUFSIZ];
	int     og_errno;
	ssize_t og_return;
	char    og_buffer[BUFSIZ];
} t_data;

#define FILE_NAME ".tmp"
#define NUM 42

static bool check(t_data const* obj)
{
	if (obj->my_errno != obj->og_errno)
		return false;

	if (obj->my_return != obj->og_return)
		return false;

	if (strncmp(obj->my_buffer, obj->og_buffer, BUFSIZ) != 0)
		return false;

	return true;
}

static void create_file(void)
{
	const int random = open("/dev/random", O_RDONLY, 0);
	const int fd = open(FILE_NAME, O_CREAT | O_WRONLY, 0644);
	char      buffer[BUFSIZ];

	for (int i = 0; i < NUM; i++) {
		read(random, buffer, BUFSIZ);
		write(fd, buffer, BUFSIZ);
	}

	close(fd1);
}

static void test(t_data* obj, int fd1, int fd2, size_t size)
{
	errno = 0;
	obj->og_return = read(fd1, obj->og_buffer, BUFSIZ);
	obj->og_errno = errno;

	errno = 0;
	obj->my_return = read(fd1, obj->my_buffer, BUFSIZ);
	obj->my_errno = errno;
}

static bool test_file(size_t size)
{
	create_file();

	const int og_fd = open(FILE_NAME, O_RDONLY, 0);
	const int my_fd = open(FILE_NAME, O_RDONLY, 0);
	t_data    data = {0};
	bool      ret = true;

	while (true) {
		test(&data, og_fd, my_fd, size);
		if (!check(&data)) {
			ret = false;
			break;
		}
		if (data.my_return < 0)
			break;
	}
	close(og_fd);
	close(my_fd);
	unlink(FILE_NAME);
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

			if ()
				fd = 2;
			else
				fd = 1;

			dprintf(fd, "%s test %d.%d: expected [errno: %2d, return: %2ld], "
			                         "received [errno: %2d, return: %2ld]\n",
					msg[fd - 1], i, j, ret.og_errno, ret.og_return, ret.my_errno, ret.my_return);
		}
	}
}
