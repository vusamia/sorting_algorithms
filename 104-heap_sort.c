#include "sort.h"

void int_arr_swap(int *q, int *v);
void bintree_to_binheap(int *arr, size_t sz, size_t bs_id, size_t rt_nd);
void heap_sort(int *array, size_t size);

/**
 * int_arr_swap - Swap two integers in an array.
 * @q: The first integer to swap.
 * @v: The second integer to swap.
 */
void int_arr_swap(int *q, int *v)
{
	int cmp;

	cmp = *q;
	*q = *v;
	*v = cmp;
}

/**
 * bintree_to_binheap - Turn a binary tree into a complete binary heap.
 * @arr: An array of integers representing a binary tree.
 * @sz: The size of the array/tree.
 * @bs_id: The index of the base row of the tree.
 * @rt_nd: The root node of the binary tree.
 */
void bintree_to_binheap(int *arr, size_t sz, size_t bs_id, size_t rt_nd)
{
	size_t left, right, large;

	left = 2 * rt_nd + 1;
	right = 2 * rt_nd + 2;
	large = rt_nd;

	if (left < bs_id && arr[left] > arr[large])
		large = left;
	if (right < bs_id && arr[right] > arr[large])
		large = right;

	if (large != rt_nd)
	{
		int_arr_swap(arr + rt_nd, arr + large);
		print_array(arr, sz);
		bintree_to_binheap(arr, sz, bs_id, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int q;

	if (array == NULL || size < 2)
		return;

	for (q = (size / 2) - 1; q >= 0; q--)
		bintree_to_binheap(array, size, size, q);

	for (q = size - 1; q > 0; q--)
	{
		int_arr_swap(array, array + q);
		print_array(array, size);
		bintree_to_binheap(array, size, q, 0);
	}
}
