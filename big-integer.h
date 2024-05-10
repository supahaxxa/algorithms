#include <bits/stdc++.h>
using namespace std;

string add_(string a, string b) {
	int a_length = a.length(), b_length = b.length();
	int left, right;
	int result_length;
	string result;

	left = 0, right = a_length - 1;
	while (left <= right) {
		swap(a[left], a[right]);
		left++;
		right--;
	}
	left = 0, right = b_length - 1;
	while (left <= right) {
		swap(b[left], b[right]);
		left++;
		right--;
	}

	if (a_length > b_length) {
		for (int i = 0; i < (a_length - b_length); ++i) {
			b.push_back('0');
		}
		result_length = a_length;
	} else {
		for (int i = 0; i < (b_length - a_length); ++i) {
			a.push_back('0');
		}
		result_length = b_length;
	}
	a.push_back('0');
	b.push_back('0');

	int carry = 0;
	for (int i = 0; i < result_length; ++i) {
		int total = (a[i] - '0') + (b[i] - '0') + carry;
		result.push_back((char)((total % 10) + '0'));
		carry = total / 10;
	}
	if (carry != 0) result.push_back((char)(carry + '0'));

	left = 0, right = result.length() - 1;
	while (left <= right) {
		swap(result[left], result[right]);
		left++;
		right--;
	}

	return result;
}
