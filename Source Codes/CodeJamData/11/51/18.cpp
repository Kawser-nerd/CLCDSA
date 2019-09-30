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
const int maxn=101;
const int max_iter=100;
double ax[maxn],ay[maxn],bx[maxn],by[maxn];
int w,l,u,g;

void init(){
	scanf("%d%d%d%d",&w,&l,&u,&g);
	for (int i=0;i<l;i++){
		scanf("%lf%lf",&ax[i],&ay[i]);
	}
	for (int i=0;i<u;i++){
		scanf("%lf%lf",&bx[i],&by[i]);
	}
	return;
}

double calcarea(double p){
	double sa=0;
	double sb=0;
	for (int i=0;i<l;i++){
		if ((ax[i+1]+(1e-9))<=p){
			sa+=0.5*(ay[i]+ay[i+1])*(ax[i+1]-ax[i]);
			continue;
		}
		double tx=p;
		double slope=((ay[i+1]-ay[i])/(ax[i+1]-ax[i]));
		double ty=slope*(tx-ax[i])+ay[i];
		sa+=0.5*(ay[i]+ty)*(tx-ax[i]);
		break;
	}
	for (int i=0;i<u;i++){
		if ((bx[i+1]+(1e-9))<=p){
			sb+=0.5*(by[i]+by[i+1])*(bx[i+1]-bx[i]);
			continue;
		}
		double tx=p;
		double slope=((by[i+1]-by[i])/(bx[i+1]-bx[i]));
		double ty=slope*(tx-bx[i])+by[i];
		sb+=0.5*(by[i]+ty)*(tx-bx[i]);
		break;
	}
	return sb-sa;
}

void bisearch(double area){
	double l=0;
	double r=(double)w;
	for (int k=1;k<=max_iter;k++){
		double mid=(l+r)*0.5;
		if (calcarea(mid)<area){
			l=mid;
		} else {
			r=mid;
		}
	}
	printf("%.10f\n",l);
	return;
}

void process(){
	double tot=calcarea((double)w);
	for (int i=1;i<g;i++){
		double curarea=tot/((double)g)*((double)i);
		bisearch(curarea);
	}
	return;
}

int main(){
	int tcase;
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		init();
		printf("Case #%d:\n",i);
		process();
	}
	return 0;
}
