#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/Dictionary.h"
#include "include/Encoding.h"


int main(){

    double time_spent = 0.0;
    clock_t begin = clock();

    char *texte = "text/Input.txt";
    int index = 0;
    
    ConvertTextToBin(texte);
    Element *list = occurrence(texte);
    print_list(list);
    List_Node *list_node = convert_elem_to_Node(list);
    
    
    Node *huffman = huffman_tree(list_node);
    char *array = malloc(sizeof(char)* depth(huffman));
    HuffmanDictionary(huffman, array, index);
    free(array);
    encoding();

    clock_t end = clock();
    time_spent += (double)(end - begin)/CLOCKS_PER_SEC;
    printf("\nseconds : %fs\n", time_spent);

    return 0;

}
