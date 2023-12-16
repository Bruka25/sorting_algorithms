#include "sort.h"

/**
 *shell_sort - Function that  Sorts integers using
 *             shell sort algorithm and knuth sequence
 *
 *@array: The array to be sorted
 *@size: The size of the array
 *
 *Return: Void
 */

void shell_sort(int *array, size_t size)
{
	size_t interval;
	size_t i;
	size_t j;

	if (array == NULL || size < 2)
		return;

	for (interval = 1; interval < (size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				swap_idx(array + j, array + (j - interval));
				j -= interval;
			}
		}
		print_array(array, size);
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
