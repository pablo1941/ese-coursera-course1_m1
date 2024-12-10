
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
#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
#define NULL (0)

void main()
{

  unsigned char test[SIZE] = {34, 201, 190, 154, 8, 194, 2, 6,
                              114, 88, 45, 76, 123, 87, 25, 23,
                              200, 122, 150, 90, 92, 87, 177, 244,
                              201, 6, 12, 60, 8, 2, 5, 67,
                              7, 87, 250, 230, 99, 3, 100, 90};
  unsigned char value_min, value_max, value_mean, value_median = 0;
  unsigned char *ptr_sort;
  ptr_sort = test;
  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  value_min = find_minimum(test, SIZE);
  printf("** Result find_minimum: ( %d ) **\n", value_min);

  value_max = find_maximum(test, SIZE);
  printf("** Result find_maximum: ( %d ) **\n", value_max);

  value_mean = find_mean(test, SIZE);
  printf("** Result find_mean: ( %d ) **\n", value_mean);

  sort_array(ptr_sort, SIZE);

  print_array(ptr_sort, SIZE);

  value_median = find_median(ptr_sort, SIZE);
  printf("** Result find_median: ( %d ) **\n", value_median);
}

/* sort_array function */
void sort_array(unsigned char *ptr_numbers, unsigned char length_ptr)
{
  unsigned char value, max_ant, pos = 0;
  unsigned char array_thor[SIZE] = {};

  // Copy array in local scope
  for (int m = 0; m < length_ptr; m++)
  {
    array_thor[m] = ptr_numbers[m];
  }

  if (ptr_numbers == NULL)
  {
    return 0;
  }

  for (int j = 0; j < length_ptr; j++)
  // for (int j = 0; j < 10; j++)
  {
    for (int i = 0; i < length_ptr; i++)
    {
      if (j == 0)
      {
        if ((array_thor[i] >= value))
        {
          value = array_thor[i];
          pos = i;
        }
      }
      else
      {
        if ((array_thor[i] >= value) && (array_thor[i] <= max_ant))
        {
          value = array_thor[i];
          pos = i;
          // printf("value if: (%d), ptr_numbers (%d), pos: (%d) \n", value, array_thor[i], pos);
        }
      }
      // printf("find_maximum sort: iteration{j,i}: (%d,%d), ptr_numbers: (%d), value: (%d), previous max:(%d) \n", j, i, array_thor[i], value, max_ant);
    }
    // Update values
    array_thor[pos] = 0;
    ptr_numbers[j] = value;
    // printf("sort_array: iteration: (%d), array_thor: (%d), max_ant (%d) \n", j, ptr_numbers[j], max_ant);
    max_ant = value;
    value = 0;
  }
}
/* print_statistics function */
void print_statistics(unsigned char *ptr_numbers, unsigned char length_ptr) {}
/* print_array function */
void print_array(unsigned char *ptr_numbers, unsigned char length_ptr)
{
  unsigned char array2print[length_ptr];
  printf("** Result print_array: [");
  for (int i = 0; i < length_ptr; i++)
  {
    printf(" %d", ptr_numbers[i]);
  }
  printf("] **\n");
}
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
  unsigned char value, median, index_median = 0;

  if (ptr_numbers == NULL)
  {
    return 0;
  }

  index_median = SIZE / 2;
  if (SIZE % 2 == 0)
  {
    median = (ptr_numbers[index_median - 1] + ptr_numbers[index_median]) / 2;
  }
  else if (SIZE % 2 == 1)
  {
    median = (ptr_numbers[index_median]);
  }
  return median;
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
