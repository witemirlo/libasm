NAME     := libasm.a
TEST     := ft_test.out

SRCS     := src/ft_strlen.s\
	    src/ft_strcpy.s\
	    src/ft_strcmp.s\
	    src/ft_write.s\
	    src/ft_read.s\
	    src/ft_strdup.s
OBJS     := $(SRCS:.s=.o)

TESTS    := test/main.c\
	    test/ft_strlen_test.c\
	    test/ft_strcpy_test.c\
	    test/ft_strcmp_test.c\
	    test/ft_write_test.c\
	    test/ft_read_test.c\
	    test/ft_strdup_test.c
TOBJS    := $(TESTS:.c=.o)

AS       := nasm
ASFLAGS  := -f elf64 -O0 -gdwarf

CC       := gcc
LIB      := -L . -lasm
CFLAGS   := -Wall -Wextra -O0 -g3
CPPFLAGS := -I include/

AR       := ar
LFLAGS   := -c -r -s

all: $(NAME)
re: fclean all

$(NAME): $(OBJS) include/libasm.h
	$(AR) $(LFLAGS) $(NAME) $(OBJS)

$(TEST): $(TOBJS) include/ft_tests.h $(OBJS) include/libasm.h
	$(CC) $(TOBJS) -o $(TEST) $(LIB)

test: $(NAME) $(TEST) 
	./$(TEST)

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(TOBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST)

.SECONDARY: $(OBJS)
.PHONY: all clean fclean re bonus execute_tests
