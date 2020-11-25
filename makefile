############################
#////This is a makefile ////#
############################

CC = gcc
EXE = exec
OBJ = main.o src/CharToBinary.o src/occurrence.o src/huffman_tree.o src/dictionary.o
CFLAGS = -Wall -g  

all: $(EXE) clean

$(EXE) : $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $^

main.o : main.c
	$(CC) -o main.o -c main.c $(CFLAGS)

CharToBinary.o : src/CharToBinary.c
		$(CC) -o CharToBinary.o src/CharToBinary.c $(CFLAGS)

occurrence.o : src/occurrence.c
		$(CC) -o occurrence.o src/occurrence.c $(CFLAGS)

huffman_tree.o : src/huffman_tree.c
		$(CC) -o huffman_tree.o src/huffman_tree.c $(CFLAGS)

dictionary.o : src/dictionary.c
		$(CC) -o dictionary.o src/dictionary.c $(CFLAGS)
		
clean:
	rm -rf $(OBJ)

mrproper : clean
	rm -rf $(EXE)