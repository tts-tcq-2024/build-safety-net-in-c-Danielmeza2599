//Soundex, which is a system for encoding names into a phonetic representation. 
   // This is useful for comparing names that sound similar but may be spelled differently.


#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

//This function takes a character and returns its corresponding Soundex code
//Vowels (A, E, I, O, U) and letters H, W, Y return '0', as they do not contribute to the Soundex code
char getSoundexCode(char c) {
    c = toupper(c);
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}


//    This function generates the Soundex code for a given name.
    //Steps:
        //Takes the first letter of the name and converts it to uppercase.
        //Iterate over the rest of the name, obtaining the Soundex codes for each character.
        //Ignore '0' codes and consecutive repeated characters.
        //Fill with '0' if the Soundex code is less than 4 characters.
        //Ensure that the Soundex code ends with a null character ('0').
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }
    //validation is added if the input name is NULL or empty
    if (name == NULL || strlen(name) == 0) {
    strcpy(soundex, "0000");
    return;
    }
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
