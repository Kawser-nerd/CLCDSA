#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool sortfunc(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
	if(get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
	return get<0>(a) < get<0>(b);
}

bool sortfunc2(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
	return get<2>(a) < get<2>(b);
}

struct CityID {
	char str[100000][13];
	int str_size = 0;
	vector<tuple<int, int, int> > raw;

	CityID(int n, int m, vector<tuple<int, int, int> > & r) {
		raw = r;
		str_size = m;
	}

	void createId() {
		sort(raw.begin(), raw.end(), sortfunc);
		int id = 0, pref = -1;
		for(auto &x: raw) {
			id++;
			if(pref != get<0>(x)) {
				id = 1;
				pref = get<0>(x);
			}
			sprintf(str[get<2>(x)], "%06d%06d", pref, id);
		}
	}

	void printId() {
			for(int i = 0; i < str_size; i++) {
				cout << str[i] << endl;
			}
	}

};

int main() {
	int N, M;
	cin >> N >> M;

	vector<tuple<int, int, int> > p(M);

	for(int i = 0; i < M; i++) {
		pair<int, int> x;
		cin >> x.first >> x.second;
		p[i] = make_tuple(x.first, x.second, i);
	}

	CityID ids(N, M, p);
	ids.createId();
	ids.printId();
}