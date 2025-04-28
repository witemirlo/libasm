#ifndef FT_TESTS_H
# define FT_TESTS_H

# include <errno.h>
# include <fcntl.h> 
# include <stdbool.h> 
# include <stdint.h> 
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h> 

# include "libasm.h"

extern char const* msg[];

void	ft_strlen_test(void);
void	ft_strcpy_test(void);
void	ft_strcmp_test(void);
void	ft_write_test(void);
void	ft_read_test(void);
void	ft_strdup_test(void);

#endif
