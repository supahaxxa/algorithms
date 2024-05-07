def isPrime_v1(n):
	if n < 2:
		return False
	else:
		for i in range(2, n):
			if n % i == 0:
				return False
	return True


def isPrime_v2(n):
	if n < 2:
		return False
	if n % 2 == 0:
		if n == 2:
			return True
		else:
			return False
	i = 3
	while i <= (n ** 0.5):
		if n % i == 0:
			return False
		i += 2
	return True


def isPrime_v3(n):
	if n < 2:
		return False
	if n == 2:
		return True
	if n == 3:
		return True
	if (n ** 0.5) >= 2:
		if n % 2 == 0:
			return False
	if (n ** 0.5) >= 3:
		if n % 3 == 0:
			return False
	i = 6
	while (i - 1) <= (n ** 0.5):
		if (n % (i - 1) == 0) or (n % (i + 1) == 0):
			return False
		i += 6
	return True


def prime_factorizer(n):
	if n < 2:
		return []
	prime_factors = []
	while n % 2 == 0:
		if prime_factors:
			prime_factors[0][1] += 1
		else:
			prime_factors.append([2, 1])
		n //= 2
	i = 3
	while i <= (n ** 0.5):
		while n % i == 0:
			try:
				prime_factors[-1][1] += 1
			except IndexError:
				prime_factors.append([i, 1])
			n //= i
		i += 2
	if n > 1:
		prime_factors.append([n, 1])

	return prime_factors
