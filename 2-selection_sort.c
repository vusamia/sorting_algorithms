#include "sort.h"
/**
 * swap_num - swap two numbers
 * @q: integer
 * @v: integer
 **/
void swap_num(int *q, int *v)
{
	int tmp;

	tmp = *q;
	*q = *v;
	*v = tmp;
}
/**
 * selection_sort - sort array using selection sort algorithm
 * @array: array
 * @size: array size
 **/

void selection_sort(int *array, size_t size)
{
	unsigned int q, v, min;

	if (array == NULL || size < 2)
		return;

	for (q = 0; q < size; q++)
	{
		min = q;
		for (v = q + 1; v < size; v++)
		{
			if (array[min] > array[v])
				min = v;
		}
		if (min != q)
		{
			swap_num(&array[q], &array[min]);
			print_array(array, size);
		}
	}

}
