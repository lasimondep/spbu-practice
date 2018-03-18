OPT=g++ -c -std=gnu++11 -O0 -Wall -Wextra -DCEMA
all: main.o quaterni.o func.o
	g++ main.o quaterni.o func.o -o main.exe
main.o: main.cpp quaterni.h func.h
	$(OPT) main.cpp -o main.o
quaterni.o: quaterni.cpp quaterni.h func.h
	$(OPT) quaterni.cpp -o quaterni.o
func.o: func.cpp quaterni.h func.h
	$(OPT) func.cpp -o func.o
clean:
	rm -f *.o