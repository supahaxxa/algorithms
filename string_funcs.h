int count_element(vector<int>& arr, int element) {
	if (arr.size() == 0) return -1;
	else {
		int result = 0;
		for (int i = 0; i < arr.size(); i++) if (arr[i] == element) result++;
		return result;
	}
}

bool is_palindrome(string& text) {
	int left = 0, right = text.length() - 1;
	while (left < right) {
		if (text[left] != text[right]) return false;
		left++;
		right--;
	}
	return true;
}

void print_array(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
		if (i != arr.size() - 1) cout << ' ';
	}
}

// in-place array reversal
void reverse_array(vector<int>& arr) {
	int left = 0, right = arr.size() - 1;
	while (left < right) {
		int temp = arr[left];
		arr[left++] = arr[right];
		arr[right--] = temp;
	}
}
