#include <stdio.h>
#include <stdlib.h>
#include "include/Dictionary.h"

/**
 * @brief create the dictionary
 * @note PART 2.3
 * @return int 
 */
/*
int main(void)
{

    char *texte = "text/Alice.txt";
    Element *list = occurrence(texte);
    List_Node *list_node = convert_elem_to_Node(list);
    Node *huffman = huffman_tree(list_node);
    int index = 0;
    char array[depth(huffman)];
    HuffmanDictionary(huffman, array, index);

    return 0;
}
*/

/**
 * @brief create an huffman tree and display it with a log function
 * @note PART 2.2
 */
/*
int main(void)
{

    char *texte = "text/Alice.txt";
    Element *list = occurrence(texte);
    List_Node *list_node = convert_elem_to_Node(list);
    Node *huffman = NULL;
    huffman = huffman_tree(list_node);
    trees_log_parents_before_children(huffman);
    return 0;
}
*/
/**
 * @brief main who create a list with all occurence from a text file.
 * @note PART 2.1
 * @return int 
 */
/*
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
*/

/**
 * @brief main who read a text and convert it into bin
 * in an output file
 * @note PART 1.1 & 1.2
 * @return int 
 */

int main()
{
    char *texte = "text/Alice.txt";
    ConvertTextToBin(texte);
    printf("%d\n", CharNumber(texte));
    printf("%d\n", CharNumber("text/Output.txt"));
    return 0;
}