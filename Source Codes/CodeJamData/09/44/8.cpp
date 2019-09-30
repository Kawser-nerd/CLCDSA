#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;
int N;
int R[100];
int X[100];
int Y[100];

int dist2[100][100];

inline int sq(int n){return n*n;}

bool f(const double rad)
{
	vector<pair<double,double> > vd;vd.clear();
	vector<long long> masks;masks.clear();
	//check all points that intersect any two circles with radius rad-R[i]
		double rj;
		double dx,dy,ix,iy2,gg;
	for(int i=0;i<N;++i)
	{
		double ri = rad-R[i];
		if(ri < 0){return false;}
		for(int j=0;j<N;++j)
		{
			rj = rad-R[j];
			if(rj<0){return false;}
			if(dist2[i][j]==0){continue;}
			ix = dist2[i][j] - rj*rj+ri*ri;
			ix /= 2*sqrt(dist2[i][j]);
			iy2 = ri*ri - ix*ix;
			if(iy2<0){continue;}
			iy2 = sqrt(iy2);
			//put points in
			dx = X[j]-X[i];
			dy = Y[j]-Y[i];
			gg = sqrt(dx*dx+dy*dy);
			dx /= gg;
			dy /= gg;
			vd.push_back(make_pair(X[i]+dx*ix - dy*iy2,Y[i]+dy*ix + dx*iy2));
			vd.push_back(make_pair(X[i]+dx*ix + dy*iy2,Y[i]+dy*ix - dx*iy2));
		}
	}
	//if(vd.size() == 2){return true;}
	for(int i=0;i<vd.size();++i)
	{
		long long el = 0;
		for(int j=0;j<N;++j)
		{
			dx = X[j]-vd[i].first;
			dy = Y[j]-vd[i].second;
			if(sqrt(dx*dx+dy*dy)+R[j] <= rad+1e-12)
			{
				el |= (1LL<<j);
			}
		}
		
		masks.push_back(el);
	}
	for(int i=0;i<N;++i)
	{
		long long el = 0;
		for(int j=0;j<N;++j)
		{
			dx = X[j]-X[i];
			dy = Y[j]-Y[i];
			if(sqrt(dx*dx+dy*dy)+R[j] <= rad+1e-12)
			{
				el |= (1LL<<j);
			}
		}
		masks.push_back(el);
	}
	const long long win = ((1LL<<(N)))-1LL;
	for(int i=0;i<masks.size();++i)
	{
		for(int j=0;j<masks.size();++j)
		{
			if((masks[i]|masks[j])==win)
			{return true;}
		}
	}
	return false;



}


int main(int argc,char **argv)
{
	int CASES;
	cin >> CASES;
	for(int cn=1;cn<=CASES;++cn)
	{
		cin >> N;
		for(int i=0;i<N;++i)
		{
			cin >> X[i] >> Y[i] >> R[i];
		}
		if(N==1)
		{
			printf("Case #%d: %.12lf\n",cn,(double)R[0]);
			continue;
		}
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<N;++j)
			{
				dist2[i][j] = sq(X[i]-X[j])+sq(Y[i]-Y[j]);
			}
		}
		double low = 1e-9;
		double high = 100000.0;
		double mid;
		for(int i=0;i<60;++i)
		{
			mid = (low+high)*0.5;
			if(f(mid))
			{
				high = mid;
			}
			else
			{
				low = mid;
			}
		}

		printf("Case #%d: %.12lf\n",cn,(low+high)*0.5);
	}
	return 0;
};
