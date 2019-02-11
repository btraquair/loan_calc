CC = g++
CFLAGS = -O

loan_sim : main.o loan/loan.o
	$(CC) $(CFLAGS) -o loan_sim main.o loan/loan.o 

main.o : main.cpp
	$(CC) $(CFLAGS) -c main.cpp 

loan.o : loan/loan.cpp
	$(CC) $(CFLAGS) -c loan/loan.cpp

clean:
	rm -f core main.o
	rm -f core loan/loan.o
	rm -f core loan_sim.exe