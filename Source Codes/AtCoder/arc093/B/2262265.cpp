#include <iostream>
#include <cmath>

using pair = std::pair<int, int>;

constexpr int max_hw = 100;

int a, b;
char field[max_hw][max_hw];

int main(){

	std::cin >> a >> b;

	std::cout << max_hw << ' ' << max_hw << std::endl;
	pair diff[max_hw][max_hw]; //diff 1:w 2:b
	for(int i = 0; i < max_hw; ++i){
		for(int j = 0; j < max_hw; ++j){
			if(j >= max_hw / 2){
				field[i][j] = '#';
			}
			else{
				field[i][j] = '.';
			}
		}
	}

	int x = 51, y = 0;
	while(a > 1){
		if(x < max_hw && y < max_hw && x >= 51 && y >= 0){
			field[y][x] = '.';
			x += 2;
			--a;
		}
		else{
			x = 51, y += 2;
		}
	}

	x = 0, y = 0;
	while(b > 1){
		if(x < max_hw / 2 - 1 && y < max_hw && x >= 0 && y >= 0){
			field[y][x] = '#';
			x += 2;
			--b;
		}
		else{
			x = 0, y += 2;
		}
	}

	for(int i = 0; i < max_hw; ++i){
		for(int j = 0; j < max_hw; ++j){
			std::cout << field[i][j];
		}
		std::cout << std::endl;
	}

	return 0;
}