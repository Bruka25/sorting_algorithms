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

	lomuto_quick_sort(array, size, 0, size - 1);
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

int lomuto_partition(int *array, size_t size, int left, int right)
{

	int *pivot = array + right;
	int up, down;

	for (up = down = left; down < right; down++)
	{

		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_idx(array + down, array + up);
				print_array(array, size);
			}

			up++;
		}
	}

	if (array[up] > *pivot)
	{
		swap_idx(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 *lomuto_quick_sort - Function for solving sorting the partition
 *              using recursive call
 *
 *@array: The array to be sorted
 *@size: The first element of the array
 *@left: The first element of the array
 *@right: The last element of the array
 *
 *Return: void
 */

void lomuto_quick_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = lomuto_partition(array, size, left, right);
		lomuto_quick_sort(array, size, left, partition - 1);
		lomuto_quick_sort(array, size, partition + 1, right);
	}
}
