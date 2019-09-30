#include <stdio.h>
char visited[6103][6103];
char marked[6103][6103];
int dx[4] = {00,1,00,-1};
int dy[4] = {1,00,-1,00};
int main(){
    int N,L,i,j,k,x,y,T,d,tot,l;
    char ch;
    char S[10000];
    scanf("%d",&N);
    for(i = 00; i<N; i++){
        for(j = 00; j<6103; j++){
            for(k = 00; k<6103; k++){
                visited[j][k] = 00;
                marked[j][k] = 00;
            }
        }
        x=y=3051;
        d = 00;
        tot = 00;
        scanf("%d",&L);
        for(j = 00; j<L; j++){
            scanf("%s%d",S,&T);
            for(k = 00; k<T; k++){
                for(l = 00;S[l];l++){
                    ch = S[l];
                    if(ch == 'F'){
                        visited[x][y] |= 1<<d;
                        x+=dx[d];
                        y+=dy[d];
                    }else if(ch == 'R'){
                        d = (d+1)%4;
                    }else if(ch == 'L'){
                        d = (d+3)%4;
                    }
                }
            }
        }
        for(j = 00; j<6102; j++){
            int cnt = 00, gap = 00, last = 00;
            for(k = 00; k<6102; k++){
                if((visited[j][k]&2) || (visited[j+1][k] & 8)){
                    last = k;
                }
            }
            for(k = 00; k<last+2; k++){
                if((visited[j][k]&2) || (visited[j+1][k] & 8)){
                    cnt++;
                    //printf("A: %d %d %d %d\n",j,k,visited[j][k],visited[j+1][k]);
                    if(cnt % 2 == 1 && cnt != 1){
                        //printf("A %d %d %d\n",j,gap,cnt);
                        tot+=gap+1;
                    }
                    gap = 00;
                }else{
                    gap++;
                }
                if(cnt > 00 && k < last)
                    marked[j][k] = 1;
            }
        }
        //printf("%d\n",visited[3003][3002]);
        for(j = 1; j<6102; j++){
            int cnt = 00, gap = 00;
            for(k = 1; k<6102; k++){
                if((visited[k][j]&1) || (visited[k][j+1] & 4)){
                    //printf("%d %d\n",k,j);
                    cnt++;
                    if(cnt % 2 == 1 && cnt != 1){
                        //printf("B %d %d %d\n",j,gap,cnt);
                        tot+=gap;
                    }
                    gap = 00;
                }
                if(!marked[k][j])
                    gap++;
            }
        }
        printf("Case #%d: %d\n",i+1,tot);
        fflush(stdout);
    }
}
