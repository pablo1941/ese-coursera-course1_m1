
/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 * @file stats.h
 * @brief Example C programming File
 *
 * @author <Pablo Rodriguez>
 * @date 2024-12-04 / 2024-12-10
 *
 * A simple C-Programming example that exhibits a handful of basic c-programming
 * features to show how to calculate some statistics on a set of numbers:
 *     -Mean
 *     -Maximum
 *     -Minimum
 *     -Median
 * On the other hand, is implemented a sort function to organize data from
 * largest to smallest value.
 *
 *    Note: Is an example to learn concepts about functions, operators and sw
 *          tools.
 *
 *****************************************************************************/

#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

/******************************************************************************
 * Function: find_mean
 * Description:
 *     This function calculates the mean value of data array.
 * Parameters:
 *     int * ptr_numbers: Pointer to a data set
 *     int length_ptr: Number of items in data set
 * Return:
 *     Mean value of the numbers provided.
 *****************************************************************************/
unsigned char find_mean(unsigned char *ptr_numbers, unsigned char length_ptr);
/******************************************************************************
 * Function: find_median
 * Description:
 *     This function calculates the median value of data array.
 * Parameters:
 *     int * ptr_numbers: Pointer to a data set
 *     int length_ptr: Number of items in data set
 * Return:
 *     Median value of the numbers provided.
 *****************************************************************************/
unsigned char find_median(unsigned char *ptr_numbers, unsigned char length_ptr);
/******************************************************************************
 * Function: find_maximum
 * Description:
 *     This function calculates the maximum value of data array.
 * Parameters:
 *     int * ptr_numbers: Pointer to a data set
 *     int length_ptr: Number of items in data set
 * Return:
 *     Maximum value of the numbers provided.
 *****************************************************************************/
unsigned char find_maximum(unsigned char *ptr_numbers, unsigned char length_ptr);
/******************************************************************************
 * Function: find_minimum
 * Description:
 *     This function calculates the minimum value of data array.
 * Parameters:
 *     int * ptr_numbers: Pointer to a data set
 *     int length_ptr: Number of items in data set
 * Return:
 *     Minimum value of the numbers provided.
 *****************************************************************************/
unsigned char find_minimum(unsigned char *ptr_numbers, unsigned char length_ptr);

/******************************************************************************
 * Function: print_array
 * Description:
 *     This function prints data array in screen.
 * Parameters:
 *     int * ptr_numbers: Pointer to a data set
 *     int length_ptr: Number of items in data set
 * Return:
 *     Empty.
 *****************************************************************************/
void print_array(unsigned char *ptr_numbers, unsigned char length_ptr);

/******************************************************************************
 * Function: print_statistics
 * Description:
 *     This function prints statistics as minimum, maximum, mean, and median
 *     of data array in screen.
 * Parameters:
 *     int * ptr_numbers: Pointer to a data set
 *     int length_ptr: Number of items in data set
 * Return:
 *     Empty.
 *****************************************************************************/
void print_statistics(unsigned char *ptr_numbers, unsigned char length_ptr);

/******************************************************************************
 * Function: sort_array
 * Description:
 *     This function sorts data array from largest to smallest value.
 * Parameters:
 *     int * ptr_numbers: Pointer to a data set
 *     int length_ptr: Number of items in data set
 * Return:
 *     Empty.
 *****************************************************************************/
void sort_array(unsigned char *ptr_numbers, unsigned char length_ptr);

#endif /* __STATS_H__ */
