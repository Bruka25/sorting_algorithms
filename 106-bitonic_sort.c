#include "sort.h"

/**
 *bito_merge - Function that Sorts a bitonic sequence
 *             inside an array of integers
 *
 *@array: The array to be sorted
 *@size: The size of the array
 *@start: Starting index of the sequence
 *@seq: Size of the sequence to sort the array
 *@flow: Direction to sort the sequence
 *
 *Return: Void
 */
void bito_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i;
	size_t skip = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + skip; i++)
		{
			if ((flow == UP && array[i] > array[i + skip]) ||
			    (flow == DOWN && array[i] < array[i + skip]))
				swap_idx(array + i, array + i + skip);
		}
		bito_merge(array, size, start, skip, flow);
		bito_merge(array, size, start + skip, skip, flow);
	}
}

/**
 *bito_seq - Function that converts an array of integers
 *           into a bitonic sequence
 *
 *@array: The array to be sorted
 *@size: The size of the array
 *@start: Starting index of the bitionic sequence
 *@seq: Size of the block of bitonic sequence
 *@flow: Direction in which the bitonic sequence to be sorted
 *
 *Return: Void
 */
void bito_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut_seq = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bito_seq(array, size, start, cut_seq, UP);
		bito_seq(array, size, start + cut_seq, cut_seq, DOWN);
		bito_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 *bitonic_sort - Functio that sorts an array of integers
 *               using the bitonic sorting algorithm
 *
 *@array: Array of integers to be sorted
 *@size: The size of the array
 *
 *Return: Void
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bito_seq(array, size, 0, size, UP);
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
