#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dictionary.h"

/// create a dictionary from an huffman tree
void HuffmanDictionary(Node *tree, char array[], int index)
{

    if (tree->left) // browse on the left side and add '0' to the array
    {
        array[index] = '0';
        HuffmanDictionary(tree->left, array, (index + 1));
    }

    if (tree->right) // browse on the right side and add '1' to the array
    {
        array[index] = '1';
        HuffmanDictionary(tree->right, array, (index + 1));
    }

    if ((tree->left == NULL) && (tree->right == NULL)) // if it's a leaf, then
    {
        WriteArray(array, index, tree); // We write in the dictionary the array
    }
}

/// Write an array in the dictionary
void WriteArray(char array[], int size, Node *tree)
{
    FILE *Dico = NULL;
    Dico = fopen("text/Dictionary.txt", "a"); // open Dico.txt and create it if it doesn't exist

    if (Dico != NULL)
    {
        fprintf(Dico, "%c:", tree->letter); // print letter at the beginning
        for (int i = 0; i < size; i++)
        {
            fputc(array[i], Dico); // print its corresponding binary array
        }
        fputc('\n', Dico); // add '\n' for the next one
    }
    else
    {
        printf("Error while opening Dictionary.\n");
    }
    fclose(Dico); // close the file
}

/// this function return the depth of any tree
int depth(Node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        int depth_left = depth(tree->left);
        int depth_right = depth(tree->right);
        if (depth_left > depth_right)
        {
            return 1 + depth_left;
        }
        else
        {
            return 1 + depth_right;
        }
    }
}
