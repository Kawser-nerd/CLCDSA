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
#include <unordered_map>
#include <set>
#include <vector>
#include <chrono>
#include <random>
#include <forward_list>
#include <iomanip>
#include <functional>
using namespace std;
#define MFOR(i,end) for(size_t i = 0, end_i = (end); i < end_i; ++ i)

//??????!!
constexpr int onkai_num = 12;
string onkai = "WBWBWWBWBWBW";
vector<string> kenbann =
{
	"Do",
	"Do",
	"Re",
	"Re",
	"Mi",
	"Fa",
	"Fa",
	"So",
	"So",
	"La",
	"La",
	"Si",
};
int main()
{
	string rdata;
	cin >> rdata;
	auto first_index = rdata.find(onkai);
	while (first_index == string::npos) {
		onkai.push_back(onkai.front());
		onkai.erase(0,1);
		kenbann.push_back(kenbann.front());
		kenbann.erase(kenbann.begin());
		first_index = rdata.find(onkai);
	}
	if (first_index == 0) {
		cout << kenbann[0] << endl;
	}
	else {
		cout << kenbann[(onkai_num - first_index)] << endl;
	}
}