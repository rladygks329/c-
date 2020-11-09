CC=g++
TARGET=main.out
OBJS=main.o BST.o

all: $(TARGET)

clean:
	rm *.o
	rm $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: BST.h main.cpp
BST.o: BST.h BST.cpp
