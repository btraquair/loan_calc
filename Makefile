test0 : main.o
	g++ -L/usr/include/boost main.o -o test0

main.o : main.cpp
	g++ -I /usr/include/boost main.cpp -o main.o