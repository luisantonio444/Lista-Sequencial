# Makefile para compilar e testar a lista sequencial

CC = gcc
CFLAGS = -Wall -g
TARGET = lista_sequencial

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
	rm -f *.o
