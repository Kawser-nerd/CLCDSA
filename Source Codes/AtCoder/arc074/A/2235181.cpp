#include <iostream>
#include <algorithm>
#include <limits>

using ull = unsigned long long;

constexpr ull INF = std::numeric_limits<ull>::max();

ull H, W;

int main(){
	
	std::cin >> H >> W;

	if(H % 3 == 0 || W % 3 == 0){
		std::cout << 0 << std::endl;
		return 0;
	}

	ull ans = INF;

	for(int i = 1; i < H; ++i){
		ull s1[3] = {i * W, (H - i) * (W / 2), (H - i) * (W - (W / 2))};
		std::sort(s1, s1 + 3);
		ans = std::min(ans, s1[2] - s1[0]);
		ull s2[3] = {i * W, ((H - i) / 2) * W, ((H - i) - (H - i) / 2)  * W};
		std::sort(s2, s2 + 3);
		ans = std::min(ans, s2[2] - s2[0]);
	}
	for(int i = 1; i < W; ++i){
		ull s1[3] = {i * H, (W - i) * (H / 2), (W - i) * (H - (H / 2))};
		std::sort(s1, s1 + 3);
		ans = std::min(ans, s1[2] - s1[0]);
		ull s2[3] = {i * H, ((W - i) / 2) * H, ((W - i) - (W - i) / 2)  * H};
		std::sort(s2, s2 + 3);
		ans = std::min(ans, s2[2] - s2[0]);
	}
	std::cout << ans << std::endl;

	return 0;
}