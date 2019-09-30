#include <stdio.h>
#include <stdlib.h>
#define min(x,y) (x>y ? y : x)
#define max(x,y) (x>y ? x : y)
int eski[101][101],yeni[101][101];
int R,x1,x2,y11,y2,T,XMAX,YMAX,result;
int check(void)
{
    int i,j,c=1,k,l;
    for(i=0;i<=XMAX;i++)
    {
                       for(j=0;j<=YMAX;j++)
                       {
                                           yeni[i][j]=eski[i][j];
                                           if(yeni[i][j]) c=0;
                       }
    }
    return c;
}

int main(void)
{
    int i,j,k,l;
    FILE *in,*out;
    in=fopen("A-small.in","r");
    out=fopen("A-small.out","w");
    fscanf(in,"%d",&T);
    for(i=1;i<=T;i++)
    {
                     fscanf(in," %d",&R);
                     
                     for(k=0;k<101;k++) for(j=0;j<101;j++) eski[k][j]=yeni[k][j]=0;
                     //printf("wedfsafadsfadsf\n");
                     XMAX=0;
                     YMAX=0;
                     result=0;
                     //printf("eben\n");
                     for(l=0;l<R;l++)
                     {
                                     fscanf(in," %d %d %d %d",&x1,&y11, &x2,&y2);
                                     if(x2>XMAX) XMAX=x2;
                                     if(y2>YMAX) YMAX=y2;
                     
                     for(j=min(x1,x2);j<=max(x1,x2);j++)           
                     {
                                     for(k=min(y11,y2);k<=max(y11,y2);k++)
                                     {
                                                     yeni[j][k]=1;
                                                     eski[j][k]=1;
                                     }
                     }}
                     //printf("ANAN\n");
                     /*for(k=0;k<=XMAX;k++)
                     {
                                         for(j=0;j<=YMAX;j++)
                                         {
                                                             printf("%d ",eski[j][k]);
                                         }
                                         printf("\n");
                     }*/
                     while(1)
                     {
                             for(k=0;k<=XMAX;k++)
                             {
                                                for(j=0;j<=YMAX;j++)
                                                {
                                                                   if(k && j && !yeni[k][j] && yeni[k-1][j] && yeni[k][j-1])
                                                                   {
                                                                        eski[k][j]=1;
                                                                   }
                                                                   if(k && j && yeni[k][j] && !yeni[k-1][j] && !yeni[k][j-1])
                                                                   {
                                                                        eski[k][j]=0;
                                                                   }
                                                }
                             }
                             result++;
                             if(check()) break;
                             
                     }
                     fprintf(out,"Case #%d: %d\n",i,result);
    }
    fclose(in);
    fclose(out);
    getch();
    return 0;
}
