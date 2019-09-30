#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

ofstream fout("../../output.txt");
ifstream fin("../../input.txt");


long long lows[500];
long long highs[500];
long long misses[500];
bool ismiss[500];
bool isvalid[500];

long long trinum(long long a)
{
	return a*(a+1)/2;
}

vector<long long> solve(long long totsum, long long L)
{
	long long num = (2*totsum - L*L + L);
	long long denom = 2*L;
	long long mod = num%denom;
	if(mod!=0)
	{
		while(mod<0)
			mod+=denom;
		num-=mod;
	}
	long long a = num / denom;
	long long b = a + L;
	long long tot = trinum(b)-trinum(a-1);
	long long miss = tot - totsum;
	vector <long long> ans;
	ans.push_back(a);
	ans.push_back(b);
	ans.push_back(miss);
	return ans;
}

void show(int a)
{
	cout << lows[a] << " "  << highs[a] << " " << ismiss[a] << " " << misses[a] << endl;
}

void merge(int a, int b)
{

	//show(a);
	//show(b);
	long long num = highs[a]-lows[a];
	if(!ismiss[a])
		num++;
	num += highs[b]-lows[b];
	if(!ismiss[b])
		num++;
	long long relsum = trinum(highs[a])-trinum(lows[a]-1) + trinum(highs[b])-trinum(lows[b]-1);
	if(ismiss[a])
		relsum-=misses[a];
	if(ismiss[b])
		relsum-=misses[b];
	vector<long long> tmp = solve(relsum,num);
	isvalid[b]=false;
	lows[a]=tmp[0];
	highs[a]=tmp[1];
	ismiss[a]=true;
	misses[a]=tmp[2];
	if(misses[a]==lows[a])
	{
		lows[a]++;
		ismiss[a]=false;
	}
	else if(misses[a]==highs[a])
	{
		highs[a]--;
		ismiss[a]=false;
	}
	//show(a);
	//cout << endl;
}


int main(void)
{
	int ttt;
	fin >> ttt;
	int ct = 0;
	string s;
	fout.precision(19);
	cout.precision(19);
	while(ttt>0)
	{
		ct++;
		ttt--;
		int n,i,j,k;
		long long p,v;
		fin >> n;
		long long tot = 0;
		for(i=0; i<n; i++)
		{
			fin >> p >> v;
			if(v%2==1)
			{
				lows[i]=p-v/2;
				highs[i]=p+v/2;
				ismiss[i]=false;
			}
			else
			{
				lows[i]=p-v/2;
				highs[i]=p+v/2;
				ismiss[i]=true;
				misses[i]=p;
			}
			tot += p*p*v;
			isvalid[i]=true;
		}
		
		for(int a=0; a<n; a++)
		{
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					if(!isvalid[i] || !isvalid[j] || i==j)
						continue;
					if(lows[i] > highs[j] || lows[j] > highs[i])
						continue;
					merge(i,j);
				}
			}
		}
		
		long long newtot = 0;
		
		for(i=0; i<n; i++)
		{
			if(!isvalid[i])
				continue;
			for(long long curr = lows[i]; curr<=highs[i]; curr++)
			{
				if(ismiss[i] && curr==misses[i])
					continue;
				newtot+=curr*curr;
			}
		}
		
		long long ans = (newtot - tot)/2;
		
		
		cout << "Case #" << ct << ": " << ans << endl;
		fout << "Case #" << ct << ": " << ans << endl;
		
	}
	
	
	return 0;
}



