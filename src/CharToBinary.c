#include <stdio.h>
#include <stdlib.h>
#include "../include/CharToBinary.h"

char *CharToBinary(char c)
{
    int dividend = c;
    int quotient, remainder, i = 0;
    char temp[8] = {0};
    char *bin = malloc(8 * sizeof(char));

    do // pick the remainder and put on an array
    {
        quotient = dividend / 2;
        remainder = dividend % (2);
        dividend = quotient;
        temp[i] = remainder;
        i++;
    } while (quotient != 0);

    i = 0; // re-use of i variable
    for (int u = 7; u >= 0; u--) // reverse an array
    {
        bin[i] = temp[u];
        i++;
    }
    return bin; // binary array
}

void printBinArray(char *array)
{
    for (int u = 0; u < 8; u++)
    {
        printf("%d", array[u]);
    }
}

void WriteAnArray(FILE *file, char *array)
{
    if (file != NULL)
    {
        for (int i = 0; i < 8; i++)
        {
            fprintf(file, "%d", array[i]); //print numbers in the output file
        }
    }
}

void ConvertTextToBin(char* texte)
{
    FILE *OutPut, *Texte = NULL;
    Texte = fopen(texte, "r"); // open texte file
    OutPut = fopen("text/Output.txt", "w"); // open output file (empty)
    int c = 0;
    int i = 0;

    if (Texte != NULL)
    {
        while (c != EOF) // read char by char in the text file
        {
            c = fgetc(Texte); // recover a char 
            if (c == EOF) // avoiding to write EOF at the end
            {
                break;
            }
            char *p = CharToBinary(c); // convert char to bin
            WriteAnArray(OutPut, p); // wrtie bin in output file
            i++;
            if (i % 8 == 0) // back to the line every 64 bits
            {
                fputc('\n', OutPut);
            }
            free(p); // memory leak cause 
        }
    }
    else
    {
        printf("An error ocurred :/");
    }
    fclose(Texte);
    fclose(OutPut);
}

int CharNumber(char *texte)
{
    FILE *Texte = NULL;
    Texte = fopen(texte, "r");
    int c = 0, i = 0;

    if (Texte != NULL)
    {
        while (c != EOF)
        {
            c = fgetc(Texte);
            if (c != '\n')
                i++;
        }
    }
    fclose(Texte);
    return i - 1; // -EOF
}

