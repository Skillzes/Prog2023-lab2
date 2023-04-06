IntVector.o: IntVector.c
    gcc -Wall -Werror -c IntVector.c -o IntVector.o
main.o: main.c
    gcc -Wall -Werror -c main.c -o main.o
IntVector: main.o IntVector.o
    gcc -Wall -Werror main.c IntVector.o -o IntVector
clean:
    rm -rf *.o