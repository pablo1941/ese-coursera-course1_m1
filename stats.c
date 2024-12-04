/**************************************************************************/ /**
                                                                              * @file stats.h
                                                                              * @brief Example C programming File
                                                                              *
                                                                              * @author <Pablo Rodriguez>
                                                                              * @date 2024-12-04
                                                                              *
                                                                              * A simple C-Programming example that exhibits a handful of basic c-programming
                                                                              * features to show how to calculate some statistics on a set of numbers:
                                                                              *     -Mean
                                                                              *     -Maximum
                                                                              *     -Minimum
                                                                              *     -Median
                                                                              *
                                                                              * On the other hand, is implemented a sort function to organize data from
                                                                              * largest to smallest value.
                                                                              *
                                                                              *    Note: Is an example to learn concepts about functions, operators and sw
                                                                              *          tools.
                                                                              *
                                                                              *****************************************************************************/
/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main()
{

  unsigned char test[SIZE] = {34, 201, 190, 154, 8, 194, 2, 6,
                              114, 88, 45, 76, 123, 87, 25, 23,
                              200, 122, 150, 90, 92, 87, 177, 244,
                              201, 6, 12, 60, 8, 2, 5, 67,
                              7, 87, 250, 230, 99, 3, 100, 90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
}

/* Add other Implementation File Code Here */
void sort_array(unsigned char *ptr_numbers, unsigned char length_ptr) {}

void print_statistics(unsigned char *ptr_numbers, unsigned char length_ptr) {}

void print_array(unsigned char *ptr_numbers, unsigned char length_ptr) {}

unsigned char find_minimum(unsigned char *ptr_numbers, unsigned char length_ptr) {}

unsigned char find_maximum(unsigned char *ptr_numbers, unsigned char length_ptr) {}

unsigned char find_median(unsigned char *ptr_numbers, unsigned char length_ptr) {}

unsigned char find_mean(unsigned char *ptr_numbers, unsigned char length_ptr) {}
