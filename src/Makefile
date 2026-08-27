CC = gcc
TARGET = app
SOURCES = main.c student_ops.c file_ops.c utils.c

all:
	$(CC) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe

run: all
	./$(TARGET)