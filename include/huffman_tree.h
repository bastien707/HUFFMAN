#ifndef Huffman_tree

#include "occurrence.h"
#include "CharToBinary.h"

typedef struct Node{
    int occ;
    char letter;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct List_Node{
    struct List_Node* next;
    Node* data;
}List_Node;

List_Node* min_list_node(List_Node *list_node); 

void list_remove_node(List_Node **list_node, List_Node *min_node);

List_Node* convert_elem_to_Node(Element* list);

Node* create_node_from_element(Element* element);

List_Node* create_list_node_from_element(Element* list);

Node* huffman_tree(List_Node* list_node);

Node* create_Node(List_Node* min1, List_Node* min2);

List_Node* create_list_node(Node* new_node);


#endif