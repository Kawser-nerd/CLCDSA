/* gcc -o pb1 pb1.c  */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MIN(a,b) ( ( a > b) ? b : a ) 


static void solve (void);

int main () 
{
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int t,i;
    scanf ("%d", &t);
    for (i = 0; i < t; i++) {
        printf ("Case #%d: ", i + 1);
        solve ();
    }
    return FALSE;
}


int solve2(int* dd, int* vv, int v, int d){
    int i,j,k;
    int x=0;
    for(i=1;i< (1<<d) ;i++){
        x = 0;
        for(j=0;j<MIN(d,32);j++){
            if(i & (1 << j)){
                x+= dd[j];
            }
        }
        if(x <= v)
            vv[x-1] = 1;
    }
    
    for(i=0;i<v;i++){
        if(vv[i] == 0){
            return i+1;
        }
    }

    return 0;
}

void solve (void) 
{
    int i;
    int res = 0;
    int r = 0;
    int c,d,v;
    int n = 0;

    scanf("%d %d %d", &c, &d, &v);
    int* dd = (int*)malloc(1000*d*sizeof(int));
    int* vv = (int*)malloc((v)*sizeof(int));
    for(i=0;i<d;i++){
        scanf("%d",&dd[i]);
    }

    r = solve2(dd, vv, v, d);
    n = d;
    while(r != 0){
        dd[n] = r;
        n++;
        r = solve2(dd,vv,v,n);
        res++;
    }

    
    printf("%d\n",res);
}


