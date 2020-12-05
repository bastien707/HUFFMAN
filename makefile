############################
#////This is a makefile ////#
############################

CC = gcc
EXE = exec
OBJ = main.o src/CharToBinary.o src/Occurrence.o src/Huffman_tree.o src/Dictionary.o src/Encoding.o
CFLAGS = -Wall -g  

all: $(EXE) clean

$(EXE) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o : main.c
	$(CC) -o $@ -c $< $(CFLAGS)

CharToBinary.o : src/CharToBinary.c
		$(CC) -o $@ $< $(CFLAGS)

Occurrence.o : src/Occurrence.c
		$(CC) -o $@ $< $(CFLAGS)

Huffman_tree.o : src/Huffman_tree.c
		$(CC) -o $@ $< $(CFLAGS)

Dictionary.o : src/Dictionary.c
		$(CC) -o $@ $< $(CFLAGS)

Encoding.o : src/Encoding.c
		$(CC) -o $@ $< $(CFLAGS)
		
clean:
	rm -rf $(OBJ) text/Dictionary.txt text/Encode.txt text/Output.txt

mrproper : clean
	rm -rf $(EXE)

