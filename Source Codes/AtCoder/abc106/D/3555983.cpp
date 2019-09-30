#include<iostream>
#include<cinttypes>
#include<vector>

using ull = unsigned long long;
using ui = std::uint16_t;


struct pos {
	ui left, right;
	friend auto& operator>>(std::istream&is, pos&p) {
		return is >> p.left >> p.right;
	}
};

int main() {


	std::vector<std::vector<ull>> LR{};
	std::vector<std::vector<ull>> tab{};
//	std::vector<pos> pv;
//	pv.resize(505);

	LR.resize(505);
	tab.resize(505);

	for (auto&e : LR)
		e.resize(505);

	for (auto&e : tab)
		e.resize(505);

	ull n, m, q;

	std::cin >> n >> m >> q;

	for (ull i{1}; i <= m; ++i) {
		pos p;
		std::cin >> p;
//		std::cout << "\t>>" << p.left << ", " << p.right << "\n";
		++LR[p.left][p.right];
	}

	for (ull i{ 1 }; i < 505; ++i)
		for (ull j{ 1 }; j < 505; ++j)
			tab[i][j] = tab[i][j - 1] + LR[i][j];

/*
	for (int i{1}; i <= n; ++i) {
		for (int j{}; j <= n; ++j)
			std::cout << LR[i][j] << " ";
		std::cout << " | ";

		for (int j{1}; j <= n; ++j)
			std::cout << tab[i][j] << " ";

		std::cout << "\n";
	} 
*/

	for (ull i{1}; i <= q; ++i) {
		ull pi, qi;
		std::cin >> pi >> qi;
		
		ull c{};
		for (ull j{ pi }; j <= qi; ++j) {
			auto here = tab[j][qi]
				, pre = tab[j][pi - 1];
			
			c += here - pre;

//			std::cout << i << ", " << j << " here-pre "
//				<< here << ", " << pre << "\n";
		}
		std::cout << c << "\n";

	}


	return 0;
}