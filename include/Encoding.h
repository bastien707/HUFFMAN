/*************************************************************************
 * \file   Encoding.h
 * \brief  Header that contain function who encode a text 
 *      
 * \date   November 2020
 ***********************************************************************/
#ifndef ENCODING
#define ENCODING

/**
 * \brief Function to write a char into his binary huffman form.
 * 
 * \param DIC the huffman dictionary.
 * \param c char want to convert.
 */
void write_huffman_text(FILE* DIC, char c);

/**
 * \brief Function to encode a whole text into huffman code.
 * 
 */
void encoding();

#endif //!ENCODING