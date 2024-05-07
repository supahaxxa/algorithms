#include <bits/stdc++.h>
using namespace std;

int sh_count_element(int element, int arr[], int size) {
	int result;
	if (size == 0) return -1;
	else {
		result = 0;
		for (int i = 0; i < size; i++) if (arr[i] == element) result++;
	}

	return result;
}

bool sh_is_palindrome(string sth) {
	int left = 0, right = sth.length() - 1;

	while (left < right) {
		if (sth[left] != sth[right]) return false;
		left++;
		right--;
	}

	return true;
}

void sh_print_array(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (i != size - 1) cout << ' ';
	}
	cout << '\n';
}

void sh_reverse_array(int arr[], int start, int end) {
	while (start < end) {
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
