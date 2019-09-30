#if 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <list>

auto& in = std::cin;
auto& out = std::cout;
#define all(C) std::begin(C), std::end(C)

int32_t N;
std::vector<int32_t> edge[101000];

int32_t F(std::vector<int32_t>& a, int32_t K)
{
	std::sort(a.begin(),a.end());
	int lb = -1, ub = a.size();
	while (ub - lb>1) {
		int mid = (ub + lb) / 2;

		bool f = true;
		int l = 0, r = a.size() - 1;
		for (int i = 0; i < a.size() / 2;++i) {
			if (l == mid)l++;
			if (r == mid)r--;
			if (a[l] + a[r]>K)f = false;
			l++; r--;
		}
		if (f)ub = mid;
		else lb = mid;
	}
	return ub;
}

volatile bool func_ok = false;
int32_t len_max;
int32_t func(int32_t v, int32_t parent)
{
	//if (edge[v].size() == 1) {
	//	return 0;
	//}
	//if (edge[v].size() == 2) {
	//	for (auto& e : edge[v]) {
	//		if (e != parent) { return 1 + func(e, v); }
	//	}
	//}

	std::multiset<int32_t, std::greater<int32_t>> L;
	for (auto& e : edge[v]) {
		if (e != parent) {
			L.insert(1 + func(e, v));
		}
	}
	if (L.size() % 2 == 0) {
		L.insert(0);
	}

	std::vector<int32_t> T;
	for (auto& i : L) { T.push_back(i); }
	auto R = F(T, len_max);
	if(R==T.size()){
		func_ok = false;
		return 0;
	}
	else {
		return T[R];
	}

	//while (L.size()>=2) {
	//	auto iter2 = L.begin();
	//	auto iter1 = L.lower_bound(len_max - *iter2);
	//	if (iter1 == L.end()) {
	//		func_ok = false;
	//		return 0;
	//	}
	//	if (iter1 == iter2) {
	//		++iter1;
	//	}
	//	L.erase(iter1);
	//	L.erase(iter2);
	//}
	//return *L.begin();
}
bool func_2(int32_t v)
{
	func_ok = true;
	auto res = (func(edge[v][0], v) + 1 <= len_max);
	return func_ok&&res;
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N;
	for (int32_t i = 0; i < N-1; i++)
	{
		int a, b;
		in >> a >> b; --a; --b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	int32_t A = 1;
	for (int32_t i = 0; i < N; i++)
	{
		A += (edge[i].size() - 1) / 2;
	}
	out << A << ' ';

	int32_t root = 0;
	for (int32_t i = 0; i < N; i++)
	{
		if (edge[i].size() == 1) {
			root = i; break;
		}
	}

	using BS_INT = int64_t;
	BS_INT ok_range = N, ng_range = 0;
	while (std::abs(ok_range - ng_range) > 1) {
		BS_INT mid = (ok_range + ng_range) / 2;
		bool is_ok = false;

		//?????
		len_max=mid;
		is_ok = func_2(root);

		if (is_ok) {
			ok_range = mid;
		}
		else {
			ng_range = mid;
		}
	}
	out << ok_range << endl;


	return 0;
}
#endif