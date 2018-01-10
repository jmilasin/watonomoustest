all: exec1

exec1: wato.cpp 
	g++ --std=c++11 -o wato.out wato.cpp