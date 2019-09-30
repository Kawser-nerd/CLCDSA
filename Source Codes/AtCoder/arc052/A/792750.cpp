#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b)-1);i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int, int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))

int main(void){
	string s;
	cin >> s;
	char num[10] = {'0', '1', '2', '3', '4', '5' ,'6', '7', '8', '9'};
	int y=0;
	rep(i, s.size()) rep(j, 10) if(s[i]==num[j]){
		if(y==0) y=j;
		else y = y*10+j;
	}
	cout << y << endl;
	return 0;
}