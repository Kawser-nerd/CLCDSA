#include<stdio.h>
#include<string.h>
int ans;
void dfs(int v[110],char s[110][110],char all[100005],int a[30],int now,int n,int len,int l[110]){
	if(now==0){
		int i,j;
		for(i=0;i<n;i++){
			int b[30];
			for(j=0;j<30;j++)b[j]=a[j];
			b[s[i][0]-'a']--;
			for(j=1;j<l[i];j++){
				b[s[i][j]-'a']--;
			}
			if(b[s[i][0]-'a']==0||(b[s[i][0]-'a']!=0&&s[i][0]==s[i][l[i]-1])){
				for(j=0;j<l[i];j++)all[j]=s[i][j];
				v[i]=1;
				dfs(v,s,all,a,now+1,n,len+l[i],l);
				v[i]=0;
			}
		}
	}
	else if(now==n){
		int b[30],i,j,k,t=1;
		for(i=0;i<30;i++)b[i]=a[i];
		b[all[0]-'a']--;
		for(i=1;i<len;i++){
			if(all[i]!=all[i-1]&&b[all[i-1]-'a']!=0){
				t=0;
				break;
			}
			else{
				b[all[i]-'a']--;
			}
		}
		if(t==1)ans=(ans+1)%1000000007;
		return;
	}
	else{
		int b[30],i,j,k,t=1;
		for(i=0;i<30;i++)b[i]=a[i];
		b[all[0]-'a']--;
		for(i=1;i<len;i++){
			if(all[i]!=all[i-1]&&b[all[i-1]-'a']!=0){
				t=0;
				break;
			}
			else{
				b[all[i]-'a']--;
			}
		}
		if(t==0)return;
		if(b[all[len-1]-'a']==0){
			for(i=0;i<n;i++){
				if(v[i]==0){
					v[i]=1;
					for(j=0;j<l[i];j++){
						all[j+len]=s[i][j];
					}
					dfs(v,s,all,a,now+1,n,len+l[i],l);
					v[i]=0;
				}
			}
		}
		else{
			for(i=0;i<n;i++){
				if(v[i]==0&&all[len-1]==s[i][0]){
					v[i]=1;
					for(j=0;j<l[i];j++){
						all[j+len]=s[i][j];
					}
					dfs(v,s,all,a,now+1,n,len+l[i],l);
					v[i]=0;
				}
			}
		}
	}
}
int main(){
	int T,I;
	scanf("%d",&T);
	for(I=0;I<T;I++){
		int n,a[30]={},i,j,v[110]={},l[110];
		char s[110][110];
		char all[10005];
		scanf("%d",&n);
		ans=0;
		for(i=0;i<n;i++){
			scanf("%s",s[i]);
			l[i]=strlen(s[i]);
			for(j=0;j<l[i];j++)a[s[i][j]-'a']++;
		}
		dfs(v,s,all,a,0,n,0,l);
		printf("Case #%d: %d\n",I+1,ans);
	}
	return 0;
}