#include <iostream>

int main() {
	int total = 2; // the two is in one_before so not counted...

	int two_before = 1;
	int one_before = 2;
	int current = 3;

	while (current < 4000000) {
		two_before = one_before;
		one_before = current;
		current = two_before + one_before;

		if (current % 2 == 0) {
			total += current;
		}
	}

	std::cout << total << std::endl;
	std::getchar();
	return 0;
}