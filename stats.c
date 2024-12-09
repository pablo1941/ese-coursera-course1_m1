/**************************************************************************/ /**
                                                                              * @file stats.h
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
// #define NULL (0)

void main()
{

  unsigned char test[SIZE] = {34, 201, 190, 154, 8, 194, 2, 6,
                              114, 88, 45, 76, 123, 87, 25, 23,
                              200, 122, 150, 90, 92, 87, 177, 244,
                              201, 6, 12, 60, 8, 2, 5, 67,
                              7, 87, 250, 230, 99, 3, 100, 90};
  unsigned char value_min, value_max, value_mean, value_median = 0;
  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  printf("Hola printf, soy Pablo:( %d )\n", test[0]);

  value_min = find_minimum(test, SIZE);
  printf("** Result find_minimum: ( %d ) **\n", value_min);

  value_max = find_maximum(test, SIZE);
  printf("** Result find_maximum: ( %d ) **\n", value_max);

  value_mean = find_mean(test, SIZE);
  printf("** Result find_mean: ( %d ) **\n", value_mean);

  sort_array(test, SIZE);
}

/* sort_array function */
void sort_array(unsigned char *ptr_numbers, unsigned char length_ptr)
{
  unsigned char value, max_ant, pos = 0;
  unsigned char array_thor[SIZE] = {};

  if (ptr_numbers == NULL)
  {
    return 0;
  }

  for (int j = 0; j < length_ptr; j++)
  // for (int j = 0; j < 15; j++)
  {
    for (int i = 0; i < length_ptr; i++)
    {
      if (j == 0)
      {
        if ((ptr_numbers[i] >= value))
        {
          value = ptr_numbers[i];
          pos = i;
        }
      }
      else
      {
        if ((ptr_numbers[i] >= value) && (ptr_numbers[i] <= max_ant))
        // if ( (ptr_numbers[i] <= max_ant))
        {
          value = ptr_numbers[i];
          pos = i;
        }
      }
      // printf("find_maximum sort: iteration{j,i}: (%d,%d), ptr_numbers: (%d), value: (%d), previous max:(%d) \n", j, i, ptr_numbers[i], value, max_ant);
    }
    // Update values
    ptr_numbers[pos] = 0;
    array_thor[j] = value;
    printf("sort_array: iteration: (%d), array_thor: (%d), max_ant (%d) \n", j, array_thor[j], max_ant);
    max_ant = value;
    value = 0;
  }
}
/* print_statistics function */
void print_statistics(unsigned char *ptr_numbers, unsigned char length_ptr) {}
/* print_array function */
void print_array(unsigned char *ptr_numbers, unsigned char length_ptr) {}
/* find_minimum function */
unsigned char find_minimum(unsigned char *ptr_numbers, unsigned char length_ptr)
{
  unsigned char value = 0;

  if (ptr_numbers == NULL)
  {
    return 0;
  }

  for (int i = 0; i < length_ptr; i++)
  {
    if (i == 0)
    {
      value = *ptr_numbers;
    }

    if (*ptr_numbers <= value)
    {
      value = *ptr_numbers;
    }
    // printf("find_minimum: itaration: (%d), value: (%d) \n", i, *ptr_numbers);
    ptr_numbers++;
  }

  return value;
}
/* find_maximum function */
unsigned char find_maximum(unsigned char *ptr_numbers, unsigned char length_ptr)
{
  unsigned char value = 0;

  if (ptr_numbers == NULL)
  {
    return 0;
  }

  for (int i = 0; i < length_ptr; i++)
  {
    if (i == 0)
    {
      value = *ptr_numbers;
    }

    if (*ptr_numbers >= value)
    {
      value = *ptr_numbers;
    }
    // printf("find_maximum: itaration: (%d), value: (%d) \n", i, *ptr_numbers);
    ptr_numbers++;
  }
  return value;
}
/* find_median function */
unsigned char find_median(unsigned char *ptr_numbers, unsigned char length_ptr)
{
  unsigned char value = 0;

  if (ptr_numbers == NULL)
  {
    return 0;
  }

  for (int i = 0; i < length_ptr; i++)
  {
    if (i == 0)
    {
      value = *ptr_numbers;
    }

    if (*ptr_numbers >= value)
    {
      value = *ptr_numbers;
    }
    // printf("find_maximum: itaration: (%d), value: (%d) \n", i, *ptr_numbers);
    ptr_numbers++;
  }
  return value;
}
/* find_mean function */
unsigned char find_mean(unsigned char *ptr_numbers, unsigned char length_ptr)
{
  unsigned int value = 0;

  if (ptr_numbers == NULL)
  {
    return 0;
  }

  for (int i = 0; i < length_ptr; i++)
  {
    value += *ptr_numbers;
    // printf("find_mean: itaration: (%d), value: (%d) \n", i, value);
    ptr_numbers++;
  }
  return (value / length_ptr);
}
