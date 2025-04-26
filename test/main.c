#include "libasm.h"
#include "ft_tests.h"

char const* msg[] = {
	"\033[32m[SUCCESS]\033[0m",
	"\033[31m[FAIL]\033[0m"
};

int main(void)
{
	ft_strlen_test();
	ft_strcpy_test();
	ft_strcmp_test();
	ft_write_test();
	ft_read_test();
	//ft_strdup_test();
        return 0;
}
