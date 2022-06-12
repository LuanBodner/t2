hash:
	gcc -c hash.c
	gcc main.c hash.o -o main -lm
	./main 500

clean:
	rm *.o
	rm main
