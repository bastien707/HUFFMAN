#include <stdio.h>
#include <stdlib.h>
#include "include/CharToBinary.h"
#include "include/occurrence.h"




/**
 * @brief main who create a list with all occurence from a text file.
 * @note PART 2.1
 * @return int 
 */
int main(void)
{
    char *texte = "text/Alice.txt";
    Element *list = NULL;
    list = occurrence(texte);
    print_list(list);
    int a = list_size(list);
    printf("size :  %d\n", a);
    return 0;
}

/**
 * @brief main who read a text and convert it to bin
 * in an output file
 * @note PART 1.1 & 1.2
 * @return int 
 */
/*
int main()
{
    char *texte = "text/Alice.txt";
    ConvertTextToBin(texte);
    printf("%d\n", CharNumber(texte));
    printf("%d\n", CharNumber("text/Output.txt"));
    return 0;
}*/