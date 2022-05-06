/**
 * @file    unit_test_ansi_C.h
 * @brief   header file to do unit tests in ANSI C.
 * @author  Montse Garcia-Famoso
 * @version 1.2
 * @date    2017
 *
 * @copyright GNU Public License
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The below copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef UNIT_TEST_ANSI_C_H
#define UNIT_TEST_ANSI_C_H

#ifndef __arm__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <setjmp.h>
#include <assert.h>
#include <signal.h>
#include <ctype.h>
#endif  /* __arm__ */

#define UT_UNITTEST_MAX    64      /* Maxim number of unittest in ARM systems */

/**
 * ##Assert rutines##
 */

/**
 * assert Value is TRUE
 */
bool assert_true(bool value, char *comments);

/**
 * assert Value is FALSE
 */
bool assert_false(bool value, char *comments);

/**
 * assert actual Character is equal to expected
 */
bool assert_char_equal(char actual, char expected, char *comments);

/**
 * assert actual Unsigned Integer is lower to expected
 */
bool assert_uint_lower(unsigned int actual, unsigned int expected, char *comments);

/**
 * assert actual Unsigned Integer is higher than expected
 */
bool assert_uint_higher(unsigned int actual, unsigned int expected, char *comments);

/**
 * assert actual Integer is less than expected
 */
bool assert_int_equal(int actual, int expected, char *comments);

/**
 * assert actual Unsigned Integer is less than expected
 */
bool assert_int_less(int actual, int expected, char *comments);

/**
 * assert actual Integer is greater than expected
 */
bool assert_int_greater (int actual, int expected, char *comments);

/**
 * assert actual Double is almost equal to expected
 */
bool assert_double_almost_equal(double actual, double expected, double precision, char *comments);

/**
 * assert actual Double is less than expected
 */
bool assert_double_less(double actual, double expected, char *comments);

/**
 * assert actual String is equal to expected (NOT in ARM)
 */
bool assert_string_equal(char *actual, char *expected, char *comments);

/**
 * assert actual String (insentitive) is equal to expected  (NOT in ARM)
 */
bool assert_string_equal_insensitive (char *actual, char *expected, char *comments);

/**
 * assert actual Data in memory are equal to expected
 */
bool assert_data_equal (void *actual, void *expected,
                      unsigned long actual_size, unsigned long expected_size,
                      char *comments);

/**
 * assert actual Data in memory are equal to expected Value
 */
bool assert_data_equal_to (void *actual, void *value,
                        unsigned long data_size, unsigned long value_size, char *comments);

/**
 * assert actual File is equal to expected (NOT in ARM)
 */
bool assert_file_equal(char *actual, char *expected, char *comments);

/**
 * assert actual Mem block is equal to expected (NOT in ARM)
 */
bool assert_mem_equal(const void *actual, const void *expected, size_t byte_size, char *comments);

/**
 ### Auxiliary rutines to report information ###
 */
/**
 * Send exception missatge to standard error
 */
void report_exception(int sig, char *message);

/**
 * Send missatge to standard error
 */
void report_error(char *message);

/**
 * Send missatge to standard output
 */
void report_stdout(char *message);

/**
 * Send report to standard error
 */
void report_results(char *message, unsigned int num_tests,
                    unsigned int num_oks);

#endif /* UNIT_TEST_ANSI_C_H */
