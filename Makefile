NAME     := libasm.a
TEST     := ft_test.out

SRCS     := src/ft_strlen.s\
	    src/ft_strcpy.s
OBJS     := $(SRCS:.s=.o)

TESTS    := test/main.c\
	    test/ft_strlen_test.c
TOBJS    := $(TESTS:.c=.o)

AS       := nasm
ASFLAGS  := -f elf64 -O0 -gdwarf

CC       := cc
CFLAGS   := -Wall -Wextra -I include/ -L . -lasm
CPPGLAGS := -I .

AR       := ar
LFLAGS   := -c -r -s

all: $(NAME) $(TEST)
re: fclean all

$(NAME): $(OBJS) include/libasm.h
	$(AR) $(LFLAGS) $(NAME) $(OBJS)

$(TEST): $(TOBJS) include/ft_tests.h
	cc $(TOBJS) -I . -L . -lasm -o $(TEST)
	make execute_tests

execute_tests:
	./$(TEST)

%.o: %.s
	$(AS) $(ASFLAGS) $<

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST)

.SECONDARY: $(OBJS)
.PHONY: all clean fclean re bonus execute_tests
