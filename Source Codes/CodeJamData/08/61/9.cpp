#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <complex>
#include <cmath>
using namespace std;
typedef long long LL;

int BHmin=100000000, BHmax=0;
int BWmin=100000000, BWmax=0;

int categorize(int w, int h)
{
	if( h < BHmin ) {
		if( w < BWmin ) return 5;
		if( w <= BWmax ) return 4;
		return 3;
	} else if( h<=BHmax ) {
		if( w < BWmin ) return 6;
		if( w <= BWmax ) return 0;
		return 2;
	} else {
		if( w < BWmin ) return 7;
		if( w <= BWmax ) return 8;
		return 1;
	}
}

int main()
{
	int NC; cin >> NC;
	for(int ID=1; ID<=NC; ++ID)
	{
		cout << "Case #" << ID << ":" << endl;

		BHmin=100000000, BHmax=0;
		BWmin=100000000, BWmax=0;
		vector<int> NBH, NBW;

		int N; cin >> N;
		int BC = 0;
		for(int j=0; j!=N; ++j)
		{
			int H, W;
			string X;
			cin >> H >> W; getline(cin,X);
			if( X==" BIRD" )
			{
				BHmin = min(BHmin, H);
				BHmax = max(BHmax, H);
				BWmin = min(BWmin, W);
				BWmax = max(BWmax, W);
				++BC;
			}
			else
			{
				NBH.push_back(H);
				NBW.push_back(W);
			}
		}

if(BC==0) {
		set< pair<int,int> > NB;
		for(int j=0; j!=NBH.size(); ++j)
		{
			int H = NBH[j], W = NBW[j];
			NB.insert( make_pair(W,H) );
		}

		int M; cin >> M;
		for(int j=0; j!=M; ++j)
		{
			int H, W;
			cin >> H >> W;
			cout << (NB.count(make_pair(W,H)) ? "NOT BIRD" : "UNKNOWN") << endl;
		}
} else {
		int M; cin >> M;
		for(int j=0; j!=M; ++j)
		{
			int H, W;
			cin >> H >> W;

			int C = categorize(W,H);
			if( C == 0 ) {
				cout << "BIRD" << endl;
			} else {
				bool NotBird = false;
				for(int j=0; j!=NBH.size(); ++j)
				{
					int HH = NBH[j], WW = NBW[j];
					int C = categorize(WW,HH);

					switch(C) {
					case 1: NotBird |= (H>=HH && W>=WW); break;
					case 2: NotBird |= (W>=WW); break;
					case 3: NotBird |= (H<=HH && W>=WW); break;
					case 4: NotBird |= (H<=HH); break;
					case 5: NotBird |= (H<=HH && W<=WW); break;
					case 6: NotBird |= (W<=WW); break;
					case 7: NotBird |= (H>=HH && W<=WW); break;
					case 8: NotBird |= (H>=HH); break;
					}
				}
				cout << (NotBird ? "NOT BIRD" : "UNKNOWN") << endl;
			}
		}
}
	}
}
