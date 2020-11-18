#ifndef Huffman_tree

#include "occurrence.h"
#include "CharToBinary.h"

typedef struct Node{
    int freq;
    char lettter;
    struct Node* left;
    struct Node* right;
}Node;

Element* min_list(Element *list); 
void list_remove_element(Element **list, Element *min);

#endif