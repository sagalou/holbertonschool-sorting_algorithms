#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - partitions array using Lomuto scheme
 * @array: the array to partition
 * @size: size of the array
 * @low: starting index
 * @high: ending index (pivot)
 *
 * Return: index of the pivot after partition
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - recursive quick sort
 * @array: the array to sort
 * @size: size of the array
 * @low: starting index
 * @high: ending index
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, size, low, high);
		quick_sort_recursive(array, size, low, pivot_idx - 1);
		quick_sort_recursive(array, size, pivot_idx + 1, high);
	}
}

/**
 * quick_sort - sorts an array using quick sort
 * @array: the array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, size, 0, size - 1);
}
