CC := clang++ --std=c++11
CFLAGS :=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -I./include -Wall -g
TARGET := nomb
INCLUDE=-I./include 
# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^
%.o: %.cpp
	$(CC) -c $(INCLUDE) $<
clean:
	rm -rf $(TARGET) *.o
	
# For targets not based on file names
.PHONY: all clean
