/*************************************************************************
 * \file   Occurrence.h
 * \brief  Header of the part that create a list 
 *         of all occurrence from a text file.
 * \date   November 2020
 ***********************************************************************/
#ifndef OCCURRENCE
#define OCCURRENCE

/**
 * @typedef struct Element
 * @brief Element of a list, it owns one pointer : next.
 * 
 */
typedef struct Element{
    char letter; /**< the letter contains by the Element*/
    int occ; /**< the occurrence (occ) data */
    struct Element* next; /**< the next Element*/
}Element;

/**
 * @brief Create an Element object
 * 
 * @note occ initialized at 1
 * @param letter the char to add in the new Element 
 * @return Element* 
 */
Element* create_Element(char letter);

/**
 * @brief  add one occurrence in the list if the letter exist, else,
 * we create an element at the beginning of the list
 * 
 * @note so it modify a list
 * @param letter the char to add in the new Element 
 * @param list list we modify,so need double pointer
 */
void add_occ(char letter, Element **list);

/**
 * @brief read text file and use add_occ to 
 * add letter by letter an occurence to the list of all occurrences
 * 
 * @param texte file in wich we read char by char
 * @return Element*, the list of all occurrences
 */
Element* occurrence(char* texte);

/**
 * @brief Function who return size of a list
 * 
 * @param l , list of Element
 * @return int, the size of the list
 */
int list_size(Element *l);

/**
 * @brief Function to print a list information of a list 
 * @note Print letter and number of occurrence
 * @param list, list of Element
 */
void print_list(Element* list);


#endif // !OCCURRENCE