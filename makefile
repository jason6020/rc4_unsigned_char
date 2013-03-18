main:main.o rc4.o
	gcc -o main main.o rc4.o
main.o:main.c rc4.h
	gcc -c main.c
rc4.o:rc4.c rc4.h
	gcc -c rc4.c
clean:
	rm *.o main
