CC=gcc
OBJS=main.o queue.o
TARGET=app.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: queue.h main.c
queue.o: queue.h queue.c
