#include "sort.h"

/**
 * quick_sort - function that sorts an array of ints
 * in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_s(array, 0, size - 1, size);
}

/**
 * lomuto_part - Lomuto partition scheme (Pivot last element)
 * @array: array
 * @left: starting index of the array
 * @right: ending index of the array
 * @size: Size of array
 *
 * Return: i
 */
int lomuto_part(int *array, int left, int right, size_t size)
{
	int i = left - 1;
	int j = left;
	int pivot = array[right], aux = 0;

	for (; j < right; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[right])
	{
		aux = array[i + 1];
		array[i + 1] = array[right];
		array[right] = aux;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * lomuto_s - Lomuto sort through recursion
 * @array: given array of ints
 * @left: starting index of the array
 * @right: ending index of the array
 * @size: array's size
 *
 * Return: void
 */
void lomuto_s(int *array, int left, int right, size_t size)
{
	int pivot;

	if (right - left > 0)
	{
		pivot = lomuto_part(array, left, right, size);
		lomuto_s(array, left, pivot - 1, size);
		lomuto_s(array, pivot + 1, right, size);
	}
}
