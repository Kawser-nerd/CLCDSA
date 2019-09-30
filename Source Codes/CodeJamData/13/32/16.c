#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

#define MAXN 30000
#define MAXM 30000


short m[MAXN][MAXM];

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};


ifstream fin;
ofstream fout;

long h(long i) {
	return (i < 0) ? 2 * (-i) + 1 : 2 * i;
}


void print_res(int x, int y, long k) {
	short from;
	if (k != 0) {
		from = m[h(x)][h(y)];
		print_res(x - dx[from] * k, y - dy[from] * k, k - 1);
		if (from == 0)
			fout << "W";
		else if (from == 1)
			fout << "S";
		else if (from == 2)
			fout << "E";
		else if (from == 3)
			fout << "N";
	}
}


int main() {
	deque<long> x_queue;
	deque<long> y_queue;
	deque<long> k_queue;

	fin.open("b.in");
	fout.open("b.out");

	int T = 0;

	fin >> T;

	for (int i = 0; i != T; i++) {
		memset(m, -1, sizeof(short) * MAXN * MAXM);

		long tx, ty;
		long cx, cy, ck;
		bool flag = false;
		fin >> tx >> ty;

		x_queue.clear();
		y_queue.clear();
		k_queue.clear();

		x_queue.push_back(0);
		y_queue.push_back(0);
		k_queue.push_back(1);

		int step = 0;

		while (x_queue.size() && !flag) {

			step++;

			cx = x_queue.front(); x_queue.pop_front();
			cy = y_queue.front(); y_queue.pop_front();
			ck = k_queue.front(); k_queue.pop_front();


			for (int j = 0; j != 4 && !flag; j++) {
				long ccx = cx + dx[j] * ck;
				long ccy = cy + dy[j] * ck;
				if (h(ccx) >= MAXN || h(ccy) >= MAXN)
					continue;
				if (m[h(ccx)][h(ccy)] == -1) {
					m[h(ccx)][h(ccy)] = j;
					x_queue.push_back(ccx);
					y_queue.push_back(ccy);
					k_queue.push_back(ck + 1);

					if (ccx == tx && ccy == ty) {
						cout << ccx << ccy << " " << ck << endl;
						fout << "Case #" << i + 1 << ": ";
						print_res(tx, ty, ck);
						fout << endl;
						flag = true;
					}
				}
			}
		}
	}



	return 0;
}