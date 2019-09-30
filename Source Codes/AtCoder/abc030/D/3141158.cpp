#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

int b[100005];
int visit[100005];
vector<pair<int,int> >vec;
vector<int>vec2;

int main() {

	int N,a;

	scanf("%d %d",&N,&a);

	namespace mp = boost::multiprecision;
	using Bint = mp::cpp_int;

	string k;

	cin>>k;

	int i;

	for(i=1;i<=N;i++){
		scanf(" %d",&b[i]);
	}

	int cnt=1;
	int pos=a;

	int alpha;
	int beta;

	while(1){
		if(visit[pos]>0){
			alpha=cnt-visit[pos];
			beta=visit[pos]-2;
			break;
		}
		visit[pos]=cnt;
		vec2.push_back(pos);
		pos=b[pos];
		cnt++;
	}

	for(i=0;i<alpha;i++){
		if(i==alpha-1){vec.push_back(make_pair(pos,0));}
		else{vec.push_back(make_pair(pos,i+1));}
		pos=b[pos];
	}

	Bint cycle=alpha;
	Bint div=beta;
	Bint step(k);

	if(step<=div){
		cout<<vec2[atoi(k.c_str())]<<endl;
	}
	else{
		Bint mod=(step-div)%cycle;
		for(i=0;i<alpha;i++){
			Bint hit=vec[i].second;
			if(hit==mod){
				cout<<vec[i].first<<endl;
				return 0;
			}
		}
	}


	return 0;
}