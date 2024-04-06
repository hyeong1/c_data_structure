CC=gcc
OBJS=main.o bst.o
TARGET=app.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: bst.h main.c
bst.o: bst.h bst.c
