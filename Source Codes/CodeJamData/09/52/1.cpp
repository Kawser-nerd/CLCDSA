#include<iostream>
#include<string>
using namespace std;

const int MOD = 10009;

const int maxn = 100 + 5;
const int maxK = 10 + 2;

string word[maxn];
string ope,tmp;

int ans[maxK];
int p[maxn][4];
int K,n,m;

int res[maxK][1<<4];
void work()
{
	m = tmp.size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			p[i][j] = 0;
			for(int k=0;k<word[i].size();k++) if( word[i][k]==tmp[j] ) p[i][j]++;
		}
	}

	res[0][0] = 1;
	int mu;
	for(int i=1;i<=K;i++)
	{
		for(int j=0;j<(1<<m);j++)
		{
			res[i][j] = 0;
			for(int k=0;k<n;k++)
			{
				for(int d=0;d<=j;d++) if( (d&j)==d )
				{
					mu = 1;
					for(int u=0;u<m;u++) if( ((1<<u)&j)>0 && ((1<<u)&d)==0 )
						mu = mu*p[k][u]%MOD;
					res[i][j] = (res[i][j] + mu*res[i-1][d])%MOD;
				}
			}
		}
		ans[i] = (ans[i]+res[i][(1<<m)-1])%MOD;
	}
}
int main()
{
	int T;
	cin>>T;
	for( int num=1;num<=T;num++ )
	{
		cin>>ope>>K;
		cin>>n;
		for(int i=0;i<n;i++) cin>>word[i];

		for(int i=1;i<=K;i++) ans[i] = 0;
		
		for(int i=0;i<ope.size();i++)
		{
			int j = i;while( j+1<ope.size() && ope[j+1]!='+' ) j++;
			tmp = "";
			for(int k=i;k<=j;k++) tmp+=ope[k];
			work();
			i = j+1;
		}

		cout<<"Case #"<<num<<":";
		for(int i=1;i<=K;i++) cout<<" "<<ans[i];
		cout<<endl;
	}
	return 0;
}
