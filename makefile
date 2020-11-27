############################
#////This is a makefile ////#
############################

CC = gcc
EXE = exec
OBJ = main.o src/CharToBinary.o src/Occurrence.o src/Huffman_tree.o src/Dictionary.o
CFLAGS = -Wall -g  

all: $(EXE) clean

$(EXE) : $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $^

main.o : main.c
	$(CC) -o main.o -c main.c $(CFLAGS)

CharToBinary.o : src/CharToBinary.c
		$(CC) -o CharToBinary.o src/CharToBinary.c $(CFLAGS)

Occurrence.o : src/Occurrence.c
		$(CC) -o Occurrence.o src/Occurrence.c $(CFLAGS)

Huffman_tree.o : src/Huffman_tree.c
		$(CC) -o Huffman_tree.o src/Huffman_tree.c $(CFLAGS)

Dictionary.o : src/Dictionary.c
		$(CC) -o Dictionary.o src/Dictionary.c $(CFLAGS)
		
clean:
	rm -rf $(OBJ)

mrproper : clean
	rm -rf $(EXE)