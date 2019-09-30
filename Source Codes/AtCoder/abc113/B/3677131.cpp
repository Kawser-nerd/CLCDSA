#include<iostream>
using namespace std;
int main(){
	int n,T,A,p[1005],min=999999,k=0;
	cin>>n>>T>>A;
	double x=(T-A)/0.006;
	for(int i=0;i<n;i++){
		cin>>p[i];
		double y=x-p[i];
		if(y<0) y=-y;
		if(y<min){
			min=y; k=i;
		}
	}
	cout<<k+1<<endl;
	return 0;
}