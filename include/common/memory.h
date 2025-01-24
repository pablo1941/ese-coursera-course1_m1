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
 * @file memory.h
 * @brief Abstraction of memory, general move operations
 *
 * This header file provides an abstraction of general move operations
 * in the memory via function calls.
 *
 * @author Pablo Rodriguez
 * @date January 25, 2025
 *
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>

/**
 * @brief Move ptr1 to ptr2
 *
 * --> This function takes two byte pointers (one source and one destination) and
 *     a length of bytes to move from the source location to the destination.
 * --> The behavior should handle overlap of source and destination. Copy should
 *      occur, with no data corruption.
 * --> All operations need to be performed using pointer arithmetic, not array indexing
 *
 * @param uint8_t * src: Pointer source
 * @param uint8_t * dst: Pointer destination
 * @param size_t length: length of bytes to move from the source location to the destination
 *
 * @return uint8_t *: Should return a pointer to the destination (dst).
 */

uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length);

/**
 * @brief Copy ptr1 to ptr2
 *
 * --> This function takes two byte pointers (one source and one destination) and a length
 *      of bytes to copy from the source location to the destination.
 * --> The behavior is undefined if there is overlap of source and destination. Copy should
 *       still occur, but will likely corrupt your data.
 * --> All operations need to be performed using pointer arithmetic, not array indexing
 *
 * @param uint8_t * src: Pointer source
 * @param uint8_t * dst: Pointer destination
 * @param size_t length: length of bytes to copy from the source location to the destination
 *
 * @return uint8_t *: Should return a pointer to the destination (dst).
 */

uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length);

/**
 * @brief Set value in memory segment
 *
 * --> This should take a pointer to a source memory location, a length in bytes and set all
 *      locations of that memory to a given value
 * --> All operations need to be performed using pointer arithmetic, not array indexing
 * --> You should NOT reuse the set_all() function
 *
 * @param uint8_t * src: Pointer to data array
 * @param size_t length: length in bytes and set all locations of that memory to a given value
 * @param uint8_t value: Value to set memory positions
 *
 * @return uint8_t *: Should return a pointer to the source (src).
 */

uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value);

/**
 * @brief Clear memory segment
 *
 * --> This should take a pointer to a memory location, a length in bytes and zero out all of the memory.
 * --> All operations need to be performed using pointer arithmetic, not array indexing
 * --> You should NOT reuse the clear_all() function
 *
 * @param uint8_t * src: Pointer to data array
 * @param size_t length: length in bytes and set all locations of that memory to a given value
 *
 * @return uint8_t *: Should return a pointer to the source (src).
 */

uint8_t *my_memzero(uint8_t *src, size_t length);

/**
 * @brief Reverse ptr values
 *
 * --> This should take a pointer to a memory location and a length in bytes and reverse
 *      the order of all of the bytes.
 * --> All operations need to be performed using pointer arithmetic, not array indexing
 *
 * @param uint8_t * src: Pointer to data array
 * @param size_t length: length in bytes and set all locations of that memory to a given value
 *
 * @return uint8_t *: Should return a pointer to the source.
 */

uint8_t *my_reverse(uint8_t *src, size_t length);

/**
 * @brief Reserve memory segment
 *
 * --> This should take number of words to allocate in dynamic memory
 * --> All operations need to be performed using pointer arithmetic, not array indexing
 *
 * @param size_t length: length in bytes and set all locations of that memory to a given value
 *
 * @return uint32_t *: Should return a pointer to memory if successful, or a Null Pointer if not successful
 */

int32_t *reserve_words(size_t length);

/**
 * @brief Reserve memory segment
 *
 * --> Should free a dynamic memory allocation by providing the pointer src to the function
 * --> All operations need to be performed using pointer arithmetic, not array indexing
 *
 * @param size_t length: length in bytes and set all locations of that memory to a given value
 *
 * @return uint32_t *: Should return a pointer to memory if successful, or a Null Pointer if not successful
 */

void free_words(int32_t *src);

#endif /* __MEMORY_H__ */
