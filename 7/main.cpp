#include <iostream>

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
	int count = 0;
	for (int i = 2; i < 1000000; i++) {
		if (isPrime(i)) count++;
		if (count == 10001) {
			std::cout << i << std::endl;
			break;
		}
	}

	std::getchar();
	return 0;
}