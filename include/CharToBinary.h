/*********************************************************************
 * \file   ChatToBinary.h
 * \brief  Header of the part that convert text file to its binary form
 *
 * \date   November 2020
 *********************************************************************/
#ifndef CHARTOBINARY
#define CHARTOBINARY

/**
 * \brief convert a char to his binary form
 * 
 * \param c char, one char from the text file
 * \return binary array
 */
char* CharToBinary(char c);

/**
 * \brief it print an array only 8 bits array
 * 
 * \param array 
 */
void printBinArray(char* array);

/**
 * \brief this function write an array in a file.txt
 * 
 * \note it only recover array of 8 bits
 * \param file file in wich we wanna write 
 * \param array array of size 7 (0,1,2,3,4,5,6,7)
 */
void WriteAnArray(FILE* file, char* array);

/**
 * \brief write the entire text file in binary
 * 
 * \param texte any text file (no NULL text)
 */
void ConvertTextToBin(char* texte);

/**
 * @brief Function to count number of character in a file
 * 
 * @param texte 
 * @return int number of character
 */
int CharNumber(char* texte);

#endif // !CHARTOBINARY