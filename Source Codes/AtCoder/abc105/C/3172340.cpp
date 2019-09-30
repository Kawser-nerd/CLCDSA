#include <iostream>
#include <string>
#include <algorithm>

namespace {
	inline char itoc(int i)
	{
		return '0' + i;
	}
} /* namespace  */

std::string itobina(int a)
{
	const int b=(-2);
	std::string ret;

	while (a != 0) {
		int p = a / b;
		int q = a % b;
		if (q < 0) {
			p += 1;
			q -= b;
		}
		ret.push_back(itoc(q));
		a = p;
	}

	if (ret.size() == 0) {
		ret = "0";
	}
	else {
		std::reverse(ret.begin(), ret.end());
	}

	return ret;
}

int main(int argc, const char *argv[])
{
	int N;
	std::cin >> N;
	std::cout << itobina(N) << std::endl;
	return 0;
}