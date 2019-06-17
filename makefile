CC = g++
CFLAGS = -std=c++14

all: command_manager.o course_manager.o course.o main.o
	$(CC) $(CFLAGS) command_manager.o course_manager.o course.o main.o -o cmsys

main.o: src/main.cpp
	$(CC) $(CFLAGS) -Isrc/command/ -Isrc/course/ -c src/main.cpp

command_manager.o: src/command/command_manager.cpp src/command/command_manager.h
	$(CC) $(CFLAGS) -Isrc/course/ -c src/command/command_manager.cpp

course_manager.o: src/course/course_manager.cpp src/course/course_manager.h
	$(CC) $(CFLAGS) -c src/course/course_manager.cpp

course.o: src/course/course.cpp src/course/course.h
	$(CC) $(CFLAGS) -c src/course/course.cpp

clean:
	rm -rf *.o cmsys