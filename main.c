#include <stdio.h>
#include <stdlib.h>
#include "include/CharToBinary.h"

int main()
{
    char *texte = "text/Alice.txt";
    ConvertTextToBin(texte);
    printf("%d\n", CharNumber(texte));
    printf("%d\n", CharNumber("text/Output.txt"));
    return 0;
}