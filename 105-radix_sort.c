#include "sort.h"
/**
 * radix_sort - sorts an array of integers in ascending
 * order
 *
 * @array: input array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int flg = 1, num = 10;
	size_t q, v;

	if (!array || size == 1)
		return;
	while (flg)
	{
		flg = 0;
		for (q = 1, v = 1; q <  size; q++, v++)
		{
			if ((array[q - 1] % (num * 10)) / ((num * 10) / 10) > 0)
				flg = 1;
			if (((array[q - 1] % num) / (num / 10)) > ((array[q] % num) / (num / 10)))
			{
				array[q - 1] = array[q - 1] + array[q];
				array[q] = array[q - 1] - array[q];
				array[q - 1] = array[q - 1] - array[q];
				if ((q - 1) > 0)
					q = q - 2;
			}
		}
		print_array(array, size);
		num = num * 10;
	}
}
