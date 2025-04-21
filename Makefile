NAME     := libasm.a
TEST     := test.out

SRCS     := src/ft_strlen.s
OBJS     := $(SRCS:.s=.o)

AS       := nasm
ASFLAGS  := -f elf64 -O0 -gdwarf

AR       := ar
LFLAGS   := -c -r -s

all: $(NAME) $(TEST)
re: fclean all

$(NAME): $(OBJS) libasm.h
	$(AR) $(LFLAGS) $(NAME) $(OBJS)

$(TEST): main.c
	cc main.c -I . -L . -lasm -o $(TEST)

%.o: %.s
	$(AS) $(ASFLAGS) $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST)

.SECONDARY: $(OBJS)
.PHONY: all clean fclean re bonus