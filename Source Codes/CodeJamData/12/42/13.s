#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>

int n;
double x[1005],y[1005];
int len[1005];
int in[1005];
int cmp(const void *p,const void *q){
    int pp = *(int*)p, qq=*(int*)q;
    return len[qq]-len[pp];
}

int chk(){
    double ax,bx,ay,by,disT,disN;
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            ax = x[in[i]];
            ay = y[in[i]];
            bx = x[in[j]];
            by = y[in[j]];
            disT = len[in[i]]+len[in[j]];
            disT = disT;
            disN = sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
            /*
            printf("disT %lf disN %lf\n",disT,disN);
            */
            if(fabs(disN-disT)>1e-7 && disT>disN)return 0;
        }
    }

    return 1;
}

int main()
{
    int tn;
    int i,j,k;
    int Lx,Ly;
    unsigned int t;
    srand(time(0));
    scanf("%d",&tn);
    for(k=1;k<=tn;k++){
        scanf("%d%d%d",&n,&Lx,&Ly);
        for(i=0;i<n;i++){
            scanf("%d",&len[i]);
            in[i] = i;
        }

        qsort(in,n,sizeof(int),cmp);

        while(1){
            for(i=0;i<n;i++){
                t = rand();
                t = ((t<<15)|rand());
                x[i] = t%(Lx+1);
                t = ((t<<15)|rand());
                y[i] = t%(Ly+1);
            }
            if(chk())break;
        }

        printf("Case #%d:",k);
        for(i=0;i<n;i++)printf(" %.1lf %.1lf",x[i],y[i]);
        printf("\n");
    }
    return 0;
}
