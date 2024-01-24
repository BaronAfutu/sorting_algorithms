#include "sort.h"

void swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap - Swaps two integers.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/**
 * lomuto_partition - Orders a subset of an array according to the lomuto
 *                    partition scheme (last element as pivot).
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implements the quicksort algorithm using recursion.
 * @array: Array to sort.
 * @size: Size of the array.
 * @left: Starting (left) index of the array partition to order.
 * @right: Ending (right) index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme for quicksorting.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int pivot;

	if (right - left > 0)
	{
		pivot = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, pivot - 1);
		lomuto_sort(array, size, pivot + 1, right);
	}
}

/**
 * quick_sort - Sorts an in ascending order using
 *              the quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 *              Prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
