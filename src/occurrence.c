#include <stdio.h>
#include <stdlib.h>
#include "../include/occurrence.h"



/**
 * @brief Create a Element object
 * 
 * @param letter 
 * @return Element* 
 */

Element *create_Element(char letter)
{
    Element *n_e = malloc(sizeof(Element));
    n_e->letter = letter;
    n_e->occ = 1;
    n_e->next = NULL;

    return n_e;
}



/**
 * @brief  add one occurrence in the list if the letter exist, else,
 * we create an element at the beginning of the list
 * @note so it modify a list
 * @param letter 
 * @param list 
 */

void add_occ(char letter, Element **list)
{
    if ((*list) != NULL)
    {
        Element *temp = (*list);
        int counter = 0;
        while (temp->next != NULL)
        {
            if (temp->letter == letter) // if letter are equal
            {
                temp->occ += 1; // just add an occurrence
                counter++;
            }
            temp = temp->next;
        }
        if (counter == 0)
        {                                          // if the counter = 0 it mean that the letter is not in the list
            Element *n_e = create_Element(letter); // so we create a new element in a list
            n_e->next = (*list);
            (*list) = n_e; // at the begginning
        }
    }
}




/**
 * @brief read text file and use add_occ to 
 * add letter by letter an occurence
 * @param texte 
 * @return Element* 
 */

Element *occurrence(char *texte)
{

    FILE *Texte = NULL;
    Texte = fopen(texte, "r"); // open texte file
    Element *list = NULL;
    int c = 0;
    if (Texte != NULL)
    {
        while (c != EOF) // read char by char in the text file
        {
            c = fgetc(Texte); // recover a char
            if (c == EOF)     // avoiding to write EOF at the end
            {
                break;
            }
            if ((list) == NULL) // if the list is NULL we create it, 
            {
                list = create_Element(c);
            }
            if(c != '\n'){ // avoid to add the '\n' occurrence
                add_occ(c, &list);
            }
        }
    }
    else if (Texte == NULL)
    {
        printf("An error occured :/\n");
    }
    fclose(Texte);
    return list;
}




/**
 * @brief return size of a list, but -1 to 
 * avoid an EOF char
 * 
 * @param l 
 * @return int 
 */

int list_size(Element *l)
{
    if (l == NULL)
        return -1; // -1 avoid false count instead of 0
    else
    {
        return (1 + list_size(l->next));
    }
}


/**
 * @brief print a list while temp->next != NULL
 * @note print letter and number of occurrence
 * @param list 
 */

void print_list(Element *list)
{
    Element *temp = list;
    while (temp->next != NULL)
    {
        printf("%d  %c\n", temp->occ, temp->letter);
        temp = temp->next;
    }
}

