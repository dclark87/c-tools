/* strings_arrays.c
 *
 * Author: Daniel Clark, 2016
 */

// Includes
#include "../include/strings_arrays.h"


/**
 * Reverse c-style strings in place
 */
void reverse(char * str)
{
    char * end = str;
    char tmp;
    if (str) {
        // Increment end index to end of string
        while (* end) {
            ++end;
        }
        // Go back one char
        --end;
        // While str ptr val < end ptr val
        while (str < end) {
            // Store str pointer in tmp
            tmp = * str;
            // Set value at str ptr to val at end and increment str ptr
            *str++ = * end;
            // Store rest of str back in end ptr and increment end ptr
            *end-- = tmp;
        }
    }
}

/**
 * Remove duplicate chars from string in place
 */
void remove_dups(char * str)
{
    int char_idx = 0;
    int i, j;
    char test_char;


    }
}
