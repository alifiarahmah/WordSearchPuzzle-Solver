CC=g++
TARGET=.\main.exe
SRC=$(wildcard main.cpp) \
		$(wildcard lib\*.cpp) \

.SILENT:all

all:
	$(CC) -o $(TARGET) $(SRC) && echo Build Successs && echo Executable in \bin\main.exe.

clean:
	rm $(TARGET)