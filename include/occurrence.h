#ifndef Occurrence

typedef struct Element{
    char letter;
    int occ;
    struct Element* next;
}Element;

Element* occurrence(char* texte);

Element* create_Element(char letter);

void parcours_occ_liste(char letter, Element** list);

int isEmpty(Element* list);

int list_size(Element *l);

void print_list(Element* list);


#endif