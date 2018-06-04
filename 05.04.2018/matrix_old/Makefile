OPT=g++ -c -std=gnu++11 -O0 -Wall -Wextra
all: main.o matrix.o
	g++ main.o matrix.o -o main.exe
main.o: main.cpp matrix.h
	$(OPT) main.cpp -o main.o
matrix.o: matrix.cpp matrix.h
	$(OPT) matrix.cpp -o matrix.o
clean:
	rm -f *.o