CC=g++
TARGET=bin\main.exe
SRC=$(wildcard src\main.cpp) \
		$(wildcard src\lib\*.cpp) \

.SILENT:all

all:
	$(CC) -o $(TARGET) $(SRC) && echo Build Successs && echo Executable in \bin\main.exe.

clean:
	rm $(TARGET)