#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sort_merge_subarr - sorts and merges the sub arrays in source
 * @start_id: starting index (inclusive) for left sub array
 * @middle_id: end index (exclusive) for left sub array and
 * starting index (inclusive) for the right sub array
 * @end_id: end index (exclusive) for the right sub array
 * @dest_d: destination for data
 * @source_d: source of data
 *
 * Return: void
 */
void sort_merge_subarr(size_t start_id, size_t middle_id, size_t end_id,
		int *dest_d, int *source_d)
{
	size_t q, v, z;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source_d + start_id, middle_id - start_id);
	printf("[right]: ");
	print_array(source_d + middle_id, end_id - middle_id);
	q = start_id;
	v = middle_id;
	for (z = start_id; z < end_id; z++)
	{
		if (q < middle_id && (v >= end_id || source_d[q] <= source_d[v]))
		{
			dest_d[z] = source_d[q];
			q++;
		}
		else
		{
			dest_d[z] = source_d[v];
			v++;
		}
	}
	printf("[Done]: ");
	print_array(dest_d + start_id, end_id - start_id);
}

/**
 * split_merge_array - recursively splits the array and merges
 *                     the sorted arrays
 * @begin_id: starting index (inclusive)
 * @close_id: end index (exclusive)
 * @arr: the array to sort
 * @cpy: a copy of the array
 *
 * Return: void
 */
void split_merge_array(size_t begin_id, size_t close_id, int *arr, int *cpy)
{
	size_t midd;

	if (close_id - begin_id < 2)
		return;
	midd = (begin_id + close_id) / 2;
	split_merge_array(begin_id, midd, arr, cpy);
	split_merge_array(midd, close_id, arr, cpy);
	sort_merge_subarr(begin_id, midd, close_id, arr, cpy);
	for (midd = begin_id; midd < close_id; midd++)
		cpy[midd] = arr[midd];
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t q;
	int *cop;

	if (array == NULL || size < 2)
		return;
	cop = malloc(sizeof(int) * size);
	if (cop == NULL)
		return;
	for (q = 0; q < size; q++)
		cop[q] = array[q];
	split_merge_array(0, size, array, cop);
	free(cop);
}
