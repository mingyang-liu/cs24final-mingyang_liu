# Makefile
# -g includes debugging info
all: bst
	./bst
 
bst: bst.cpp bst.h testbst.cpp
	g++ -std=c++11 -O0 -g bst.cpp testbst.cpp -o bst

clean:
	rm bst