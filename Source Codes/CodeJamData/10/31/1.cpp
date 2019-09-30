#include<iostream>
using namespace std;

int a[1001],b[1001];

int main(){
	freopen("A-large.in","r",stdin);
	freopen("pa.txt","w",stdout);
	int c,cc,t,i,j,ans;
	scanf("%d",&cc);
	for(c=1 ; c<=cc ; c++){
		scanf("%d",&t);
		for(i=0 ; i<t ; i++){
			scanf("%d%d",&a[i],&b[i]);
		}
		ans=0;
		for(i=0 ; i<t-1 ; i++){
			for(j=i+1 ; j<t ; j++){
				if((a[i]>a[j] && b[i]<b[j]) || (a[i]<a[j] && b[i]>b[j])) ans++;
			}
		}
		cout << "Case #" << c << ": " << ans << endl;
	}
}
