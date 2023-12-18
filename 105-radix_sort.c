#include "sort.h"

/**
 *radix_sort - Function that sorts an array of integers
 *             using the radix sort algorithm
 *
 *@array: The array to be sorted
 *@size: The size of the array
 *
 *Return: Void
 */

void radix_sort(int *array, size_t size)
{
	int int_max;
	int imp;
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	int_max = max_int(array, size);
	for (imp = 1; int_max / imp > 0;  imp *= 10)
	{
		_counting_sort(array, size, imp, buffer);
		print_array(array, size);
	}

	free(buffer);
}


/**
 *_counting_sort - Function that sorts the array of
 *                 integers using counting sort
 *
 *@array: The array to be sorted
 *@size: The size of the array
 *@sig: Significant digit to sort inside the array
 *@buff: Buffer to store the sorted array
 *
 *Return: Void
 */

void _counting_sort(int *array, size_t size, int sig, int *buff)
{
	int int_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		int_count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		int_count[i] += int_count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[int_count[(array[i] / sig) % 10] - 1] = array[i];
		int_count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}


/**
 *max_int - Function that gets the maximum value in an array of integers
 *
 *@array: The array of integers to be count_sort
 *@size: The size of the array
 *
 *Return: The maximum integer in the array
 */

int max_int(int *array, int size)
{
	int maximum, i;

	for (maximum = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}

	return (maximum);
}
