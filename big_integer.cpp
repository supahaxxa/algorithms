string add_(string a, string b) {
	int a_length = a.length(), b_length = b.length();
	int left, right, result_length;
	string result;

	left = 0, right = a_length - 1;
	while (left < right) swap(a[left++], a[right--]);
	left = 0, right = b_length - 1;
	while (left < right) swap(b[left++], b[right--]);

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

	while (result[result.length() - 1] == '0') result.pop_back();

	left = 0, right = result.length() - 1;
	while (left < right) swap(result[left++], result[right--]);

	return result;
}

string multiply_(string a, string b) {
	int a_len = a.length(), b_len = b.length();
	int left, right, total, carry;
	string result(a_len + b_len, '0');

	left = 0, right = a_len - 1;
	while (left < right) swap(a[left++], a[right--]);
	left = 0, right = b_len - 1;
	while (left < right) swap(b[left++], b[right--]);

	for (int i = 0; i < a_len; i++) {
		carry = 0;
		for (int j = 0; j < b_len; j++) {
			total = ((a[i] - '0') * (b[j] - '0')) + carry + (result[i + j] - '0');
			result[i + j] = (total % 10) + '0';
			carry = total / 10;
		}
		if (carry) result[i + b_len] = carry + '0';
	}

	while (result[result.length() - 1] == '0') result.pop_back();

	left = 0, right = result.length() - 1;
	while (left < right) swap(result[left++], result[right--]);

	return result;
}
