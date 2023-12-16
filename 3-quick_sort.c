#include "sort.h"


/**
 *quick_sort - Entry point for the quick sorting
 *             algorithm
 *
 *@array: The array to be sorted
 *@size: The size of an array
 *
 *Return: Void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

/**
 *swap_idx - Swaps the indexes inside an array
 *
 *@array: The array to be sorted
 *@idx1: The previous index
 *@idx2: The next index
 *
 *Return: The swapped index
 */

size_t swap_idx(int *array, size_t idx1, size_t idx2)
{

	int temp = array[idx1];

	array[idx1] = array[idx2];
	array[idx2] = temp;

	return (idx1);
}

/**
 *lomuto_partition - partitions the array by implementing the
 *                   lomuto partition scheme
 *
 *@array: The array to be sorted
 *@size: The size of an array
 *@left: The first index of the array
 *@right: The last index of the array
 *
 *Return: The pivot index
 */

size_t lomuto_partition(int *array, size_t size, size_t left, size_t right)
{

	int pivot = array[right];
	size_t i = left - 1;
	size_t j;

	for (j = left; j < right; j++)
	{

		if (array[j] <= pivot)
		{
			i++;
			swap_idx(array, i, j);
			print_array(array, size);
		}
	}

	swap_idx(array, i + 1, right);
	print_array(array, size);

	return (i + 1);
}

/**
 *lomuto_sort - Function for solving sorting the partition
 *              using recursive call
 *
 *@array: The array to be sorted
 *@size: The first element of the array
 *@left: The first element of the array
 *@right: The last element of the array
 *
 *Return: void
 */

void lomuto_sort(int *array, size_t size, size_t left, size_t right)
{
	size_t idx;

	if (left < right)
		idx = lomuto_partition(array, size, left, right);

	if (idx > 0)
		lomuto_sort(array, size, left, idx - 1);

	lomuto_sort(array, size, idx + 1, right);
}
