hash:
	gcc -c hash.c
	gcc main.c hash.o -o main -lm

clean:
	rm -f *.o
	rm -f main
