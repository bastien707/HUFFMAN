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
        cur = fgetc(DIC);                            // go to ':'
        do
        {      
            cur = fgetc(DIC);                        // write the array until the '\n'
            if (cur != '\n' && cur != ':')
            {
                fputc(cur, Encode);
            }
            
        } while (cur != '\n');
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
    Texte = fopen("text/Input.txt", "r");           // open text file
    Dictionary = fopen("text/Dictionary.txt", "r"); // open an encode file (empty)
    int cur = 0;

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
        }
    }
    else
    {
        printf("An error ocurred :/");
    }
    fclose(Texte);
    fclose(Dictionary);
}
