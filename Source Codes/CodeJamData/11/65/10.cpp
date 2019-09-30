#include <cstdio>
#include <cmath>
#include <cstring>
#include <memory.h>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int maxn=22;
const int iter_step=16384;
const double eps=1e-6;
double opt[maxn];
int a,m,v;

void init(){
	scanf("%d%d%d",&a,&m,&v);
	memset(opt,0,sizeof(opt));
	return;
}

double calcprob(){
	for (int iter=1;iter<=iter_step;iter++){
		for (int i=1;i<=v;i++){
			for (int bet=1;bet<=i;bet++){
				double fwin;
				if ((i+bet)>=v){
					fwin=1;
				} else {
					fwin=opt[i+bet];
				}
				for (int mul=1;bet*mul<=m;mul*=2){
					double flose;
					if ((i-(2*mul-1)*bet)<=0){
						flose=0;
					} else {
						flose=opt[i-(2*mul-1)*bet];
					}
					double prob=1.0/(2.0*((double)mul));
					opt[i]=max(opt[i],(1.0-prob)*fwin+prob*flose);
				}
			}
		}
	}
	return opt[a];
}

void getmaxbet(){
	for (int bet=a;bet>=1;bet--){
		double fwin;
		if ((a+bet)>=v){
			fwin=1;
		} else {
			fwin=opt[a+bet];
		}
		for (int mul=1;mul*bet<=m;mul*=2){
			double flose;
			if ((a-(2*mul-1)*bet)<=0){
				flose=0;
			} else {
				flose=opt[a-(2*mul-1)*bet];
			}
			double prob=1.0/(2.0*((double)mul));
			double curans=(1.0-prob)*fwin+prob*flose;
			if (fabs(curans-opt[a])<=eps){
				printf("%d\n",bet);
				return;
			}
		}
	}
	return;
}

int main(){
	int tcase;
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		init();
		printf("Case #%d: %.10lf ",i,calcprob());
		getmaxbet();
	}
	return 0;
}