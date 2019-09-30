#include <iostream>

// ax+by=c ???????(x, y)????????
bool axbyc(int a, int b, int c)
{
	c %= (a * b);
	for (int cand_x = 0; c - a * cand_x >= 0; cand_x++) {
		if ((c - a * cand_x) % b == 0) {
			return true;
		}
	}
	return false;
}

int main(int argc, const char *argv[])
{
	const int PlaceOfCake = 4;
	const int PlaceOfDonuts = 7;

	int N;
	std::cin >> N;

	std::cout << (axbyc(PlaceOfCake, PlaceOfDonuts, N) ? "Yes" : "No")
			  << std::endl;

	return 0;
}