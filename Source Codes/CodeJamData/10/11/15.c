#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int i,j,t,n,k,m,red,blue,l;
    char map[52][52];
    FILE *fin=fopen("A-large.in","r");
    FILE *fout=fopen("A.out","w");
    fscanf(fin,"%d\n",&t);
    for(i=1;i<=t;i++){
        red=0;
        blue=0;
        for(j=0;j<n;j++)
            memset(map[j],'.',n*sizeof(char));
        fscanf(fin,"%d %d\n",&n,&k);
        for(j=0;j<n;j++)
            fscanf(fin,"%s",map[j]);
        for(j=0;j<n;j++)
            for(m=n-1;m>=0;m--){
                if(map[j][m]!='.'){
                    char x;
                    l=m+1;
                    while((l<n)&&(map[j][l]=='.'))
                        l++;
                    if(l!=m+1){
                        x=map[j][l-1];
                        map[j][l-1]=map[j][m];
                        map[j][m]=x;
                    }
                }
            }
        for(j=0;j<n;j++)
            for(m=0;m<n;m++){
                int right,left,up,down;
                if(red==1&&blue==1)
                    break;
                if(map[j][m]!='.'){
                    if(map[j][m]=='B'&&blue==1)
                        continue;
                    if(map[j][m]=='R'&&red==1)
                        continue;
                   
                    l=1;
                    right=m+1;
                    while((right<n)&&(map[j][right])==map[j][m])
                        right++;
                    l=l+right-m-1;
                    left=m-1;
                    while((left>=0)&&(map[j][left])==map[j][m])
                        left--;
                    l=l+m-(left+1);
                    if(l>=k){
                        if(map[j][m]=='B')
                            blue=1;
                        if(map[j][m]=='R')
                            red=1;
                    }

                    l=1;
                    up=j-1;
                    while((up>=0)&&(map[up][m])==map[j][m])
                        up--;
                    l=l+j-(up+1);
                    down=j+1;
                    while((down<n)&&(map[down][m])==map[j][m])
                        down++;
                    l=l+down-j-1;
                    if(l>=k){
                        if(map[j][m]=='B')
                            blue=1;
                        if(map[j][m]=='R')
                            red=1;
                    }

                    l=1;
                    up=j-1,left=m-1;
                    while((up>=0)&&(left>=0)&&(map[up][left])==map[j][m]){
                        up--;
                        left--;
                    }
                    l=l+j-(up+1);
                    down=j+1,right=m+1;
                    while((down<n)&&(right<n)&&(map[down][right])==map[j][m]){
                        down++;
                        right++;
                    }
                    l=l+right-m-1;
                    if(l>=k){
                        if(map[j][m]=='B')
                            blue=1;
                        if(map[j][m]=='R')
                            red=1;
                    }

                    l=1;
                    down=j+1,left=m-1;
                    while((down<n)&&(left>=0)&&(map[down][left])==map[j][m]){
                        down++;
                        left--;
                    }
                    l=l+m-(left+1);
                    up=j-1,right=m+1;
                    while((up>=0)&&(right<n)&&(map[up][right])==map[j][m]){
                        up--;
                        right++;
                    }
                    l=l+right-m-1;
                    if(l>=k){
                        if(map[j][m]=='B')
                            blue=1;
                        if(map[j][m]=='R')
                            red=1;
                    }
                }
            }
        if(red==1&&blue!=1)
            fprintf(fout,"Case #%d: Red\n",i);
        if(red!=1&&blue==1)
            fprintf(fout,"Case #%d: Blue\n",i);
        if(red==1&&blue==1)
            fprintf(fout,"Case #%d: Both\n",i);
        if(red!=1&&blue!=1)
            fprintf(fout,"Case #%d: Neither\n",i);
    }
    fclose(fin);
    fclose(fout);
    return (EXIT_SUCCESS);
}

