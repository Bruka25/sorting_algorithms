#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>



/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

listint_t *head_node(listint_t *temp);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void swap_idx(int *idx1, int *idx2);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_quick_sort(int *array, size_t size, int left, int right);


/*counting sort function helper*/
int max_int(int *array, int size);

/*heap sort function helper*/
void bin_heap(int *array, size_t size, size_t base, size_t root);

/*Radix sort helper function*/
void _counting_sort(int *array, size_t size, int sig, int *buff);

/*Directional macros for comparison in bitonic sort*/
#define UP 0
#define DOWN 1

/*bitonic sort helper functions*/
void bito_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bito_seq(int *array, size_t size, size_t start, size_t seq, char flow);

/*qiuck sort hoare helper functions*/
int partition_hoare(int *array, size_t size, int left, int right);
void sort_quick(int *array, size_t size, int left, int right);



#endif/*SORT_H*/
