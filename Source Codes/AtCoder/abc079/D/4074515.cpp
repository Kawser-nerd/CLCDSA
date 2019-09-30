/*#include<iostream>
#include<string.h>

using namespace std;
const int inf = 1e7;
const int man = 5e2+10;
//int maze[man][man];
int vis[man],dis[man];
int c[15][15];
//int jishu[10];
int h,w;
/*
int dij(int u)
{
	memset(vis,0,sizeof(vis));
	for(int i =1 ;i <= 9 ;i++)
	{
		dis[i] = c[u][i];
	}
	vis[u] = 1;
	for(int i =1 ;i < 9;i++)//?????9??????debug??????
	{
		int minn = inf ,v = -1;
		for(int j =1 ;j <= 9 ;j++)
		{
			if(!vis[j]&&dis[j]<minn)
			{
				v = j;
				minn = dis[j];
			}
		}
		vis[v] = 1;
		for(int j = 1; j <= 9 ;j++)
		{
			if(!vis[j])
			{
				dis[j] = min(dis[j],dis[v]+c[v][j]);
			}
		}
	}
	return dis[1];
}


void floyd()
{
	for(int k = 0; k <= 9 ;k++)
	{
		for(int i = 0 ;i <= 9 ;i++)
		{
			for(int j =0;j<= 9 ;j++)
			{
				c[i][j] = min(c[i][j],c[i][k] + c[k][j]);
			}
		}
	}
}

void solve()
{
	cin >> h >> w;
	 for (int i = 0; i < 10; i++)
       for (int j = 0; j < 10; j++)
             cin>>c[i][j];
//		floyd();
     int ans = 0;
     for(int i=0;i<h;i++)
         for (int j = 0; j < w ; j++)
		 {
		 	int A;
            scanf("%d", &A);
            if (A >= 0)
                 ans += c[A][1];
         }
		//cout << dij(8) << endl;
		cout << ans << endl;
}

int main()
{
	solve();
	return 0;
}
*/
#include<iostream>
#include<string.h>

using namespace std;
const int inf = 1e7;
const int man = 5e2+10;
int maze[man][man];
int vis[man],dis[man];
int c[15][15];
int jishu[10];
int h,w;

int dij(int u)
{
	memset(vis,0,sizeof(vis));
	for(int i =0 ;i <= 9 ;i++)
	{
		dis[i] = c[u][i];
	}
	vis[u] = 1;
	for(int i =0 ;i < 9;i++)//?????9??????debug??????
	{
		int minn = inf ,v = -1;
		for(int j =0 ;j <= 9 ;j++)
		{
			if(!vis[j]&&dis[j]<minn)
			{
				v = j;
				minn = dis[j];
			}
		}
		vis[v] = 1;
		for(int j = 0; j <= 9 ;j++)
		{
			dis[j] = min(dis[j],dis[v]+c[v][j]);
		}
	}
	return dis[1];
}

void solve()
{
	cin >> h >> w;//????.

		for(int i = 0; i < 10 ;i++)
		{
			for(int j = 0 ;j < 10 ;j++)
			{
				cin >> c[i][j];
			}
		}
		memset(jishu,0,sizeof(jishu));
		for(int i = 1 ; i <= w ;i++)
		{
			for(int j = 1; j<= h ;j++)
			{
				cin >> maze[i][j];
				if(maze[i][j] >= 0 )
				{
					jishu[maze[i][j]]++;
				}
			}
		}
		int ans = 0;
		//cout << dij(8) << endl;
		for(int i = 0 ; i <= 9 ;i++)
		{
			if(jishu[i])
			{
				int k = jishu[i];
				ans= ans +dij(i)*k;
			}
		//	cout << jishu[i] << endl;
		}
		cout << ans << endl;

}

int main()
{
	solve();
	return 0;
} ./Main.cpp:12:1: warning: '/*' within block comment [-Wcomment]
/*
^
1 warning generated.