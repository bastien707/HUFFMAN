#ifndef dictionary

#include "huffman_tree.h"

/// create a dictionary from an huffman tree
void HuffmanDictionary(Node* root, char arr[], int top);

/// this function return the depth of any tree
int depth(Node* tree);

/// Write an array in the dictionary
void WriteArray(char array[], int size, Node* tree);

#endif