"""
Insertion Sort
This is a simple sorting algorithm that builds the final sorted list one item at a time by comparisons. It is much less
efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.
"""

def insertion_sort(arr, reverse=False):
	"""
	Sorts the `arr` list following insertion sort algorithm.
	If the argument `reverse` isn't passed in, the `arr` list is sorted in ascending order.

	Parameters
	==========
	arr : list
		The list to be sorted.
	reverse : bool
		Set to False by default, sorts the list in ascending order.
		When set to True, list is sorted in descending order.
	"""
	if reverse:
		for i in range(1, len(arr)):
			while arr[i] > arr[i - 1] and i > 0:
				if arr[i] > arr[i - 1]:
					arr[i - 1], arr[i] = arr[i], arr[i - 1]
					i -= 1
	else:
		for i in range(1, len(arr)):
			while arr[i] < arr[i - 1] and i > 0:
				if arr[i] < arr[i - 1]:
					arr[i - 1], arr[i] = arr[i], arr[i - 1]
					i -= 1

	return arr
