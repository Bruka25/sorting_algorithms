#include "sort.h"

/**
 *selection_sort - Function that sorts an array of integers
 *                 in ascending order
 *
 *@array: The array of integers
 *@size: Size of an array
 *
 *Return: Void
 */

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t int_min;
	int temp;

	if (size == 0 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		int_min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[int_min])
				int_min = j;
		}
		if (i != int_min)
		{
			temp = array[i];
			array[i] = array[int_min];
			array[int_min] = temp;
			print_array(array, size);
		}
	}
}
