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

long long nums[500];

long long sums[1<<20];

bool cmp(pair<long long, int> a, pair<long long,int> b)
{
	return (a.first<b.first);
}

vector<vector<long long> > firsts;
vector<vector<long long> > seconds;

long long othernums[25];

int main(void)
{
	int ttt;
	fin >> ttt;
	int ct = 0;
	string s;
	
	cout.precision(9);
	fout.precision(9);
	
	cout << RAND_MAX << endl;
	
	while(ttt>0)
	{
		ct++;
		ttt--;
		int n,i,j,k;
		
		fin >> n;
		
		for(i=0; i<n; i++)
		{
			fin >> nums[i];
			//nums[i]=rand();
		}
		
		firsts.clear();
		seconds.clear();

		
		sort(nums,nums+500);
		
		for(int k=0; k<500; k+=20)
		{
		
			vector<pair<long long,int> > lis;
			
			for(i=0; i<(1<<20); i++)
			{
				long long p =0;
				
				for(j=0; j<20; j++)
				{
					if( (i&(1<<j))>0)
					{
						p+=nums[j+k];
					}
				}
				lis.push_back(make_pair(p,i));
			}
			sort(lis.begin(),lis.end(),cmp);
			
			long long besti = 0;
			long long bestdiff = lis[1].first-lis[0].first;
			
			for(i=0; i<lis.size()-1; i++)
			{
				if(lis[i+1].first-lis[i].first < bestdiff)
				{
					bestdiff = lis[i+1].first-lis[i].first;
					besti=i;
				}
			}
			
			cout << bestdiff << endl;
			
			vector<long long> lowers;
			vector<long long> uppers;
			
			othernums[k/20]=bestdiff;
			i=besti;
			for(j=0; j<20; j++)
			{
				if( (lis[i].second & (1<<j))>0 && (lis[i+1].second&(1<<j))==0)
				{
					lowers.push_back(nums[j+k]);
				}
			}
									 
			for(j=0; j<20; j++)
			{
				if( (lis[i+1].second & (1<<j))>0 && (lis[i].second&(1<<j))==0)
				{
					uppers.push_back(nums[j+k]);
				}
			}
			
			lis.clear();
			

			firsts.push_back(lowers);
			seconds.push_back(uppers);
			
		}
		
		
		vector<pair<long long,int> > lis;
		
		for(i=0; i<(1<<20); i++)
		{
			long long p =0;
			
			for(j=0; j<20; j++)
			{
				if( (i&(1<<j))>0)
				{
					p+=othernums[j];
				}
			}
			lis.push_back(make_pair(p,i));
		}
		sort(lis.begin(),lis.end(),cmp);
		
		for(i=0; i<lis.size(); i++)
		{
			if(lis[i].first==lis[i+1].first)
				break;
		}
		
		
		
		
		
		cout << "Case #" << ct << ":" << endl;
		fout << "Case #" << ct << ":" << endl;
		
			
		
		for(j=0; j<25; j++)
		{
			if( (lis[i].second & (1<<j))>0 && (lis[i+1].second&(1<<j))==0)
			{
				for(k=0; k<firsts[j].size(); k++)
				{
				 	cout << firsts[j][k] << " ";
					fout << firsts[j][k] << " ";
				}
			}
			if( (lis[i+1].second & (1<<j))>0 && (lis[i].second&(1<<j))==0)
			{
				for(k=0; k<seconds[j].size(); k++)
				{
				 	cout << seconds[j][k] << " ";
					fout << seconds[j][k] << " ";
				}
			}
		}
		
		cout << endl;
		fout << endl;
		
		for(j=0; j<25; j++)
		{
			if( (lis[i+1].second & (1<<j))>0 && (lis[i].second&(1<<j))==0)
			{
				for(k=0; k<firsts[j].size(); k++)
				{
				 	cout << firsts[j][k] << " ";
					fout << firsts[j][k] << " ";
				}
				
			}
			if( (lis[i].second & (1<<j))>0 && (lis[i+1].second&(1<<j))==0)
			{
				for(k=0; k<seconds[j].size(); k++)
				{
				 	cout << seconds[j][k] << " ";
					fout << seconds[j][k] << " ";
				}
			}
		}
		
		cout << endl;
		fout << endl;
			
		
	}
	
	
	return 0;
}

