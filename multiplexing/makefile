CXX = g++
INC_DIR = ../include
SRC_DIR = ../src
LIBS = 
CXXFLAGS = -Wall -std=c++17 -g -I $(INC_DIR) -I .

TARGET = main
PROGS =	main\
	main.o\
	
all:$(SRC_DIR)/help.o $(PROGS) 

$(SRC_DIR)/help.o:$(SRC_DIR)/help.cpp $(INC_DIR)/help.h
	$(CXX) $(CXXFLAGS) -c -o $(SRC_DIR)/help.o $(SRC_DIR)/help.cpp

main:main.o
	$(CXX) $(CXXFLAGS)  -o main main.cpp $(SRC_DIR)/help.o $(LIBS)

main.o:main.cpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp










clean: 
	rm $(TARGET) *.o