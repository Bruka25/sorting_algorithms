#include "sort.h"


void subarray_merge(int *subarray, int *buff, size_t front, size_t mid,
		size_t back);
void recursively_sort(int *subarray, int *buff, size_t front, size_t back);

/**
 *merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 *@array: An array of integers.
 *@size: The size of the array.
 *
 *Return: Void
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	recursively_sort(array, buff, 0, size);

	free(buff);
}



/**
 *subarray_merge - Sort a subarrayay of integers
 *
 *@subarray: A subarrayay of an array of integers to sort
 *@buff: A buffer to store the sorted subarrayay
 *@front: The front index of the array
 *@mid: The middle index of the array
 *@back: The back index of the array
 *
 *Return: Void
 */

void subarray_merge(int *subarray, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + front, mid - front);

	printf("[right]: ");
	print_array(subarray + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < mid; i++)
		buff[k++] = subarray[i];
	for (; j < back; j++)
		buff[k++] = subarray[j];
	for (i = front, k = 0; i < back; i++)
		subarray[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarray + front, back - front);
}

/**
 *recursively_sort - Implement the merge sort algorithm through recursion
 *
 *@subarray: A subarrayay of an array of integers to sort
 *@buff: A buffer to store the sorted result
 *@front: The front index of the subarrayay
 *@back: The back index of the subarrayay
 *
 *Return: Void
 */

void recursively_sort(int *subarray, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		recursively_sort(subarray, buff, front, mid);
		recursively_sort(subarray, buff, mid, back);
		subarray_merge(subarray, buff, front, mid, back);
	}
}
