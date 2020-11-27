/*************************************************************************
 * \file   Dictionary.h
 * \brief  Header of the part that create an huffman dictionary 
 *      
 * \date   November 2020
 ***********************************************************************/
#ifndef DICTIONARY
#define DICTIONARY

#include "Huffman_tree.h"

/**
 * @brief create a dictionary from an huffman tree
 * 
 * @param tree a pointer to an huffman tree 
 * @param array array that recover the path to a char 
 * @param index index for the array
 */
extern void HuffmanDictionary(Node* tree, char array[], int index);

/**
 * @brief Write an array in the dictionary
 * 
 * @param array array that contain a path to the char
 * @param size size of the array
 * @param tree a pointer to a tree
 */
 extern void WriteArray(char array[], int size, Node* tree);

/**
 * @brief this function return the depth of any tree
 * 
 * @param tree a pointer to a tree
 * @return depth of the tree
 */
extern unsigned int depth(Node* tree);

#endif // !DICTIONARY