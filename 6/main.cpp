#include <iostream>


int main() {
	const int tgt = 100;

	int sumOfSquares = 0;
	for (int i = 1; i <= tgt; i++) {
		sumOfSquares += i*i;
	}

	int sum = 0;
	for (int i = 1; i <= tgt; i++) {
		sum += i;
	}
	int squareOfSum = sum*sum;

	std::cout << squareOfSum - sumOfSquares << std::endl;
	std::getchar();
	return 0;
}