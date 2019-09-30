#include <stdio.h>

    //standard
    #define max(p,q)((p)>(q)?(p):(q))
    #define min(p,q)((p)<(q)?(p):(q))
    #define abs(a) ((a)>(0)?(a):-(a))

    //Prototype Declaration
    void bubbleSort(int* N, int len);
    void Swap(int *a, int *b);


    int main() {
        int n;
        //int count = 0;
        int p[20001];
        int r[20001];
        int a[20001];
        int b[20001];

        //input
        scanf("%d",&n);

        int i;
        for(i = 1; i <= n; i++){
            scanf("%d",&p[i]);
            r[p[i]] = i;    //p[] ????
         }

        //calculation

        //setting a[]
        for(i = 1; i <= n; i++){
        	a[i] = 20001*i;
         }

        //setting b[]
        for(i = 1; i <= n; i++){
        	b[i] = 20001*(n-i) + r[i];
         }



        //Output
        for(i = 1; i <= n; i++){
        	printf("%d ",a[i]);
         }
        printf("\n");
        for(i = 1; i <= n; i++){
           printf("%d ",b[i]);
         }
        return 0;
    }


    //BubbleSort
    void bubbleSort(int* N, int len){
        int i,j;

        for(i=0; i<len; i++){
            for(j=len-1; j>i; j--){
                if(N[j] < N[j-1]){
                    Swap(&N[j],&N[j-1]);
                }
            }
        }
    }

    //general function
    void Swap(int *a, int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    } ./Main.c: In function ‘main’:
./Main.c:22:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&n);
         ^
./Main.c:26:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&p[i]);
             ^