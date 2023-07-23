#include "sort.h"

void int_arr_swap(int *q, int *v);
int hoare_partition_scheme(int *arr, size_t sz, int left_side, int right_side);
void quicksort_algorithm(int *arr, size_t sz, int left_side, int right_side);
void quick_sort_hoare(int *array, size_t size);

/**
 * int_arr_swap - Swap two integers in an array.
 * @q: The first integer to swap.
 * @v: The second integer to swap.
 */
void int_arr_swap(int *q, int *v)
{
	int tmp;

	tmp = *q;
	*q = *v;
	*v = tmp;
}

/**
 * hoare_partition_scheme - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @arr: The array of integers.
 * @sz: The size of the array.
 * @lft_side: The starting index of the subset to order.
 * @rgt_side: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int hoare_partition_scheme(int *arr, size_t sz, int lft_side, int rgt_side)
{
	int piv, up, under;

	piv = arr[rgt_side];
	for (up = lft_side - 1, under = rgt_side + 1; up < under;)
	{
		do {
			up++;
		} while (arr[up] < piv);
		do {
			under--;
		} while (arr[under] > piv);

		if (up < under)
		{
			int_arr_swap(arr + up, arr + under);
			print_array(arr, sz);
		}
	}

	return (up);
}

/**
 * quicksort_algor - Implement the quicksort algorithm through recursion.
 * @arr: An array of integers to sort.
 * @sz: The size of the array.
 * @lft_side: The starting index of the array partition to order.
 * @rgt_side: The ending index of the array partition to order.
 */
void quicksort_algor(int *arr, size_t sz, int lft_side, int rgt_side)
{
	int part;

	if (rgt_side - lft_side > 0)
	{
		part = hoare_partition_scheme(arr, sz, lft_side, rgt_side);
		quicksort_algor(arr, sz, lft_side, part - 1);
		quicksort_algor(arr, sz, part, rgt_side);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_algor(array, size, 0, size - 1);
}
