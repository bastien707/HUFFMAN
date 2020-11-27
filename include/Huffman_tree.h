/*************************************************************************
 * \file   Huffman_tree.h
 * \brief  Header of the part that create an huffman dictionary 
 *      
 * \date   November 2020
 ***********************************************************************/
#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

#include "Occurrence.h"
#include "CharToBinary.h"

/**
 * @typedef struct Node
 * @brief a Node is composed by two pointers : left and right
 * 
 */
typedef struct Node
{
    int occ;            /**< the occurrence (occ) data */
    char letter;        /**< the letter contains by the Element*/
    struct Node *left;  /**< left child */
    struct Node *right; /**< right child */
} Node;

/**
 * @typedef struct List_Node
 * @brief a List_Node is composed by one Node and a pointer : next
 * 
 */
typedef struct List_Node
{
    struct List_Node *next; /**< the next List_Node*/
    Node *data;             /**< the data is a Node*/
} List_Node;

/**
 * @brief Function to find minimum from a List_Node List
 * 
 * @param list_node a List_Node that contain Node
 * @return List_Node* the minimum occurrence List_Node 
 */
List_Node *min_list_node(List_Node *list_node);

/**
 * @brief Function to remove a List_Node 
 * @note used to remove the minimum 
 * @param list_node a List_Node that contain Node
 * @param min_node a List_Node that contain the minimum Node
 */
void list_remove_node(List_Node **list_node, List_Node *min_node);

/**
 * @brief Function to create a node with an occurence value equal 
 * to sum of two minimum List_Node occurrences
 * 
 * @param min1 a List_Node that contain the first minimum Node
 * @param min2 a List_Node that contain the second minimum Node
 * @return Node* the new Node.
 */
Node *create_Node(List_Node *min1, List_Node *min2);

/**
 * @brief Function to create a node that has been converted from an element
 * 
 * @param element first element to be converted
 * @return Node* the element that has been converted into a Node
 */
Node *create_node_from_element(Element *element);

/**
 * @brief Function to create a List_Node with a Node in parameter
 * 
 * @param new_node a Node pointer
 * @return List_Node* a list with a Node data
 */
List_Node *create_list_node(Node *new_node);

/**
 * @brief Function to create List_Node with first element is a List_Node element
 * 
 * @param list first element of the list
 * @return List_Node* the element that has been converted into a List_Node
 */
List_Node *create_list_node_from_element(Element *list);

/**
 * @brief Function to create a List of Liste_Node from List of Element
 * 
 * @param list a list of element 
 * @return List_Node* the converted list into List_Node
 */
List_Node *convert_elem_to_Node(Element *list);

/**
 * @brief Function to add List_Node at the beginning of a List_Node List
 * 
 * @param list_node a List_Node that contain Node
 * @param NODE a Node that will become the data of the list_node 
 */
void Add_node_beg(List_Node **list_node, Node *NODE);

/**
 * @brief Function used to print a tree in prefix order
 * 
 * @param tree a non NULL tree
 */
void trees_log_parents_before_children(Node *tree);

/**
 * @brief Function to create an huffman tree
 * 
 * @param list_node List that contain all character and their own occurrence
 * @return Node* the huffman tree
 */
Node *huffman_tree(List_Node *list_node);

#endif // !HUFFMAN_TREE