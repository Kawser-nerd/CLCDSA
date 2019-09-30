#include<iostream>
#include<stdio.h>
#include<string.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=102;
int i,j,ca,ti,n,m;
char g[maxn][maxn];
int main(){
	freopen("a2.in","r",stdin);
	freopen("a2.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cout<<"Case #"<<ti<<":"<<endl;
		cin>>n>>m;
		memset(g,0,sizeof(g));
		fr(i,1,n)
			scanf("%s",g[i]+1);
		bool ok=true,found;
		do{
			found=false;
			fr(i,1,n){
				fr(j,1,m)
					if(g[i][j]=='#'){
						found=true;
						if(g[i][j+1]=='#'&&g[i+1][j]=='#'&&g[i+1][j+1]=='#'){
							g[i][j]='/';
							g[i][j+1]='\\';
							g[i+1][j]='\\';
							g[i+1][j+1]='/';
						}
						else
							ok=false;
						break;		
					}
				if(found)
					break;
			}
		}while(found&&ok);
		if(ok)
			fr(i,1,n){
				fr(j,1,m)
					printf("%c",g[i][j]);
				cout<<endl;
			}
		else
			cout<<"Impossible"<<endl;
	}
}