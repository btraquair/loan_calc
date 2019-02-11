CC = g++
CFLAGS = -O

test0 : main.o loan/loan.o
	$(CC) $(CFLAGS) -o test0 main.o loan/loan.o 

main.o : main.cpp
	$(CC) $(CFLAGS) -c main.cpp 

loan.o : loan/loan.cpp
	$(CC) $(CFLAGS) -c loan/loan.cpp

clean:
	rm -f core main.o
	rm -f core loan/loan.o