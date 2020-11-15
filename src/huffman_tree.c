#include <stdio.h>
#include <stdlib.h>
#include "../include/huffman_tree.h"


Element *min_list(Element *list)
{
    if (list != NULL)
    {
        Element *min = list;
        Element *temp = list;
        while (temp->next != NULL)
        {
            if (temp->occ < min->occ)
            {
                min = temp;
            }
            temp = temp->next;
        }
        return min;
    }
    return NULL;
}

void list_remove_element(Element **list, Element* min)
{
    Element *temp = NULL;
    if ((*list) != NULL)
    {
        list_remove_element(&((*list)->next), min);
        if ((*list) == min)
        {
            temp = (*list);
            (*list) = (*list)->next;
            free(temp);
        }
    }
}

int main(void)
{
    char *texte = "../text/Alice.txt";
    Element *list = NULL;
    list = occurrence(texte);

    list_remove_element(&list,min_list(list));
    print_list(list);
    int b = list_size(list);
    printf("size :  %d\n", b);
    return 0;
}
