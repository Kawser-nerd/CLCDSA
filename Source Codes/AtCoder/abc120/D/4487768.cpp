#include<iostream>
#include<vector>
#include<algorithm>

using sll = signed long long;
using ui =  long int;
class disjoint_set {
	std::vector<int> p;

	auto link(int x, int y) {

		//x = find(x);
		//y = find(y);

		if(x==y)
			return false;

		
		if ( size(x) < size(y) )
			std::swap(x, y);
		
		
		p[x] += p[y];
		p[y] = x;
		return true;
	}

public:
	disjoint_set()
		:p{}{}

	disjoint_set(int size_) :
		p{}
	{
		p.resize(size_, int{-1});
	}

	auto find(int x)
		->decltype(p)::value_type {
		
		return p[x] < 0 ? 
			x : p[x] = find(p[x]);
	}


	auto same(int x, int y) {
		return
			find(x) == find(y);
	}

	auto unite(int x, int y) {
		this->link(find(x), find(y));
	}

	auto size(int x)
		->decltype(p)::value_type{
		return -p[ this->find(x) ];
	}

};

int main() {


	int n, m;
	std::cin >> n >> m;

	std::vector< std::pair<int, int> > vp;

	disjoint_set ds{ n };
	vp.resize(m);


	for (int i{}; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;

		vp[i] = std::make_pair(a-1, b-1);
	}



	auto it = std::rbegin(vp);
	auto end_ = std::rend(vp);

	auto ansi = sll{ n } *(n - 1) / 2;

	std::vector<sll> ans{};
	ans.resize(m, 0);
	ans[m - 1] = ansi;


	for (int i{m-1}; i > 0; --i) {
		
		auto a = it->first;
		auto b = it->second;

		ans[i-1] = ans[i];
//		std::cout << " ab " << a+1 << " " << b+1 << "\n";
		if (!ds.same(a, b)) {
			auto x = ds.size(a);
			auto y = ds.size(b);

			ans[i-1] -= x * y;
			ds.unite(a, b);
//			std::cout <<" xy "<< x << " " << y << "\n";
			if (ans[i-1] < 0 )
				ans[i-1] = 0;
		}
		++it;
	}


	for (auto&e : ans)
		std::cout << e << "\n";
	

	return 0;
}