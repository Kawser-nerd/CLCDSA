#include<deque>
#include<queue>
#include<map>
#include<string>
#include<iostream>
#include<set>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
//#define scanf scanf_s
#define fir first
#define sec second
#define mp make_pair
#define mt make_tuple
#define pub push_back
using namespace std;
typedef long long int llint;
const llint one = 1;
const llint big = (one<<30);
const llint mod=1000000007;


int main(void){
	llint N,L,T,i,j,a,b,c,d,e,isyu,syukai=0;
	vector<llint> ant;
	vector<llint> muki;
	vector<llint> gont;
	scanf("%lld %lld %lld",&N,&L,&T);
	isyu=(T/(2*L));
	T=(T%(2*L));
	gont.resize(N);
	for(i=0;i<N;i++){
		scanf("%lld %lld",&a,&b);
		ant.pub(a);
		muki.pub(b);
	}

	if(muki[0]==1){
		a=1;syukai=0;j=0;//a???????? j???
		while(-1){
			if(a>=N){a-=N;j++;}
			if(ant[0]+2*2*L<=ant[a]+j*L){break;}
			if(muki[0]!=muki[a]){syukai+=isyu;}
			a++;
		}
	} 
	else{
		a=N-1;syukai=0;j=-1;//a???????? j???
		while(-1){
			if(a<0){a+=N;j--;}
			if(ant[0]-2*2*L>ant[a]+j*L){break;}
			if(muki[0]!=muki[a]){syukai-=isyu;}
			a--;
		}
	}

	if(muki[0]==1){
		a=1;b=0;j=0;//a???????? j???
		while(-1){
			if(a>=N){a-=N;j++;}
			if(ant[0]+2*T<=ant[a]+j*L){break;}
			if(muki[0]!=muki[a]){b++;}
			a++;
		}
	} 
	else{
		a=N-1;b=0;j=-1;//a???????? j???
		while(-1){
			if(a<0){a+=N;j--;}
			if(ant[0]-2*T>ant[a]+j*L){break;}
			if(muki[0]!=muki[a]){b--;}
			a--;
		}
	}
	b+=syukai;
	//ant[N-b]????0?
	for(i=0;i<N;i++){
		if(muki[i]==1){gont[i]=(2000*L+ant[i]+T)%L;}
		else{gont[i]=(2000*L+ant[i]-T)%L;}
	}
	c=gont[0];
	sort(gont.begin(),gont.end());
	llint hon=lower_bound(gont.begin(),gont.end(),c)-gont.begin();
	d=(hon-b+N*10000)%N;//??????0
	for(i=0;i<N;i++){
		printf("%lld\n",gont[d]);
		d++;
		d%=N;
	}
	return 0;
}