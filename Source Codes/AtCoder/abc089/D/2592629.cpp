#include<cstdio>
#define abs(x) ((x>0)?x:(-(x)))
int H,W,D,A;
int Q,L,R;
int px[90001] ,py [90001];
int d[90001];
int  main()
{
    scanf ("%d %d %d",&H,&W,&D);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            scanf ("%d",&A);
            px[A]=i,py[A]=j;
        }
    }
    for(int i=D+1;i<=H*W;i++){ 
        d[i]=d[i-D]+abs(px[i]-px[i-D])+ abs(py[i]-py[i-D]);
    } 
    scanf ("%d",&Q);
    while(Q--){ 
        scanf ("%d%d",&L,&R);
        printf ("%d\n",d[R]-d[L]);
    } 
}