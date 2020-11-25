#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dictionary.h"

void huffman_dictionary(Node* tree, char **DictionaryArray, char array[], int index ){

    if(tree->left != NULL){
        array[index] = '0';
        huffman_dictionary(tree->left,DictionaryArray,array,(index+1));
    }
    
    if(tree->right != NULL){
        array[index] = '1';
        huffman_dictionary(tree->right,DictionaryArray,array,(index+1));
    }

    if((tree->left == NULL) && (tree->right == NULL))
    {
        array[index] = '\0';
        DictionaryArray[0] = (char*)malloc(sizeof(char)*(index+1));
        strcpy(DictionaryArray[0], array);
        printf("%c: %s\n",tree->letter, DictionaryArray[0]);

    }
}

int main(void)
{

    char *texte = "../text/Alice.txt";
    char *DictionaryArray = NULL;
    char array[3];
    int index = 0;
    Element *list = occurrence(texte);
    List_Node *list_node = convert_elem_to_Node(list);
    Node *huffman = NULL;
    huffman = huffman_tree(list_node);
    huffman_dictionary(huffman, &DictionaryArray, array, index);
    printf("%s", &DictionaryArray[0]);
    //trees_log_parents_before_children(huffman);

    return 0;
}