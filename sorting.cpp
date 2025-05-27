vector<int> insertion_sort(vector<int> arr, int length) {
	for (int i = 1; i < length; i++) {
		int j = i - 1;
		while (j >= 0 && arr[j] > arr[j + 1]) {
			arr[j] = arr[j] + arr[j + 1];
			arr[j + 1] = arr[j] - arr[j + 1];
			arr[j] = arr[j] - arr[j + 1];
			j--;
		}
	}

	return arr;
}
