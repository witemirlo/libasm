#ifndef LIBASM_H
# define LIBASM_H
# include <sys/types.h>

size_t	ft_strlen(const char *s);

char	*strcpy(char *restrict dst, const char *restrict src);

int	strcmp(const char *s1, const char *s2);

ssize_t	write(int fd, const void *buf, size_t count);

ssize_t	read(int fd, void *buf, size_t count);

char	*strdup(const char *s);

#endif
