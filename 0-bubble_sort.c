#include "sort.h"

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
 * bubble_sort - Sorts the elements of an array in ascending order.
 * @array: Array to be sorted.
 * @size: Size of the array.
 *
 * Description: Sorts an array in ascending order and prints the 
 * array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;

	while (swapped == false)
	{
		swapped = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + (i + 1));
				print_array(array, size);
				swapped = false;
			}
		}
		len--;
	}
}
