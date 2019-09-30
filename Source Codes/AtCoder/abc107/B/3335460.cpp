#include<iostream>
using namespace std;
#define F(i) for(int i=0;i<n;i++)
#define G(i) for(int i=0;i<m;i++)
const int N=111;
char c[N][N];
bool L[N],C[N];
int n,m;
int main(){
	cin>>n>>m;
	F(i)G(j)
		cin>>c[i][j];
	F(i)G(j)
		L[i]|=c[i][j]=='#';
	G(i)F(j)
		C[i]|=c[j][i]=='#';
	F(i){
		G(j)
			if(L[i]&&C[j])
				cout<<c[i][j];
		if(L[i])
			cout<<endl;
	}
	return 0;
}