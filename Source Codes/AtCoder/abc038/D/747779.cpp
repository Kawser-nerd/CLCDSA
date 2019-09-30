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
using namespace std;

int32_t N;
const int32_t H_MAX = 100000;
std::pair<int32_t, int32_t> S[100000];

#define MFOR(i,end) for(size_t i = 0, end_i = (end); i < end_i; ++ i)

class seg_tree
{
private:
	int32_t data[H_MAX * 4];

	inline int32_t get_par(int32_t n) { return (n - 1) / 2; }
	inline int32_t get_cld1(int32_t n) { return n * 2 + 1; }
	inline int32_t get_cld2(int32_t n) { return n * 2 + 2; }

	//[node_i_min,node_i_max)?node???[a,b)???????????
	int32_t get_max_impl(int32_t a, int32_t b, int32_t node, int32_t node_i_min, int32_t node_i_max)
	{
		//???
		if (b <= node_i_min || node_i_max <= a) { return 0; }
		//?????
		if (a <= node_i_min && node_i_max <= b) { return data[node]; }
		//????
		auto i_mid = (node_i_min + node_i_max) / 2;
		return std::max(
			get_max_impl(a, b, get_cld1(node), node_i_min, i_mid),//?
			get_max_impl(a, b, get_cld2(node), i_mid, node_i_max) //?
		);
	}
	//[node_i_min,node_i_max)?node?????
	void set_value_impl(int32_t pos, int32_t value, int32_t node, int32_t node_i_min, int32_t node_i_max)
	{
		//???
		if (pos < node_i_min || node_i_max <= pos) { return; }
		//??
		if (data[node] < value) {
			data[node] = value;
		}
		//???????
		if (node_i_min + 1 < node_i_max)
		{
			auto i_mid = (node_i_min + node_i_max) / 2;
			set_value_impl(pos, value, get_cld1(node), node_i_min, i_mid);//?
			set_value_impl(pos, value, get_cld2(node), i_mid, node_i_max);//?
		}
	}
public:
	seg_tree()
	{
		for (auto& i : data) {
			i = 0;
		}
	}

	inline int32_t get_max(int32_t a, int32_t b)
	{
		return get_max_impl(a, b, 0, 0, H_MAX+1);
	}
	inline void set_value(int32_t pos, int32_t value)
	{
		set_value_impl(pos, value, 0, 0, H_MAX+1);
	}
};

seg_tree seg_tree_;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;
	MFOR(i, N) {
		cin >> S[i].first >> S[i].second;
		S[i].second = -S[i].second;
	}
	std::sort(S, S + N);

	MFOR(i, N)
	{
		S[i].second = -S[i].second;
		seg_tree_.set_value(S[i].second, seg_tree_.get_max(0, S[i].second)+1);
	}

	cout << seg_tree_.get_max(0, H_MAX+1) << endl;
}