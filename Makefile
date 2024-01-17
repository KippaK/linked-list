
all:
	g++ main.cpp -o test

clean:
	rm test

comperr: 
	g++ main.cpp -o test
	rm test
