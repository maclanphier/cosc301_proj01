# Makefile template for project 1

CC = clang
CFLAGS = -g -Wall
# main executable file first
TARGET = proj01
# object files next
OBJS = main.o list.o
# header files next
DEPS = list.h
.PHONY : clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.c.o: $(DEPS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET) *~

