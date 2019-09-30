#include <stdio.h>

int a[55];
int aoki_select[55];

int main(){

	int N;

	scanf("%d",&N);

	int i,j,k;

	for(i=0;i<N;i++){
		scanf(" %d",&a[i]);
	}


	for(i=0;i<N;i++){
		int aoki_max=-114514;
		int aoki_idx=-1;
		for(j=0;j<i;j++){
			int aoki=0;
			int cnt=0;
			for(k=j;k<=i;k++){
				if(cnt%2==1){aoki+=a[k];}
				cnt++;
			}
			if(aoki>aoki_max){
				aoki_max=aoki;
				aoki_idx=j;
			}
		}
		for(j=i+1;j<N;j++){
			int aoki=0;
			int cnt=0;
			for(k=i;k<=j;k++){
				if(cnt%2==1){aoki+=a[k];}
				cnt++;
			}
			if(aoki>aoki_max){
				aoki_max=aoki;
				aoki_idx=j;
			}
		}
		aoki_select[i]=aoki_idx;
	}
	int ans=-114514;
	for(i=0;i<N;i++){
		int takahashi=0;
		int cnt=0;
		if(i<aoki_select[i]){
			for(j=i;j<=aoki_select[i];j++){
				if(cnt%2==0){takahashi+=a[j];}
				cnt++;
			}
		}
		else{
			for(j=aoki_select[i];j<=i;j++){
				if(cnt%2==0){takahashi+=a[j];}
				cnt++;
			}
		}
		if(ans<takahashi){ans=takahashi;}
	}

	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %d",&a[i]);
   ^