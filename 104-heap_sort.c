#include "sort.h"


/**
 * heap_sort - Sort an array of integers using
 *             the heap sort algorithm
 *
 *@array: The array to be sorted
 *@size: The size of the array
 *
 *Return: Void
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		bin_heap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_idx(array, array + i);
		print_array(array, size);
		bin_heap(array, size, i, 0);
	}
}

/**
 *bin_heap - Function that turns a binary tree
 *              into a complete binary heap
 *
 *@array: The array that represents the binary tree
 *@size: Size of the array
 *@base: Index of the base row of the binary tree
 *@root: The root node of the binary tree
 *
 *Return: Void
 */
void bin_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t first;
	size_t last;
	size_t biggie;

	first = 2 * root + 1;
	last = 2 * root + 2;
	biggie = root;

	if (first < base && array[first] > array[biggie])
		biggie = first;
	if (last < base && array[last] > array[biggie])
		biggie = last;

	if (biggie != root)
	{
		swap_idx(array + root, array + biggie);
		print_array(array, size);
		bin_heap(array, size, base, biggie);
	}
}

/**
 *swap_idx - Swaps the indexes inside an array
 *
 *@idx1: The previous index
 *@idx2: The next index
 *
 *Return: void
 */

void swap_idx(int *idx1, int *idx2)
{

	int temp = *idx1;
	*idx1 = *idx2;
	*idx2 = temp;
}
