/* strings_arrays_test.c
 *
 * Author: Daniel Clark, 2016
 */

// Includes
#include <stdio.h>
#include <string.h>

#include <CUnit/CUnit.h>

#include "../../include/strings_arrays.h"

// Test the reverse function
int test_reverse()
{
    char test_str1[] = "abcd";
    char test_str1_rev[] = "dcba";
    reverse(test_str1);
    printf("test_str1: %s\n", test_str1);
    printf("test_str1_rev: %s\n", test_str1_rev);
    int ret = strcmp(test_str1, test_str1_rev);
    printf("retval for strcmp is: %d\n", ret);
    CU_ASSERT_EQUAL(test_str1, test_str1_rev);
    return(1);
}

int maxi(int i1, int i2)
{
  return (i1 > i2) ? i1 : i2;
}

void test_maxi(void)
{
  CU_ASSERT(maxi(0,2) == 2);
  CU_ASSERT(maxi(0,-2) == 0);
  CU_ASSERT(maxi(2,2) == 2);
}

// Main function
int main()
{
    //int pass = test_reverse();
    test_maxi();
    return(0);
}
