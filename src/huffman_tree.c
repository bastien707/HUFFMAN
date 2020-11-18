#include <stdio.h>
#include <stdlib.h>
#include "../include/huffman_tree.h"

List_Node *min_list_node(List_Node *list_node)
{
    if (list_node != NULL)
    {
        List_Node *min_node = list_node;
        List_Node *temp = list_node;
        while (temp != NULL)
        {
            if (temp->data->occ < min_node->data->occ)
            {
                min_node = temp;
            }
            temp = temp->next;
        }
        return min_node;
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

Node *create_Node(int min1, int min2)
{

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->occ = (min1 + min2);
    new_node->letter = '/'; //invisible letter

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
    List_Node *new_list_n = (List_Node *)malloc(sizeof(List_Node));
    new_list_n->data = new_node;
    new_list_n->next = NULL;

    return new_list_n;
}

List_Node *create_list_node_from_element(Element *list)
{

    Node *new_n = create_node_from_element(list);
    List_Node *new_list_n = (List_Node *)malloc(sizeof(List_Node));
    new_list_n->data = new_n;
    new_list_n->next = NULL;

    return new_list_n;
}

List_Node *convert_elem_to_Node(Element *list)
{

    List_Node *list_node = create_list_node_from_element(list);
    List_Node *temp_liste = list_node;
    Element *temp = list->next;

    while (temp->next != NULL) // avoid to get twice equal node
    {
        List_Node *n_list_node = create_list_node_from_element(temp);
        while (temp_liste->next != NULL)
        {
            temp_liste = temp_liste->next;
        }
        temp_liste->next = n_list_node;
        temp = temp->next;
    }
    return list_node;
}

void Add_node_beg(List_Node **list_node, Node *NODE)
{

    List_Node *temp_list = create_list_node(NODE);
    temp_list->next = (*list_node);
    (*list_node) = temp_list;
}

void trees_log_parents_after_children(Node *huffman)
{
    if (huffman != NULL)
    {

        printf("%d\n", huffman->occ);
        trees_log_parents_after_children(huffman->left);
        trees_log_parents_after_children(huffman->right);
    }
}

Node *huffman_tree(List_Node *list_node)
{
    List_Node *min1, *min2 = NULL;
    Node *new_node = NULL;

    while (list_node->next != NULL)
    {
        min1 = min_list_node(list_node);
        list_remove_node(&list_node, min1);
        printf("min1 : %d\n", min1->data->occ);
        min2 = min_list_node(list_node);
        list_remove_node(&list_node, min2);
        printf("min2 : %d\n", min2->data->occ);
        
        new_node = create_Node(min1->data->occ, min2->data->occ);
         
        new_node->left = min1->data;
        new_node->right = min2->data;
        
        printf("nn %d nl %d nr %d\n", new_node->occ, new_node->left->occ, new_node->right->occ);
        Add_node_beg(&list_node, new_node);
        
        printf("START\n");
        List_Node *temp = list_node;
        while (temp != NULL)
        {
            printf("%c %d\n", temp->data->letter, temp->data->occ);
            temp = temp->next;
        }
        printf("END\n");

    }

    return new_node;
}


int main(void)
{

    char *texte = "../text/Alice.txt";
    Element *list = occurrence(texte);
    List_Node *list_node = convert_elem_to_Node(list);
    /*List_Node* temp = list_node;
    int cpt = 0;
    while(temp != NULL){
        printf("%c %d\n", temp->data->letter, temp->data->occ);
        temp = temp->next;
        cpt++;
    }*/


    Node *huffman = NULL;
    huffman = huffman_tree(list_node);
    trees_log_parents_after_children(huffman);

    /*
    List_Node* temp = list_node;
    int cpt = 0;
    while(temp->next != NULL){
        printf("%c %d\n", temp->data->letter, temp->data->occ);
        temp = temp->next;
        cpt++;
    }

    printf("cpt = %d\n", cpt);
    */

    return 0;
}
