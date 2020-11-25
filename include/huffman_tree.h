#ifndef Huffman_tree

#include "occurrence.h"
#include "CharToBinary.h"

/**
 * @brief struct used to create a Node
 * 
 */
typedef struct Node
{
    int occ;
    char letter;
    struct Node *left;
    struct Node *right;
} Node;

/**
 * @brief Struct used to create list of List_Node
 * 
 */
typedef struct List_Node
{
    struct List_Node *next;
    Node *data;
} List_Node;

/// return minimum from List_Node
List_Node *min_list_node(List_Node *list_node);

/// remove a List_Node element (in particular the minimum)
void list_remove_node(List_Node **list_node, List_Node *min_node);

/// create a node with an occurence value equal to sum of two minimum List_Node
Node *create_Node(List_Node *min1, List_Node *min2);

/// return a node that has been convert from an element
Node *create_node_from_element(Element *element);

/// create a List_Node with a Node in parameter
List_Node *create_list_node(Node *new_node);

/// create List_Node with first element is a List_Node element
List_Node *create_list_node_from_element(Element *list);

/// create a List of Liste_Node from List of Element
List_Node *convert_elem_to_Node(Element *list);

/// Add List_Node at the beginning of a List_Node List
void Add_node_beg(List_Node **list_node, Node *NODE);

/// used to print a tree in prefix order
void trees_log_parents_before_children(Node *tree);

/// create an huffman tree
Node *huffman_tree(List_Node *list_node);

#endif