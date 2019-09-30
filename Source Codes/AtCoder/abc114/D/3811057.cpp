#include<iostream>
#include<vector>
#include<algorithm>

using ui = unsigned int;

struct recode {
	ui lv;
	recode(ui x) :lv{
		[=]()->ui {
			ui c = 0;
			for (const ui e : {2, 4, 14, 24, 74}) {
				if (e <= x)
					c += 1;
				else
					break;
				return c;
			}
		}()
	}{}
};

int main() {
	ui dtab[105]{};


	ui n;
	std::cin >> n;

	for (ui i{2}; i < n+1; ++i) {


		auto x = i;
		for (ui j{ 2 }; j <= i; j+=(j==2?1:2)) {
			while (x%j == 0) {
				++dtab[j];
				x /= j;
			}
		}


	}

	/*
	for (ui i{0};i<105;++i)
		std::cout <<"["<<i<<":"<< dtab[i]<<"]"
			<< ( i%10!=0 ? " " : "\n" );
	*/
	int ar[5]; ui idx{ 0 };
	for (const ui e : {2, 4, 14, 24, 74}) {
		ar[idx]
			= std::count_if(std::begin(dtab), std::end(dtab)
			, [=](auto x)->bool {
				return e <= x;
			}
		);
		idx++;
	}
	
/*
	for (auto&e : ar)
		std::cout << e << " ";
	std::cout << "\n";
*/

	auto res =
		[&]()->int {
		auto a = ar[0] >= 2 && ar[1] >= 1 ?
			(ar[0] - 2)*(ar[1] - 1)* ar[1]/2 : 0;
//		abc?bac???????????2???
//		std::cout << ar[0] - 2 <<" "<<ar[1]-1<<  "\n";

		auto b = ar[1] > 0 ? (ar[1] - 1)*ar[2] : 0;

		auto c = ar[0] > 0 ? (ar[0] - 1)*ar[3]:0;
//		std::cout << a << " " << b << " " << c << "\n";
		return a + b + c + ar[4];
	}();
	std::cout << res << "\n";

	return 0;
} ./Main.cpp:20:3: warning: control may reach end of non-void lambda [-Wreturn-type]
                }()
                ^
1 warning generated.