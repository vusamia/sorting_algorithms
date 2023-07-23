#include "sort.h"
#include "stdlib.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int q, max;
	int *count = NULL, *cop = NULL;
	size_t v, tp, total = 0;


	if (array == NULL || size < 2)
		return;
	cop = malloc(sizeof(int) * size);
	if (cop == NULL)
		return;
	for (v = 0, max = 0; v < size; v++)
	{
		cop[v] = array[v];
		if (array[v] > max)
			max = array[v];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(cop);
		return;
	}
	for (q = 0; q <= max; q++)
		count[q] = 0;
	for (v = 0; v < size; v++)
		count[array[v]] += 1;
	for (q = 0; q <= max; q++)
	{
		tp = count[q];
		count[q] = total;
		total += tp;
	}
	for (v = 0; v < size; v++)
	{
		array[count[cop[v]]] = cop[v];
		count[cop[v]] += 1;
	}
	print_array(count, max + 1);
	free(count);
	free(cop);
}
