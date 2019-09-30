#include <utility>
#include <algorithm>
#include <type_traits>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <memory>
#include <unordered_set>
#include <set>
#include <vector>
#include <chrono>
#include <random>
#include <forward_list>
#include <iomanip>
using namespace std;
int32_t L;
int32_t X;//?????
int32_t Y;//???
int32_t S;
int32_t E;
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> L >> X >> Y >> S >> E;

	//???
	int32_t diff1 = (E - S);
	if (diff1 < 0) { diff1 += L; }

	//??
	int32_t diff2 = L - diff1;

	double time;
	if (X + Y > 0) {
		time = diff1 / double(X + Y);
	}
	if (X - Y < 0) {
		time = min(time,diff2 / -double(X - Y));
	}
	cout << std::fixed << std::setprecision(10) << time << endl;



	return 0;
}