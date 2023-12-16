#include "sort.h"

/**
 *counting_sort - Function that sorts an array using
 *                the counting sort algorithm
 *@array: The array of integers
 *@size: The size of the array
 *
 *Return: Void
 */

void counting_sort(int *array, size_t size)
{
	int *count, *count_sort, maximum, i;

	if (array == NULL || size < 2)
		return;

	count_sort = malloc(sizeof(int) * size);
	if (count_sort == NULL)
		return;
	maximum = max_int(array, size);
	count = malloc(sizeof(int) * (maximum + 1));
	if (count == NULL)
	{
		free(count_sort);
		return;
	}

	for (i = 0; i < (maximum + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (maximum + 1); i++)
		count[i] += count[i - 1];
	print_array(count, maximum + 1);

	for (i = 0; i < (int)size; i++)
	{
		count_sort[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = count_sort[i];

	free(count_sort);
	free(count);
}


/**
 *max_int - Function that gets the maximumimum value in an array of integers
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
