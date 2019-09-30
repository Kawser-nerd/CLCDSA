#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

ifstream in;
ofstream out;

int main(int argc, char** argv)
{
	in.open(argv[1]);
	out.open(argv[2]);

	int T;
	in >> T;

	string s;
	getline(in, s);

	for(int i = 0; i < T; ++i)
	{
		string s;
		getline(in, s);
		int v[64];
		int dv[256];
		int n = 0;
		memset(dv, 0xff, sizeof(dv));

		for(unsigned j = 0; j < s.size(); ++j)
		{
			unsigned char c = (unsigned char)s[j];
			if(dv[c] >= 0)
				v[j] = dv[c];
			else
			{
				int cv;
				if(!j)
					cv = 1;
				else
				{
					cv = n++;
					if(n == 1)
						++n;
				}
				v[j] = cv;
				dv[c] = cv;
			}
		}

		if(n == 0)
			n = 2;

		unsigned long long r = 0ULL;

		for(unsigned j = 0; j < s.size(); ++j)
		{
			r = r * (unsigned long long)n;
			r += (unsigned long long)v[j];
		}

		out << "Case #" << (i + 1) << ": " << r << endl;
	}
	return 0;
}
