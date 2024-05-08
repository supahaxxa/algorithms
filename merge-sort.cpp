#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
int a[N];

void merge(int l, int r, int mid) {
	int left_size = mid - l + 1, right_size = r - mid;
	int LEFT[left_size + 1], RIGHT[right_size + 1];
	
	for (int i = 0; i < left_size; ++i) LEFT[i] = a[i + l];
	for (int i = 0; i < right_size; ++i) RIGHT[i] = a[i + mid + 1];
	
	LEFT[left_size] = RIGHT[right_size] = INT_MAX;
	
	int left_index = 0, right_index = 0;
	for (int i = l; i <= r; ++i) {
		if (LEFT[left_index] <= RIGHT[right_index]) a[i] = LEFT[left_index++];
		else a[i] = RIGHT[right_index++];
	}
}

void merge_sort(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	merge(l, r, mid);
}

// driver code
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> a[i];

	merge_sort(0, n - 1);

	for (int i = 0; i < n; ++i) {
		cout << a[i];
		if (i != n - 1) cout << ' ';
	}

	return 0;
}
