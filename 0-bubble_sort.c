
#include "sort.h"

/**
 *bubble_sort - Functions that sorts using the bubble
 *              sorting algorithm
 *
 *@array: Array that contains the integers to be sorted
 *@size: The size of the array
 *
 *Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t a;
	size_t swap_int;
	int temp;

	if (size == 0 || array == NULL)
		return;


	swap_int = 1;

	while (swap_int)
	{
		swap_int = 0;

		for (a = 0; a < size - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				temp = array[a + 1];
				array[a + 1] = array[a];
				array[a] = temp;
				swap_int = 1;
				print_array(array, size);
			}
		}
	}
}
