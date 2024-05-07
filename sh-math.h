#include <bits/stdc++.h>
using namespace std;

int sh_array_max(int arr[], int size) {
	int result;
	if (size == 0) return 0;
	else {
		result = arr[0];
		for (int i = 0; i < size; i++) if (arr[i] > result) result = arr[i];
	}

	return result;
}

int sh_array_min(int arr[], int size) {
	int result;
	if (size == 0) return 0;
	else {
		result = arr[0];
		for (int i = 0; i < size; i++) if (arr[i] < result) result = arr[i];
	}

	return result;
}

int sh_digits_sum(int n) {
	int sum = 0;
	while (n >= 10) {
		sum += (n % 10);
		n /= 10;
	}
	sum += n;

	return sum;
}

void sh_divisors(int n) {
	vector<int> v;

	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (n / i == i) cout << i << ' ';
			else {
				cout << i << ' ';
				v.push_back(n / i);
			}
		}
	}

	for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << ' ';
}

int sh_gcd(int a, int b) {
	while (a > 0 && b > 0) {
		if (a > b) a = a % b;
		else b = b % a;
	}

	if (a) return a;
	return b;
}

int sh_lcm(int a, int b) {
	return a * b / sh_gcd(a, b);
}

int sh_mod_power(long long x, unsigned int y, int m) {
	int result = 1;
	x = x % m;

	if (x == 0) return 0;

	while (y > 0) {
		if (y & 1) result = (result * x) % m;

		y = y >> 1;
		x = (x * x) % m;
	}

	return result;
}

int sh_nth_fibonacci(int n) {
	float PHI = (1.0 + pow(5.0, 0.5)) / 2.0;
	float result = ((1.0 / pow(5.0, 0.5)) * (pow(PHI, n) - pow(1.0 - PHI, n)));

	return round(result);
}

const long long MAX_SIZE = 1000001;
vector<long long> isprime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);

void sh_optimized_sieve(int N) {
	isprime[0] = isprime[1] = false;

	for (long long int i = 2; i < N; i++) {
		if (isprime[i]) {
			prime.push_back(i);
			SPF[i] = i;
		}

		for (long long int j = 0; j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) {
			isprime[i * prime[j]] = false;
			SPF[i * prime[j]] = prime[j];
		}
	}
}

int sh_power(int x, unsigned int y) {
	int result = 1;

	while (y > 0) {
		if (y & 1) result = result * x;

		y = y >> 1;
		x = x * x;
	}

	return result;
}

void sh_sieve(int n) {
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p) {
				prime[i] = false;
			}
		}
	}

	for (int p = 2; p <= n; p++) {
		if (prime[p]) {
			cout << p << ' ';
		}
	}
}

int sh_sum(int arr[], int size) {
	size -= 1;
	int result = 0;

	for (; size >= 0; size--) {
		result += arr[size];
	}

	return result;
}
