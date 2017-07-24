/******************************************************************************
 * Copyright (C) 2017 by Gustavo Castro
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Gustavo Castro is not liable for any misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief header file for stats.c
 *
 * This is for the week 1 assignment for the embedded systems class @ Coursera
 *
 * @author Gustavo Castro
 * @date Sunday, July 23, 2017
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief prints the statistics of an array 
 *
 * Statistics include minimum, maximum, mean, and median.
 *
 * @return void
 */
void print_statistics();

/**
 * @brief prints the contents of the array 
 *
 * @param * data is the pointer to the array
 * @param data_size is the number of elements in the array
 *
 * @return void
 */
void print_array(unsigned char * data, int data_size);

/**
 * @brief finds the median of the array 
 *
 * The median is the element at the center of the array
 * after placing them in ascending or descending order
 *
 * @param * data is the pointer to the array
 * @param data_size is the number of elements in the array
 *
 * @return unsigned char with the value of the median
 */
unsigned char find_median(unsigned char * data, int data_size );

/**
 * @brief finds the mean of the array 
 *
 * The arithmetic mean is the average of all elements
 * in the array. The result is rounded to the nearest integer
 *
 * @param * data is the pointer to the array
 * @param data_size is the number of elements in the array
 *
 * @return unsigned char with the value of the mean
 */
unsigned char find_mean(unsigned char * data, int data_size );

/**
 * @brief finds the maximum value in the array 
 *
 * @param * data is the pointer to the array
 * @param data_size is the number of elements in the array
 *
 * @return unsigned char with the value of the maximum
 */
unsigned char find_maximum(unsigned char * data, int data_size );

/**
 * @brief finds the minimum value in the array 
 *
 * @param * data is the pointer to the array
 * @param data_size is the number of elements in the array
 *
 * @return unsigned char with the value of the minimum
 */
unsigned char find_minimum(unsigned char * data, int data_size );

/**
 * @brief sorts the array in descending order
 *
 * The array is sorted. The function does not return anything but 
 * after calling this function, the array passed as an argument
 * would be now ordered
 *
 * @param * data is the pointer to the array
 * @param data_size is the number of elements in the array
 *
 * @return void
 */
void sort_array(unsigned char * data, int data_size );

#endif /* __STATS_H__ */
