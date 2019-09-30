#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define debug(x) cerr<<#x<<"="<<(x)<<endl;

void eval(){
	int X, S, R, T, N;
	int B[1000], E[1000], w[1000];
	scanf("%d %d %d %d %d", &X, &S, &R, &T, &N);
	map<int, double> speed;
	speed[0]=X;
	for(int i=0; i<N; i++){
		scanf("%d %d %d", B+i, E+i, w+i);
		int d=E[i]-B[i];
		speed[0]-=d;
		speed[w[i]]+=d;
	}
	double ans=0;
	double t=T;
	while(t>0 && speed.size()){
		map<int, double>::iterator slow=speed.begin();
		double tm=slow->second/(slow->first+R);
		if(tm>=t){
			ans+=t;
			slow->second-=t*(slow->first+R);
			break;
		}else{
			t-=tm;
			speed.erase(slow);
			ans+=tm;
		}
	}
	for(map<int, double>::iterator it=speed.begin(); it!=speed.end(); it++){
		ans+=it->second/(it->first+S);
	}
	printf("%.9lf\n", ans);
}

int main(){
	int cases;
	string line;
	getline(cin, line);
	istringstream(line)>>cases;
	for(int i=1; i<=cases; i++){
		cout<<"Case #"<<i<<": ";
		eval();
	}
	return 0;
}
