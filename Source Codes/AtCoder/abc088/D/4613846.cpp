#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>


struct pos {
	int x, y;
	pos(int xv, int yv) :x{ xv }, y{ yv }{}
};

int main() {

	constexpr static const auto inf = (1 << 30);

	auto put = [&](const auto&container) {

		for (const auto& e : container) {
			for (const auto& ee : e) {
				std::cout << ee<<" ";
			}std::cout << "\n";
		}

	};


	int H, W;
	std::cin >> H >> W;

	std::vector<std::string> tab(H);
	std::vector<std::vector<int>> count(H, std::vector<int>(W, inf));

	for (auto&e : tab)
		std::cin >> e;

	std::queue<pos> q;

	q.emplace(0,0);
	count[0][0] = 1;

	const int dx[] = { 1,0,-1,0 };
	const int dy[] = { 0,1,0,-1 };

	while (!q.empty()) {
		const auto p = q.front(); q.pop();

		//if (p.x == H - 1 && p.y == W - 1)
		//	break;


		for (int i{}; i < 4; ++i) {

			const int cx = p.x + dx[i];
			const int cy = p.y + dy[i];

			if (cx < 0 || cy < 0 || H <= cx || W <= cy)
				continue;

			if (tab[cx][cy] == '#')
				continue;


			if (count[cx][cy] > count[p.x][p.y] + 1) {
				count[cx][cy] = count[p.x][p.y] + 1;
				q.emplace(cx, cy);
			}
//			std::cout << count[cx][cy]<<" "<< cx << " " << cy << "\n";
//			put(count);
		}

	}


	if (count[H - 1][W - 1] == inf) {
		std::cout << "-1\n";
	}
	else {

		auto sum = 0;
		for (const auto&e : tab) {
			sum += std::count(std::begin(e), std::end(e), '.');
		}

		sum -= count[H - 1][W - 1];
		std::cout << sum << "\n";
	}
	return 0;
}