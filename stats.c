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
 * @file stats.c
 * @brief Implements statistics
 *
 * This is for the week 1 assignment of embedded systems class @ Coursera
 *
 * @author Gustavo Castro
 * @date Sunday, July 23, 2017
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  unsigned char minval, maxval, meanval, medval;
  unsigned char * ptr = &test[0];

  minval=find_minimum(ptr,SIZE);
  maxval=find_maximum(ptr,SIZE);
  meanval=find_mean(ptr,SIZE);
  medval=find_median(ptr,SIZE);
  print_statistics(minval,maxval,meanval,medval);
  print_array(ptr,SIZE);
  return 0;
}

/* Implementation File Code */

void print_statistics(unsigned char minval, unsigned char maxval,
					  unsigned char meanval, unsigned char medval){

	printf("Minimum = %u\nMaximim = %u\n", minval,maxval);
	printf("Mean = %u\nMedian = %u\n", meanval,medval);

}


void print_array(unsigned char * data, int data_size){
	printf("Array:\n");
	for(int i=0;i<data_size;i++){
		printf("%u\n",*(data+i));
	}
	printf("<end>\n");
}


unsigned char find_median(unsigned char * data, int data_size ){
	
	unsigned int median = 0;
	unsigned int modulus = 0;

	sort_array(data,data_size);
	if(data_size%2 != 0){
		median = *(data+data_size/2);
	}
	else{
		median=( *(data+data_size/2) + *((data+data_size/2)-1) );
		modulus = 0x0001 & median;
		median >>= 1;
		median += modulus;
	}

	return (unsigned char)median;
}


unsigned char find_mean(unsigned char * data, int data_size ){

	unsigned int average = 0;
	unsigned int modulus = 0;

	for(int i = 0; i < data_size ; i++){
		average += *(data+i);
	}
	modulus = average % data_size;
	if(average % data_size >= data_size/2){
		average = (average/data_size)+1;
	}
	else
		average /= data_size;

	return (unsigned char)average;
}


unsigned char find_maximum(unsigned char * data, int data_size ){
	
	unsigned char max_value= *data;
	
	for(int i = 1; i < data_size ; i++){
		if(max_value <= *(data+i)) max_value = *(data+i);
	}
	
	return max_value;
}


unsigned char find_minimum(unsigned char * data, int data_size ){
	
	unsigned char min_value = *data;
	
	for(int i = 1 ; i < data_size ; i++){
		if(min_value >= *(data+i)) min_value = *(data+i);
	}
	
	return min_value;
}


void sort_array(unsigned char * data, int data_size ){
	quick_sort(data, data + data_size - 1);

}


void quick_sort(unsigned char * left, unsigned char * right ){
	if(left <= right){ // execute only if the left pointer is on the left
		unsigned char * pivot_ptr = split_array(left,right,right);
		quick_sort(left, pivot_ptr - 1);
		quick_sort(pivot_ptr + 1, right);
	}
}


unsigned char * split_array(unsigned char * left, 
							unsigned char * right, 
							unsigned char * pivot){

	unsigned char *l = left;
	unsigned char *r = right - 1;
	unsigned char temp;

	do{
		/* move pointers until finding values that need to swap places*/
		while(*l < *pivot){l++;}
		while( (*r >= *pivot) && (r > left) ){r--;}
		/* swap places only if the pointers have not crossed over each other*/
		if(l <= r){
			temp = *l;
			*l = *r;
			*r = temp;
		}
	}while(l < r); //exit the loop if the pointers crossed over
	/* place pivot between the two subarrays */
	temp = *l;
	*l = *right;
	*right = temp;

	return l;
}
