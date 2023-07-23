#include "sort.h"

/**
 * bubble_sort - a function to sort an array
 * @array: integer array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t ub, cj;
	int k;

	for (ub = 0; ub < size; ub++)
		for (cj = 0; cj < size - 1; cj++)
			if (array[cj] > array[cj + 1])
			{
				k = array[cj];
				array[cj] = array[cj + 1];
				array[cj + 1] = k;
				print_array(array, size);
			}
}
