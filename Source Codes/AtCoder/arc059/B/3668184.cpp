#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<string>
//#include<string>
//#include<sstream>
using namespace std;
int main()
{
	int n,i,mid=0,k,c[26]={0},flag=0;
    string a;
    cin>>a;
    
	/*if(n>2){
		for(i=1;i<n;i++)
		{
			k=1;
			flag=0;
			if(i-k>=0&&i+k<=n-1&&a[i-1]!=a[i+1])
			{
				mid=i;
				while(1){
					if(mid-k>0&&mid+k<n-1){
						if(a[mid-k]!=a[mid+k])
						{
							k++;
						}
						else break;
					}
					else break;
				}
				for(int j=mid-k;j<=mid+k;j++){
					c[a[j]-'a']++;
				}
				sort(c,c+26);
				if(c[25]*2>=(2*k+1)){
					flag=1;
					break;
				}
				else{
					for(int j=0;j<26;j++) c[j]=0;
				}
			}
			if(flag!=0) break;
		}
		if(flag!=0){
			printf("%d %d\n",mid-k+1,mid+k+1);
		}
		else printf("-1 -1\n");
	}
	else{
		if(a[0]==a[1])
			printf("-1 -1\n");
		else printf("1 2\n");
	}*/
	for(int i=0;i<a.size()-1;i++){
        if(a[i]==a[i+1]){
            cout<<i+1<<" "<<i+2<<endl;
            flag=1;
            break;
        }
        else if(i<a.size()-2&&a[i]==a[i+2]){
            cout<<i+1<<" "<<i+3<<endl;
            flag=1;
            break;
        }
    }
    if(!flag)
    cout<<-1<<" "<<-1<<endl;
}