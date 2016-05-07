#include <iostream>

bool isDivisible1to20(int n) {
	for (int i = 1; i <= 20; i++) {
		if (n % i != 0) return false;
	}

	return true;
}

int main() {
	const long MAX = 100000000000;
	long result = 0;

	for (long i = 1; i < MAX; i++) {
		if (isDivisible1to20(i)) {
			result = i;
			break;
		}
	}

	std::cout << result << std::endl;
	std::getchar();
	return 0;
}