#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 2010;

double t[maxn], x[maxn];
int task, cs=0, n, T;
double D;

int main(){
	//freopen("B-small-attempt0.in","r",stdin);
	freopen("B-large.in","r",stdin);
	freopen("a.out","w",stdout);

	for(scanf("%d", &task); task--;){
		printf("Case #%d:\n", ++cs);
		scanf("%lf%d%d", &D, &n, &T);
		for (int i=0; i<n; i++){
			scanf("%lf%lf", t+i, x+i);
		}
		while ( n-2>=0 && x[n-2]>D ) n--;
		if ( x[n-1]>D ){
			double v = (x[n-1]-x[n-2])/(t[n-1]-t[n-2]);
			x[n-1] = D;
			t[n-1] = t[n-2]+(D-x[n-2])/v;
		}

		while (T--){
			double dist=0, tm=0, v=0, a;
			scanf("%lf", &a);
			for (int i=0; i<n-1; i++){
				double deltaT = t[i+1]-t[i], deltaX = x[i+1]-x[i];
				double deltaV = deltaX / deltaT;

				double mine = dist+v*deltaT+0.5*a*deltaT*deltaT;
				if ( mine>x[i+1] ){
					double A = 0.5*a, B = v, C = -(x[i+1]-dist);
					double deltaT = ( -B+sqrt(B*B-4*A*C) ) / (2*A);

					dist = x[i+1];
					tm = t[i+1];
					v += a*deltaT;
				}else{
					dist = mine;
					tm = t[i+1];
					v += a*deltaT;
				}
			}
			if ( dist+1e-6 < D ){
				double A = 0.5*a, B = v, C = -(D-dist);
				double deltaT = ( -B+sqrt(B*B-4*A*C) ) / (2*A);
				tm += deltaT;
			}
			printf("%.6lf\n", tm);
		}
	}
	return 0;
}
