#include <stdio.h>
#include <stdlib.h>
#include "../include/Huffman_tree.h"


List_Node *min_list_node(List_Node *list_node)
{
    if (list_node != NULL)
    {
        List_Node *min_node = list_node;
        List_Node *temp = list_node;
        while (temp != NULL) // goes to the next List_Node until the end
        {
            if (temp->data->occ < min_node->data->occ) // if we've found a List_Node min, we appoint it as the new minimum
            {
                min_node = temp;
            }
            temp = temp->next;
        }
        return min_node; // Once the list has been browse, we return the minimum
    }
    return NULL;
}

void list_remove_node(List_Node **list_node, List_Node *min_node)
{

    List_Node *temp = NULL;
    if ((*list_node) != NULL)
    {
        list_remove_node(&((*list_node)->next), min_node);
        if ((*list_node) == min_node)
        {
            temp = (*list_node);
            (*list_node) = (*list_node)->next;
            free(temp);
        }
    }
}

Node *create_Node(List_Node *min1, List_Node *min2)
{

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->occ = (min1->data->occ + min2->data->occ); // new node occurence is the sum of both minimum occ
    new_node->letter = '\0';                             //invisible letter

    new_node->left = min2->data;  
    new_node->right = min1->data; 

    return new_node;
}

Node *create_node_from_element(Element *element)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->letter = element->letter;
    new_node->occ = element->occ;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

List_Node *create_list_node(Node *new_node)
{
    List_Node *new_list_n = (List_Node *)malloc(sizeof(List_Node)); // memory allocation
    new_list_n->data = new_node;                                    // data of the List_Node is a Node
    new_list_n->next = NULL;

    return new_list_n;
}

List_Node *create_list_node_from_element(Element *list)
{
    if (list == NULL)
    {
        printf("From : create_list_node_from_element\nList of element is NULL, please retry with a no-NULL List.\n");
        return NULL;
    }
    Node *new_n = create_node_from_element(list);                   // recover first element and convert it into a node
    List_Node *new_list_n = (List_Node *)malloc(sizeof(List_Node)); // memory allocation
    new_list_n->data = new_n;                                       // fill the data ( who is a node) of the new List_Node
    new_list_n->next = NULL;

    return new_list_n;
}

List_Node *convert_elem_to_Node(Element *list)
{
    if (list == NULL)
    {
        printf("From : convert_elem_to_Node\nList of element is NULL, please retry with a no-NULL List.\n");
        return NULL;
    }

    List_Node *list_node = create_list_node_from_element(list); // create List_Node with a first element from list of element
    List_Node *temp_liste = list_node;
    Element *temp = list->next; // list->next avoid to get twice same node

    while (temp->next != NULL) // first while recover element by element and convert into Node until the end
    {
        List_Node *n_list_node = create_list_node_from_element(temp);
        while (temp_liste->next != NULL) // second while browse list_node until the end to add at the end the new node
        {
            temp_liste = temp_liste->next;
        }
        temp_liste->next = n_list_node;
        temp = temp->next;
    }
    return list_node; // return list of Liste_Node
}

void Add_node_beg(List_Node **list_node, Node *NODE)
{

    List_Node *temp_list = create_list_node(NODE); // create a List_Node with the new_node (NODE) in data
    temp_list->next = (*list_node);                // add the List_Node at the beginning of the list
    (*list_node) = temp_list;
}

void trees_log_parents_before_children(Node *tree)
{
    if (tree != NULL)
    {
        printf("%d\n", tree->occ); // log in perfix order
        trees_log_parents_before_children(tree->left);
        trees_log_parents_before_children(tree->right);
    }
}

Node *huffman_tree(List_Node *list_node)
{
    List_Node *min1, *min2 = NULL;
    Node *new_node = NULL;

    if (list_node == NULL)
    {
        printf("From : huffman_tree\nList_Node is NULL, please retry with a no-NULL List.\n");
        return NULL;
    }
    while (list_node->next != NULL) // while the list has more that 1 node we keep it up
    {
        min1 = min_list_node(list_node);    // return first minimum
        list_remove_node(&list_node, min1); // remove the first minimum from the list

        min2 = min_list_node(list_node);    // return second minimum
        list_remove_node(&list_node, min2); // remove the second minimum from the list

        new_node = create_Node(min1, min2); // create new node with both minimum
        Add_node_beg(&list_node, new_node); // add the new node in the list of List_Node
    }
    return new_node; // return the last node in the list that is the huffman tree
}
