CC=gcc
OBJS=main.o
TARGET=app.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(OBJS) : main.c
	$(CC) -c -o $@ $^
