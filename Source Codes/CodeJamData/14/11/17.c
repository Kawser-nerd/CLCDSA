#include<stdio.h>
int n,l;
char a[222][222],b[222][222];
char dif(char a,char b){
    return (a+2-b)%2;
}
int ans;
void proc(int xx){
    int i,j,k,m;
    int t;
    ans=99999;
    scanf("%d %d",&n,&l);
    for(i=0;i<n;i++){
        scanf("%s",a[i]);
        for(j=0;j<l;j++)a[i][j]-='0';
    }
    for(i=0;i<n;i++){
        scanf("%s",b[i]);
        for(j=0;j<l;j++)b[i][j]-='0';
    }
    int h;
    for(k=0;k<n;k++){
        h=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(m=0;m<l;m++){
                    if( dif(a[i][m],b[j][m])!=dif(a[0][m],b[k][m]) )break;
                }
                if(m==l){
                    h++;break;
                }
            }
        }
        if(h==n){
            t=0;
            for(i=0;i<l;i++)t+=dif(a[0][i],b[k][i]);
            ans=t<ans?t:ans;
        }
    }
    printf("Case #%d: ",xx);
    if(ans==99999)printf("NOT POSSIBLE");
    else printf("%d",ans);
    printf("\n");
}
int main(){
    int qq;
    scanf("%d",&qq);
    int i;
    for(i=1;i<=qq;i++)proc(i);
    return 0;
}
