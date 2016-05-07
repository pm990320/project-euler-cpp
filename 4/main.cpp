#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

bool isPalandrome(int n) {
	std::ostringstream is;
	is << n;

	std::string s = is.str();

	for (int i = 0; i < s.length(); i++) {
		int f = static_cast<int>(s[i]);
		int e = static_cast<int>(s[s.length()-1-i]);
		if (f != e) {
			return false;
		}
	}

	return true;
}

int main(){
	std::vector<int> palandromes{};

	for (int i = 100; i < 1000; i++) {
		for (int j = 100; j < 1000; j++) {
			if (isPalandrome(i*j)) {
				palandromes.push_back(i*j);
			}
		}
	}

	std::sort(palandromes.rbegin(), palandromes.rend());
	std::cout << palandromes[0] << std::endl;
	std::getchar();
	return 0;
}