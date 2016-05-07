#include <iostream>
#include <vector>
#include <algorithm>

bool isPrime(int number) {
	if (number == 1) return false;

	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	long long tgt = 600851475143;
	std::vector<long long> factors;

	for (int i = 1; i <= sqrt(tgt); i++){
		if (tgt % i == 0) {
			if(isPrime(i)) factors.push_back(i);
			if(isPrime(tgt/i)) factors.push_back(tgt / i);
		}
	}

	std::sort(factors.rbegin(), factors.rend());

	std::cout << factors[1] << std::endl;
	std::getchar();
	return 0;
}
