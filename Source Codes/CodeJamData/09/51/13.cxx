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
#include <set>

using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");

char board[14][14];
int nums[14][14];

set<vector<int> > states;
vector<vector<int> > dolis;

bool isok[196];

void init()
{
	for(int i=0; i<14; i++)
	{
		for(int j=0; j<14; j++)
		{
			nums[i][j]=14*i+j;
		}
	}
}

int n;

int lis[5];
bool isin[5];

void add(int x)
{
	isin[x]=true;
	for(int i=0; i<n; i++)
	{
		if(!isin[i] && (lis[i]-lis[x]==1 || lis[i]-lis[x]==-1 || lis[i]-lis[x]==14 || lis[i]-lis[x]==-14))
		{
			add(i);
		}
	}
	return;
}

bool test()
{
	int i;
	for(i=0; i<n; i++)
		isin[i]=false;
	add(0);
	for(i=0; i<n; i++)
	{
		if(!isin[i])
			return false;
	}
	return true;
}

int main(void)
{
	int ttt;
	cin >> ttt;
	int ct = 0;
	init();
	while(ttt>0)
	{
		ct++;
		ttt--;
		int i,j,k;
		int r,c;
		cin >> r >> c;
		for(i=0; i<14; i++)
		{
			for(j=0; j<14;j++)
			{
				board[i][j]='#';
				isok[14*i+j]=false;
			}
		}
		
		vector <int> st;
		vector <int> en;
		for(i=1; i<=r; i++)
		{
			for(j=1; j<=c; j++)
			{
				cin >> board[i][j];
				if(board[i][j]!='#')
					isok[14*i+j]=true;
				if(board[i][j]=='o')
					st.push_back(nums[i][j]);
				else if(board[i][j]=='x')
					en.push_back(nums[i][j]);
				else if(board[i][j]=='w')
				{
					st.push_back(nums[i][j]);
					en.push_back(nums[i][j]);
				}
			}
		}
		sort(st.begin(),st.end());
		sort(en.begin(),en.end());
		n = st.size();
		dolis.resize(0);
		states.clear();
		states.insert(st);
		st.push_back(0);
		dolis.push_back(st);
		int readfrom = 0;
		int ans = -1;
		int cx,cy;
		int nx,ny;
		while(ans<0 && readfrom<dolis.size())
		{
			vector <int> curr = dolis[readfrom];
			int dep = curr[n];
			curr.pop_back();
			if(curr==en)
			{
				ans=dep;
				break;
			}
			for(k=0; k<n; k++)
			{
				//cout << curr[k] << " ";
				isok[curr[k]]=false;
				lis[k]=curr[k];
			}
		//	cout << endl;
			bool isdang = !test();
			for(int a=0; a<n; a++)
			{	
				if( isok[curr[a]-14] && isok[curr[a]+14])
				{
					//cout << a << " " << "UP ";
					lis[a]-=14;
					if(!isdang || test())
					{
						//cout << "<ORE" << endl;
						vector <int> tmp = curr;
						tmp[a]=curr[a]-14;
						sort(tmp.begin(),tmp.end());
						//cout << states.count(tmp) << endl;
						if(states.count(tmp)==0)
						{
							//cout << "STRA" << endl;
							states.insert(tmp);
							tmp.push_back(dep+1);
							dolis.push_back(tmp);
						}
					}
					lis[a]+=28;
					
					if(!isdang || test())
					{
						vector <int> tmp = curr;
						tmp[a]=curr[a]+14;
						sort(tmp.begin(),tmp.end());
						if(states.count(tmp)==0)
						{
							states.insert(tmp);
							tmp.push_back(dep+1);
							dolis.push_back(tmp);
						}
					}
					lis[a]=curr[a];
				}
				if( isok[curr[a]-1] && isok[curr[a]+1])
				{
					//cout << a << " across ";
					lis[a]-=1;
					if(!isdang || test())
					{
						vector <int> tmp = curr;
						tmp[a]=curr[a]-1;
						sort(tmp.begin(),tmp.end());
						if(states.count(tmp)==0)
						{
							states.insert(tmp);
							tmp.push_back(dep+1);
							dolis.push_back(tmp);
						}
					}
					lis[a]+=2;
					
					if(!isdang || test())
					{
						vector <int> tmp = curr;
						tmp[a]=curr[a]+1;
						sort(tmp.begin(),tmp.end());
						if(states.count(tmp)==0)
						{
							states.insert(tmp);
							tmp.push_back(dep+1);
							dolis.push_back(tmp);
						}
					}
					lis[a]=curr[a];
				}
				//cout << endl;
				
			}
			readfrom++;
			for(k=0; k<n; k++)
				isok[curr[k]]=true;
			//cout << dolis.size() << endl;
		}
		cout << "Case #" << ct << ":" << " " << ans << endl;
		fout << "Case #" << ct << ":" << " " << ans << endl;
		
	}

	
	return 0;
}

