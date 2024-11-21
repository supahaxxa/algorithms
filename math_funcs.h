int array_max(vector<int>& arr) {
	if (arr.size() == 0) return 0;
	else {
		int result = arr[0];
		for (int i = 1; i < arr.size(); i++) if (arr[i] > result) result = arr[i];
		return result;
	}
}

int array_min(vector<int>& arr) {
	if (arr.size() == 0) return 0;
	else {
		int result = arr[0];
		for (int i = 1; i < arr.size(); i++) if (arr[i] < result) result = arr[i];
		return result;
	}
}

// for not so large numbers
int digits_sum_int(int n) {
	int sum = 0;
	while (n) {
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

// for large numbers
int digits_sum_string(string n) {
	int sum = 0;
	for (int i = 0; i < n.length(); i++) sum += (n[i] - '0');
	return sum;
}

vector<int> divisors(int n) {
	vector<int> divs;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			divs.push_back(i);
			if (n / i != i) divs.push_back(n / i);
		}
	}
	return divs;
}

int gcd_iterative(int a, int b) {
	while (a > 0 && b > 0) {
		if (a > b) a = a % b;
		else b = b % a;
	}
	if (a) return a;
	return b;
}

int gcd_recursive(int a, int b) {
	if (b == 0) return a;
	int temp = a;
	a = b;
	b = temp % a;
	return hcf(a, b);
}

int lcm(int a, int b) {
	return a * b / gcd_recursive(a, b);
}

int mod_power(long long x, unsigned int y, int m) {
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

int nth_fibonacci(int n) {
	double PHI = (1.0 + pow(5.0, 0.5)) / 2.0;
	double result = ((1.0 / pow(5.0, 0.5)) * (pow(PHI, n) - pow(1.0 - PHI, n)));
	return round(result);
}

const long long MAX_SIZE = 1000001;
vector<long long> isprime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);

void optimized_sieve(int N) {
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

int power(int x, unsigned int y) {
	int result = 1;
	while (y > 0) {
		if (y & 1) result = result * x;
		y = y >> 1;
		x = x * x;
	}
	return result;
}

// there must be n + 1 items in the prime vector
void sieve(vector<bool>& prime) {
	memset(prime, true, sizeof(prime));
	for (int p = 2; p * p < prime.size(); p++) {
		if (prime[p] == true) {
			for (int i = p * p; i < prime.size(); i += p) prime[i] = false;
		}
	}
}

int summation(vector<int>& arr) {
	int result = 0;
	for (int i = 0; i < arr.size(); i++) result += arr[i];
	return result;
}

int sum_of_divisors(int number) {
	vector<int> factors;
	int result = 1;
	if (number % 2 == 0) {
		factors.push_back(2);
		factors.push_back(0);
		while (number % 2 == 0) {
			number /= 2;
			factors[1]++;
		}
	}
	if (number % 3 == 0) {
		factors.push_back(3);
		factors.push_back(0);
		while (number % 3 == 0) {
			number /= 3;
			factors[3]++;
		}
	}
	int a = 5, b = 7;
	while (a * a <= number) {
		if (number % a == 0) {
			factors.push_back(a);
			factors.push_back(0);
			while (number % a == 0) {
				number /= a;
				factors[factors.size() - 1]++;
			}
		}
		if (number % b == 0) {
			factors.push_back(b);
			factors.push_back(0);
			while (number % b == 0) {
				number /= b;
				factors[factors.size() - 1]++;
			}
		}
		a += 6;
		b += 6;
	}
	if (number > 1) {
		factors.push_back(number);
		factors.push_back(1);
	}
	for (int var = 0; var < factors.size() / 2; var++) {
		result *= (int) ((pow(factors[2 * var], factors[(2 * var) + 1] + 1) - 1) / (factors[2 * var] - 1));
	}
	return result;
}
