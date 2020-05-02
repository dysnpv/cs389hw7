all: Run_driver

Run_driver: compile_driver execute_driver

compile_driver: converter.c driver.c
	g++ -std=c++17 -O3 -march=native -o driver.o -Wall -Wextra -pedantic *.c
	
execute_driver:
	./driver.o quotes.txt 1000

clean:
	rm -f *.o