############################
#////This is a makefile ////#
############################

CC = gcc
EXE = exec
OBJ = main.o src/CharToBinary.o src/occurrence.o
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

clean:
	rm -rf $(OBJ)

mrproper : clean
	rm -rf $(EXE)