//cj2.c
#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <map>
#include <stack>
using namespace std;
//Input macros
#define si(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n);
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define mem(a,b) memset(a,b,sizeof(a))
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define frev(i,a,b) for(ll i=a;i>=b;i--)
#define maX(a,b) ((a)>(b)?a:b)
#define miN(a,b) ((a)<(b)?a:b)
#define ll long long
#define ld long
#define llu unsigned long long
#define pb push_back
#define gc getchar_unlocked
#define fs first
#define sn second
#define ls (node<<1)
#define rs (node<<1)|1
vector<char> v;
int lps[20];
int yes[30];
char str[20],pat[20];
int k,l,s;
char temp[20];
int resmax=0;
int cnt[10];
double ans=0;
void compute_prefix(char *pattern){
	int n=strlen(pattern); 
	lps[0]=0;
    int len=0,i=1;
    while(i<n){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0) len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
int kmp_matcher(char *given,char *pattern){
	int n=strlen(given),m=strlen(pattern);
	compute_prefix(pattern);
	int j=0,i=0;
    int ans=0;
    while(i<n){
        if(given[i]==pattern[j]) i++,j++;
        if(j==m){
            ans++;
            if(i<n) j=lps[m-1];
        }
        else if(i<n && given[i]!=pattern[j]){
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
    return ans;
}
void rec(int ind)
{
	if(ind==s){
		temp[ind]='\0';
		//printf("%s\n",temp);
		int k=kmp_matcher(temp,pat);
		resmax=max(k,resmax);
		return;
	}
	for(int i=0;i<v.size();i++){
		temp[ind]=v[i];
		rec(ind+1);
	}
}
void rec2(int ind)
{
	if(ind==s){
		temp[ind]='\0';
		//printf("%s\n",temp);
		int u=kmp_matcher(temp,pat);
		double prob=1.0;
		for(int i=0;i<s;i++){
			prob=prob*(yes[temp[i]-'A']/(double)k);
		}
		//printf("prob=  %lf\n",prob);
		ans+=(resmax-u)*prob;
		return;
	}
	for(int i=0;i<v.size();i++){
		temp[ind]=v[i];
		rec2(ind+1);
	}
}
void Readinput()
{
	si(k);si(l);si(s);
	ss(str);ss(pat);
}
void solve(int x)
{
	int i,j;
	mem(cnt,0);
	mem(yes,0);
	resmax=0;
	for(i=0;i<k;i++){
		if(!yes[str[i]-'A']){v.pb(str[i]);}
		yes[str[i]-'A']++;
	}
	compute_prefix(pat);
	rec(0);
	ans=0;
	rec2(0);
	printf("Case #%d: %.8lf\n",x,ans);
}
int main()
{
	int t;
	int x=0;
	si(t);
	while(t--){
		x++;
		v.clear();
		Readinput();
		solve(x);
	}
	return 0;
}