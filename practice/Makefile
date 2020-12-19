all:
	gcc -c -o ./linkedlist/linkedlist.o ./linkedlist/linkedlist.c
	g++ -c -o hash_table_addressing.o hash_table_addressing.cpp
	g++ -o hash ./linkedlist/linkedlist.o hash_table_addressing.o

clean:
	rm hash hash_table_addressing.o
