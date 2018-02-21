all: main.o pw.o prime.o leg_symb.o 
	g++ -std=gnu++11 -O0 -Wall -Wextra -DCEMA main.o pw.o prime.o leg_symb.o -o main.exe
main.o: main.cpp func.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra -DCEMA main.cpp -o main.o
pw.o: pw.cpp
	g++ -c -std=gnu++11 -O0 -Wall -Wextra -DCEMA pw.cpp -o pw.o
prime.o: prime.cpp
	g++ -c -std=gnu++11 -O0 -Wall -Wextra -DCEMA prime.cpp -o prime.o
leg_symb.o: leg_symb.cpp func.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra -DCEMA leg_symb.cpp -o leg_symb.o
clean:
	rm -f *.o