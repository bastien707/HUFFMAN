#include <stdio.h>
#include <stdlib.h>
#include "../include/Encoding.h"

void write_huffman_text(FILE *DIC, char c)
{
    FILE *Encode = fopen("text/Encode.txt", "a"); // open an encode file (empty)
    int cur = 0;
    fseek(DIC, 0, SEEK_SET);
    if (Encode != NULL)
    {
        while (cur != c)                             // browse until finding the same char
        {
            cur = fgetc(DIC);
        }
        cur = fgetc(DIC);                            // go to the ':'
        do
        {                                            // write the array until the '\n'
            cur = fgetc(DIC);
            if (cur == 48 || cur == 49)
            {
                fputc(cur, Encode);
            }
        } while (cur == 48 || cur == 49);
    }
    else
    {
        printf("An error ocurred :/");
    }
    fclose(Encode);
}

void encoding()
{
    FILE *Dictionary, *Texte = NULL;
    Texte = fopen("text/Alice.txt", "r");           // open text file
    Dictionary = fopen("text/Dictionary.txt", "r"); // open an encode file (empty)
    int cur = 0;
    unsigned i = 0;

    if (Texte != NULL)
    {
        while (cur != EOF) // read char by char in the text file
        {
            cur = fgetc(Texte); // recover a char
            if (cur == EOF)
            {
                break;
            }
            write_huffman_text(Dictionary, cur);
            i++;
            if( i % 8 == 0){
                FILE* Encode = fopen("text/Encode.txt", "a");
                fputc('\n', Encode);
                fclose(Encode);
                i = 0;
            }
        }
    }
    else
    {
        printf("An error ocurred :/");
    }
    fclose(Texte);
    fclose(Dictionary);
}
