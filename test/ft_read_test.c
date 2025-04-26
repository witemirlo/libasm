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
	const int fd = open(FILE_NAME, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	char      buffer[BUFSIZ];

	for (int i = 0; i < NUM; i++) {
		read(random, buffer, BUFSIZ);
		write(fd, buffer, BUFSIZ);
	}

	close(fd);
	close(random);
}

static void test(t_data* obj, int fd1, int fd2, size_t size)
{
	errno = 0;
	obj->og_return = read(fd1, obj->og_buffer, size);
	obj->og_errno = errno;

	errno = 0;
	obj->my_return = ft_read(fd2, obj->my_buffer, size);
	obj->my_errno = errno;
}

static void test_file(size_t size, int n)
{
	create_file();

	const int og_fd = open(FILE_NAME, O_RDONLY, 0);
	const int my_fd = open(FILE_NAME, O_RDONLY, 0);
	t_data    data = {0};
	int       fd = 1;

	while (true) {
		test(&data, og_fd, my_fd, size);
		if (!check(&data)) {
			fd = 2;
			break;
		}
		if (data.my_return <= 0)
			break;
	}

	close(og_fd);
	close(my_fd);
	unlink(FILE_NAME);

	dprintf(fd, "%s test %d: expected [errno: %2d, return: %2ld], "
			       "received [errno: %2d, return: %2ld]\n",
			msg[fd - 1], n,
			data.og_errno, data.og_return,
			data.my_errno, data.my_return);
}

static void test_file_1(int n)
{
	test_file(1, n);
}

static void test_file_10(int n)
{
	test_file(10, n);
}

static void test_file_100(int n)
{
	test_file(100, n);
}

static void test_file_1000(int n)
{
	test_file(1000, n);
}

static void test_empty(int n)
{
	const int og_fd = open(FILE_NAME"1", O_CREAT | O_TRUNC | O_RDONLY, 0);
	const int my_fd = open(FILE_NAME"2", O_CREAT | O_TRUNC | O_RDONLY, 0);
	t_data    data = {0};
	int       fd = 1;

	test(&data, og_fd, my_fd, 42);
	if (!check(&data))
		fd = 2;

	close(og_fd);
	close(my_fd);
	unlink(FILE_NAME"1");
	unlink(FILE_NAME"2");

	dprintf(fd, "%s test %d: expected [errno: %2d, return: %2ld], "
			       "received [errno: %2d, return: %2ld]\n",
			msg[fd - 1], n,
			data.og_errno, data.og_return,
			data.my_errno, data.my_return);
}

static void test_bad_size(int n)
{
	create_file();
	const int og_fd = open(FILE_NAME, O_RDONLY, 0);
	const int my_fd = open(FILE_NAME, O_RDONLY, 0);
	t_data    data = {0};
	int       fd = 1;

	test(&data, og_fd, my_fd, -1);
	if (!check(&data))
		fd = 2;

	close(og_fd);
	close(my_fd);
	unlink(FILE_NAME);

	dprintf(fd, "%s test %d: expected [errno: %2d, return: %2ld], "
			       "received [errno: %2d, return: %2ld]\n",
			msg[fd - 1], n,
			data.og_errno, data.og_return,
			data.my_errno, data.my_return);
}

void ft_read_test(void)
{
	void (*tests_func[])(int) = {test_file_1, test_file_10, test_file_100, test_file_1000, test_empty, test_bad_size, NULL};

	int i;

	printf("Tests from %s:\n", __func__);
	for (i = 0; tests_func[i] != NULL; i++) {
		tests_func[i](i);
	}
}
