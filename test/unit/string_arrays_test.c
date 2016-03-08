/* strings_arrays_test.c
 *
 * Author: Daniel Clark, 2016
 */

// Includes
#include <stdio.h>
#include <string.h>

#include <CUnit/Basic.h>

#include "../../include/strings_arrays.h"

/* Pointer to the file used by the tests. */
static FILE* temp_file = NULL;

/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void)
{
   if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
      return -1;
   }
   else {
      return 0;
   }
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
   if (0 != fclose(temp_file)) {
      return -1;
   }
   else {
      temp_file = NULL;
      return 0;
   }
}

/* Simple test of fprintf().
 * Writes test data to the temporary file and checks
 * whether the expected number of bytes were written.
 */
void testFPRINTF(void)
{
   int i1 = 10;

   if (NULL != temp_file) {
      CU_ASSERT(0 == fprintf(temp_file, ""));
      CU_ASSERT(2 == fprintf(temp_file, "Q\n"));
      CU_ASSERT(7 == fprintf(temp_file, "i1 = %d", i1));
   }
}

// Test the reverse function
void test_reverse(void)
{
    char test_str1[] = "abcd";
    char test_str1_rev[] = "dcba";
    reverse(test_str1);
    CU_ASSERT_STRING_EQUAL(test_str1, test_str1_rev);
}

// Test the reverse function
void test_remove_dups(void)
{
    char test_str1[] = "zraarbcacd";
    char test_str1_nodups[] = "zrabcd";
    remove_dups(test_str1);
    CU_ASSERT_STRING_EQUAL(test_str1, test_str1_nodups);
}
/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
    // Init CUnit test suit (pointer to suite)
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Add a suite to the registry
    pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
    // If there was an error adding suite, clean up and return error
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add tests to the suite - if NULL on either, clean and error out
    if ((NULL == CU_add_test(pSuite, "test of fprintf()", testFPRINTF)) ||
        (NULL == CU_add_test(pSuite, "test of reverse()", test_reverse)) ||
        (NULL == CU_add_test(pSuite, "test of remove_dups()", test_remove_dups)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the CUnit Basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
