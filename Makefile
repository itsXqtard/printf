  # the compiler: gcc for C program
  CC = gcc

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  #  -Wextra - errors on unused variables
  #  -Werror Make all warnings into errors.
  CFLAGS  = -g -Wall -Wextra -Werror -g3 -fsanitize=address
  # the build target executable:
  TARGET = my_printf

all: $(TARGET) 

$(TARGET): $(TARGET).o my_string.o print_specifiers.o
	$(CC) $(CFLAGS) $(TARGET).o  my_string.o print_specifiers.o -o $(TARGET)


my_mastermind.o: my_printf.c
	$(CC) $(CFLAGS) -c my_printf.c
my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c
print_specifiers.o: print_specifiers.c
	$(CC) $(CFLAGS) -c print_specifiers.c


clean:
	rm $(TARGET) *.o