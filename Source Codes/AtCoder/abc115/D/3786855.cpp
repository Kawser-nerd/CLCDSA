#include<iostream>
#include<vector>

using sll = signed long long;
using ui = unsigned int;

auto ui_cast(sll s) {
	return static_cast<ui>(s);
}

template<class T>
class rec {
private:
	const T t;
public:
	rec(const T& t_) :t{ t_ } {}
	rec(T&&t_) :t{ t_ } {}
	auto operator()(sll n, sll x)->sll {
		if (n == 0)
			return 1 <= x ? 1 : 0;

		auto idx = ui_cast(n) - 1;
		auto& e = t[idx];

		if (x <= e.first + 1)
			return this->operator()(n - 1, x - 1);
		else
			return
				e.second + 1
				+this->operator()(n - 1, x - 2 - e.first);
	}
};


int main() {
	sll n, x;
	std::cin >> n >> x;

	std::vector<std::pair<sll,sll>> apn;
	apn.resize(ui_cast(n));
	apn.front() = { 1,1 };
	
	for (ui i{ 1 }; i < ui_cast(n); ++i) {
		auto&e = apn[i];
		auto& pe = apn[i - 1];
		e.first = 2*pe.first+3;
		e.second = 2*pe.second+1;
	}
	rec<decltype(apn)> r{ std::move(apn) };

	std::cout<<r(n, x)<<"\n";
	return 0;
}