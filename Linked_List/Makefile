CC=gcc
TARGET=app.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

linkedList.o: linkedList.c
	$(CC) -c -o $@ $^

main.o: main.c
	$(CC) -c -o $@ $^

$(TARGET): main.o linkedList.o
	$(CC) -o $(TARGET) main.o linkedList.o
