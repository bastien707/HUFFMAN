#include <stdio.h>
#include <stdlib.h>
#include "../include/huffman_tree.h"


List_Node *min_list_node(List_Node *list_node)
{
    if (list_node != NULL)
    {
        List_Node *min_node = list_node;
        List_Node *temp = list_node;
        while (temp->next != NULL)
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

void list_remove_node(List_Node **list_node, List_Node *min_node){
    
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

Node* create_Node(List_Node* min1, List_Node* min2){
    printf("before\n");
    printf("min1111 %c\n", min1->data->letter);
    printf("min2222 %c\n", min2->data->letter);
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->left = min1->data;
    new_node->right = min2->data;
    new_node->occ = (min1->data->occ + min2->data->occ);
    new_node->letter = '\0'; //invisible letter
    printf("after\n");
    printf("min1111 %c\n", min1->data->letter);
    printf("min2222 %c\n", min2->data->letter);
    //printf("min1 : %d | min 2 : %d | newnode = %d\n", min1->data->occ, min2->data->occ, new_node->occ);
    //printf("min1 : %c | min 2 : %c | newnode = %d\n", min1->data->letter, min2->data->letter, new_node->occ);

    return new_node;
}

Node* create_node_from_element(Element* element){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->letter = element->letter;
    new_node->occ = element->occ;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

List_Node* create_list_node(Node* new_node){
    List_Node* new_list_n = (List_Node*)malloc(sizeof(List_Node));
    new_list_n->data = new_node;
    new_list_n->next = NULL;

    return new_list_n;
}

List_Node* create_list_node_from_element(Element* list){
    
    Node* new_n = create_node_from_element(list);
    List_Node* new_list_n = (List_Node*)malloc(sizeof(List_Node));
    new_list_n->data = new_n;
    new_list_n->next = NULL;
    
    return new_list_n;
}

List_Node* convert_elem_to_Node(Element* list){
    
    List_Node* list_node = create_list_node_from_element(list);
    List_Node* temp_liste = list_node;
    Element* temp = list->next;
    
    while(temp != NULL){
        List_Node* n_list_node = create_list_node_from_element(temp);
        while(temp_liste->next != NULL){
            temp_liste = temp_liste->next;
        }
        temp_liste->next = n_list_node;
        temp = temp->next;
    }
    return list_node;
}

 void End_Add_Node(List_Node** list_node,Node* NODE){

    List_Node* temp_list = create_list_node(NODE);
    temp_list->next = (*list_node);
    (*list_node) = temp_list;
 }


Node* huffman_tree(List_Node* list_node){
    List_Node *min1 = NULL;
    List_Node *min2 = NULL;
    Node* new_node = NULL;
    while(list_node->next != NULL){
        min1 = min_list_node(list_node);
        list_remove_node(&list_node, min1);
        min2 = min_list_node(list_node);
        list_remove_node(&list_node, min2);
        new_node = create_Node(min1,min2);
        End_Add_Node(&list_node, new_node);
    }
    return new_node;
}



int main(void){

    char *texte = "../text/Alice.txt";
    Element *list = NULL;
    list = occurrence(texte);
    List_Node* list_node = NULL;
    list_node = convert_elem_to_Node(list); 
    //Node* huffman = NULL;
    //huffman = huffman_tree(list_node);
    //printf("%d", huffman->occ);
    List_Node *min1,*min2 = NULL;
    Node* new_node = NULL;
    min1 = min_list_node(list_node);
    list_remove_node(&list_node, min1);
    min2 = min_list_node(list_node);
    list_remove_node(&list_node, min2);

    printf("min1111 %c\n", min1->data->letter);
    printf("min2222 %c\n", min2->data->letter);

    new_node = create_Node(min1,min2);
    End_Add_Node(&list_node, new_node); 
    
    List_Node* temp = list_node;
    int cpt = 0;
    while(temp->next != NULL){
        printf("%c %d\n", temp->data->letter, temp->data->occ);
        temp = temp->next;
        cpt++;
    }
    printf("%d", cpt);
    
    return 0;
}
