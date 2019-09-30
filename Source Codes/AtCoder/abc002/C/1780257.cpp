#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <utility>
#include <fstream>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define INF 1000000001
#define mod 1000000007
#define p pair<int,int>
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
using namespace std;

int main(){
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	cout<<fixed<<double(max((d-b)*(e-a)-(c-a)*(f-b),-1*(d-b)*(e-a)+(c-a)*(f-b)))/2<<endl;

}