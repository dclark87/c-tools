/* strings_arrays.c
 *
 * Author: Daniel Clark, 2016
 */

// Includes
#include "../include/strings_arrays.h"
#include <stdio.h>
#include <string.h>

/**
 * Reverse c-style strings in place
 */
void reverse(char* str)
{
    char* end = str;
    char tmp;
    if (str) {
        // Increment end index to end of string
        while (*end) {
            ++end;
        }
        // Go back one char from null
        --end;
        // While str ptr addr (beg idx) < end ptr addr (end idx)
        while (str < end) {
            printf("\nc-str: %s, *str: %c, str: %p\n", str, *str, str);
            // Store str contents into tmp
            tmp = *str;
            // Set value at str to last char and reference next char in str
            *str++ = *end;
            // Insert beginning char into end idx and decrement ptr
            *end-- = tmp;
        }
        printf("\nstr val is now: %s", str);
    }
}

/**
 * Remove duplicate chars from string in place
 */
void remove_dups(char* str)
{
    if (!str) return;
    int len;
    len = strlen(str);
    if (len < 2) return;

    int tail, i = 1;
    for (i = 1; i < len; ++i)
    {
        int j;
        for (j = 0; j < tail; ++j)
            if (str[i] == str[j])
                break;
         if (j == tail)
        {
            str[tail] = str[i];
            ++tail;
        }
    }
    str[tail] = '\0';
}
//
//void removeDuplicates(char *str)
//{
//
//    if (!str)
//        return;
//    int len = strlen(str);
//    if (len < 2)
//        return;
//    bool hit[256];
//    for(int i = 0; i < 256; ++i)
//        hit[i] = false;
//
//    hit[str[0]] = true;
//    int tail = 1;
//    for (int i = 1; i < len; ++i)
//    {
//        if (!hit[str[i]])
//        {
//            str[tail] = str[i];
//            ++tail;
//            hit[str[i]] = true;
//        }
//    }
//    str[tail] = '\0';
//}
