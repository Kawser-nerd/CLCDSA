#include <iostream>
using namespace std;
const int MC = 200010;
int N,M;
bool x[MC] , y[MC];

bool judge(){
	for (int v=0;v<N;v++)
		if(x[v] && y[v]) return 1;
	return 0;
}

int main(){
	cin>>N>>M;
	for (int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		if(a==1) x[b] = 1;
		if(b==N) y[a] = 1;
	}
	if (judge()==true)
        cout<<"POSSIBLE";
    else
        cout<<"IMPOSSIBLE";
	return 0;
}