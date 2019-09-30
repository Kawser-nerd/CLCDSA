#include <iostream>
#include <fstream>
using namespace std;
long er[10],f[1000][1000],a[1000][1000],n,m,test,numtest,outp[1000],i,j,k,ans,sx,sy;
int calc(char ch,int v)
{
	int ans;
	if('0'<=ch && ch<='9') ans=ch-'0';else ans=ch-'A'+10;
	if((ans & v)>0) return(1);else return(0);
}

long MIN(long a,long b,long c)
{
	long ans=a;
	if(ans>b) ans=b;
	if(ans>c) ans=c;
	return(ans);
}

int main()
{
	string st;
	
	er[1]=8;er[2]=4;er[3]=2;er[4]=1;	
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> numtest;
	for(test=1;test<=numtest;test++)
	{
		cin >> m >> n;
		for(i=1;i<=m;i++){
			cin >> st;
			for(j=0;j<n/4;j++) 
				for(k=1;k<=4;k++) f[i][j*4+k]=calc(st[j],er[k]);
		}
		//for(i=1;i<=m;i++)
			//for(j=1;j<=n;j++) cout << f[i][j];cout << endl;
		memset(outp,0,sizeof(outp));
		while(1){
			ans=0;
			for(i=1;i<=m;i++) if(f[i][n]!=3) a[i][n]=1;else a[i][n]=0;
			for(i=1;i<=n;i++) if(f[m][i]!=3) a[m][i]=1;else a[m][i]=0;
			for(i=m-1;i>=1;i--)
				for(j=n-1;j>=1;j--) if(f[i][j]==3) a[i][j]=0;
				else{
					a[i][j]=1;
					if(f[i][j+1]+f[i][j]==1 && f[i+1][j]+f[i][j]==1 && f[i+1][j+1]==f[i][j]) a[i][j]=MIN(a[i][j+1],a[i+1][j],a[i+1][j+1])+1;
				}
			for(i=m;i>=1;i--)
				for(j=n;j>=1;j--) if(a[i][j]>=ans)
				{
					ans=a[i][j];sx=i;sy=j;
				}
			if(ans<2) break;
			outp[ans]++;
			for(i=1;i<=ans;i++)
				for(j=1;j<=ans;j++) f[sx+i-1][sy+j-1]=3;
			//cout << ans << endl;
		}
		outp[1]=n*m;
		for(i=2;i<=n;i++) outp[1]-=i*i*outp[i];
		ans=0;
		for(i=1;i<=n;i++) if(outp[i]>0) ans++;
		cout<<"Case #"<<test<<": "<<ans<<endl;
		for(i=n;i>=1;i--) if(outp[i]>0) cout << i << ' ' << outp[i] << endl;
	}
	return 0;
}
