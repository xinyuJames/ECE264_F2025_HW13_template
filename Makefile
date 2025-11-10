# Compiler settings
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c11 -g $(WARNING) $(ERROR)

# Source and object files
SRCS = main.c hw13.c
OBJS = $(SRCS:%.c=%.o)

# Executable name
hw13: $(OBJS)
	$(GCC) $(OBJS) -o hw13

# Rule for compiling .c files to .o
%.o: %.c
	$(GCC) -c $< -o $@

# Test
memory: hw13
	valgrind --leak-check=full ./hw13 inputs/input5.txt

clean:
	rm -f hw13 *.o *.txt output*

test%: hw13
	./hw13 inputs/input$*.txt > output$*.txt
	diff output$*.txt expected/expected$*.txt

testall: test1 test2 test3 test4 test5 test6 test7 test8 test9

.PHONY: all testall memory clean




