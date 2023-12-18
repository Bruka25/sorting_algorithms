#include "sort.h"

/**
 *quick_sort_hoare - Function that sorts an array of integers
 *                   using the quicksort algorithm
 *
 *@array: The array to be sorted
 *@size: Size of the array thats going to be sorted
 *
 *Return: Void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_quick(array, size, 0, size - 1);
}

/**
 *sort_quick - Function that recursively implements the
 *             quicksort algorithm
 *
 *@array: The array to be sorted
 *@size: Size of the array
 *@left: Starting index of the array
 *@right: Ending index of the array
 *
 *Return: Void
 */

void sort_quick(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = partition_hoare(array, size, left, right);
		sort_quick(array, size, left, partition - 1);
		sort_quick(array, size, partition, right);
	}
}


/**
 *partition_hoare - Function that orders a subset of an array
 *                  of integers according to the hoare partition scheme
 *
 *@array: The array to be partitioned
 *@size: The size of the array
 *@left: Starting index of the subset to order
 *@right: Ending index of the subset to order
 *
 *Return: Final partitioned index thats been ordered
 */
int partition_hoare(int *array, size_t size, int left, int right)
{
	int pivot;
	int above_pivot;
	int below_pivot;

	pivot = array[right];
	for (above_pivot = left - 1, below_pivot = right + 1;
			above_pivot < below_pivot;)
	{
		do {
			above_pivot++;
		} while (array[above_pivot] < pivot);
		do {
			below_pivot--;
		} while (array[below_pivot] > pivot);

		if (above_pivot < below_pivot)
		{
			swap_idx(array + above_pivot, array + below_pivot);
			print_array(array, size);
		}
	}

	return (above_pivot);
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
