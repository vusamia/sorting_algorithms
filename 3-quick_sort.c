#include "sort.h"

void swap_arr_ints(int *q, int *v);
int lomuto_partition_scheme(int *arr, size_t sz, int lft_side, int rgt_side);
void lomuto_sort_schm(int *arr, size_t sz, int lft_side, int rgt_side);
void quick_sort(int *array, size_t size);

/**
 * swap_arr_ints - Swap two integers in an array.
 * @q: The first integer to swap.
 * @v: The second integer to swap.
 */
void swap_arr_ints(int *q, int *v)
{
	int tmp;

	tmp = *q;
	*q = *v;
	*v = tmp;
}

/**
 * lomuto_partition_scheme - Order a subset of an array of integers according
 * to the lomuto partition scheme (last element as pivot).
 * @arr: The array of integers.
 * @sz: The size of the array.
 * @lft_side: The starting index of the subset to order.
 * @rgt_side: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition_scheme(int *arr, size_t sz, int lft_side, int rgt_side)
{
	int *piv, up, down;

	piv = arr + rgt_side;
	for (up = down = lft_side; down < rgt_side; down++)
	{
		if (arr[down] < *piv)
		{
			if (up < down)
			{
				swap_arr_ints(arr + down, arr + up);
				print_array(arr, sz);
			}
			up++;
		}
	}

	if (arr[up] > *piv)
	{
		swap_arr_ints(arr + up, piv);
		print_array(arr, sz);
	}

	return (up);
}

/**
 * lomuto_sort_schm - Implement the quicksort algorithm through recursion.
 * @arr: An array of integers to sort.
 * @sz: The size of the array.
 * @lft_side: The starting index of the array partition to order.
 * @rgt_side: The ending index of the array partition to order.
 */
void lomuto_sort_schm(int *arr, size_t sz, int lft_side, int rgt_side)
{
	int part;

	if (rgt_side - lft_side > 0)
	{
		part = lomuto_partition_scheme(arr, sz, lft_side, rgt_side);
		lomuto_sort_schm(arr, sz, lft_side, part - 1);
		lomuto_sort_schm(arr, sz, part + 1, rgt_side);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort_schm(array, size, 0, size - 1);
}
