#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

ifstream in;
ofstream out;

int main(int argc, char** argv)
{
	in.open(argv[1]);
	out.open(argv[2]);

	int T;
	in >> T;

	for(int it = 1; it <= T; ++it)
	{
		int P, Q;
		in >> P >> Q;

		vector<int> cells;
		cells.push_back(0);

		for(int i = 0; i < Q; ++i)
		{
			int c;
			in >> c;
			cells.push_back(c);
		}

		cells.push_back(P + 1);

		int mat[128][128];
		memset(mat, 0, sizeof(mat));

		//cout << "Case " << it << endl;
		for(int d = 2; d < Q + 2; ++d)
		{
			for(int i = 0; i < Q + 2 - d; ++i)
			{
				int j = i + d;
				int bcost = INT_MAX;
				for(int k = i + 1; k < j; ++k)
				{
					bcost = min(bcost, mat[i][k] + mat[k][j] + cells[j] - cells[i] - 2);
				}
				mat[i][j] = bcost;
				//cout << i << ' ' << j << ": " << bcost << endl;
			}
		}

		out << "Case #" << it << ": " << mat[0][Q + 1] << endl;
	}

	return 0;
}
