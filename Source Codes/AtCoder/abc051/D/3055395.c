#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[m],b[m],c[m];
    for (int i=0; i<m; i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        a[i]--;
        b[i]--;
    }
    
    int cost[n],q[n],prev[n],count=1;
    bool visited[n],ans[m];
    for (int i=0; i<m; i++){
        ans[i]=false;
    }
    
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            
            for (int k=0; k<n; k++){
                cost[k]=1e9;
                q[k]=1e9;
                visited[k]=false;
                prev[n]=-1;
            }    
            cost[i]=0;
            q[i]=0;
            
            for (int k=0; k<count; k++){
                int tmp=1e9,next;
                for (int l=0; l<n; l++){
                    if (tmp>q[l] && visited[l]==false){
                        tmp=q[l];
                        next=l;
                    }
                }
                visited[next]=true;
                if (next==j){
                    break;
                }
                count++;
                for (int l=0; l<m; l++){
                    if (a[l]==next){
                        if (cost[b[l]]>cost[next]+c[l]){
                            cost[b[l]]=cost[next]+c[l];    
                            prev[b[l]]=next;
                            q[b[l]]=cost[next]+c[l];
                        }
                    }
                    if (b[l]==next){
                        if (cost[a[l]]>cost[next]+c[l]){
                            cost[a[l]]=cost[next]+c[l];    
                            prev[a[l]]=next;
                            q[a[l]]=cost[next]+c[l];
                        }
                    }
                }
            }
            int k=j;
            while (k!=i){
                for (int l=0; l<m; l++){
                    if (a[l]==k && b[l]==prev[k]){
                        ans[l]=true;
                    } else if (b[l]==k && a[l]==prev[k]){
                        ans[l]=true;
                    }
                }  
                k=prev[k];
            }
        }
    }
    
    int anscount=0;
    for (int i=0; i<m; i++){
        if (ans[i]==false){
            anscount++;
        }
    }
    printf("%d\n",anscount);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&a[i],&b[i],&c[i]);
         ^