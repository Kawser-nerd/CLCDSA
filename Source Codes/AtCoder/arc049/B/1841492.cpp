#include <iostream>
#include <algorithm>
using namespace std;
 
long double const INF=100000001;
int main() {
	int N;
	cin >> N;
	
	long double x[N], y[N], c[N];
	for(int i=0; i<N; i++){
		cin >> x[i] >> y[i] >> c[i];
	}
	
	long double cx_max=-INF, cx_min=INF, cy_max=-INF, cy_min=INF;
	long double c_of_x_max, c_of_x_min, c_of_y_max, c_of_y_min;
	
	for(int i=0; i<N; i++){
		if(cx_max<x[i]*c[i]){cx_max=x[i]*c[i]; c_of_x_max=c[i];}
		if(cy_max<y[i]*c[i]){cy_max=y[i]*c[i]; c_of_y_max=c[i];}
		if(cx_min>x[i]*c[i]){cx_min=x[i]*c[i]; c_of_x_min=c[i];}
		if(cy_min>y[i]*c[i]){cy_min=y[i]*c[i]; c_of_y_min=c[i];}
	}
	
	long double ansx=(cx_max/c_of_x_max - cx_min/c_of_x_min)*c_of_x_max*c_of_x_min /(c_of_x_max + c_of_x_min);
	long double ansy=(cy_max/c_of_y_max - cy_min/c_of_y_min)*c_of_y_max*c_of_y_min /(c_of_y_max + c_of_y_min);
	cout<<max(ansx,ansy)<<endl;
	
	
	return 0;
}