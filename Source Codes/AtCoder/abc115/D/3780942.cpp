#include<iostream>
#include<vector>

using ui = unsigned int;
using ull = unsigned long long;
using sll = signed long long;

template<class C>
auto f(sll n, sll x,const C&apn)->sll {
//	std::cout << n <<" "<< x << "\n";

	if (n == 0)
		return 1 <= x ? 1 : 0;
	
	auto u_index = static_cast<ui>(n) - 1;

	if (x <= apn[u_index].first + 1 )
		return f(n - 1, x - 1,apn);
	else
		return apn[u_index].second + 1
		+ f(n - 1, x - 2 - apn[u_index].first, apn);
}



int main() {
	
	//ui n;
	
	sll n,x;
	std::cin >> n >> x;

	std::vector<std::pair<sll, sll>> apn;
	apn.resize(static_cast<ui>(n));
	apn[0] = { 1,1 };

	for (ui i{ 1 }; i < static_cast<ui>(n); ++i) {
		apn[i].first = 3 + 2 * apn[i - 1].first;
		apn[i].second = 1 + 2 * apn[i - 1].second;
	}

	std::cout << f(n, x, apn) << "\n";

	return 0;
}