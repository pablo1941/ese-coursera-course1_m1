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
/**
 * @file main.c
 * @brief Final Assessment
 *
 * This file contains the main function to invoke course1();
 *
 * @author Pablo Rodriguez
 * @date January 25, 2025
 *
 */

#include "course1.c"

/* A pretty boring main file */
int main(void)
{

#ifdef COURSE1
  PRINTF("*****Beginning my program :D. ");
  course1();
#endif
}
