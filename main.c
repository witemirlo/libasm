#include "libasm.h"
#include <stdio.h>

int main(void)
{
        printf("%d\n", ft_strlen("hi!"));
        printf("%d\n", ft_strlen(""));
        printf("%d\n", ft_strlen("\t\n\e\v"));
        return 0;
}
