#include <stdio.h>

    //standard
    #define max(p,q)((p)>(q)?(p):(q))
    #define min(p,q)((p)<(q)?(p):(q))
    #define abs(a) ((a)>(0)?(a):-(a))


    int main() {
        int h;
        int w;
        char a[9][9];

        //input
        scanf("%d",&h);
        scanf("%d",&w);

        int mark = 0;
        int flag = 0;

        //input
        int i;
        for (i=0;i<h;i++) {
          scanf("%s",a[i]);
         }


        //calculation
       for(i = 0; i < h; i++){
        	int j;
        	for(j = 0; j < w; j++){
        		if(a[i][j] == '#'){
        			if(j >= mark){
        				mark = max(mark,j);
        				if(i == h-1 && j == w-1){
        					printf("\nPossible");
        				}
        			}else{
        				flag++;
        				goto endloop;
        			}
        		}
            }
         }

        endloop:
			if(flag){
				printf("\nImpossible");
			}

        return 0;
    } ./Main.c: In function ‘main’:
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&h);
         ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&w);
         ^
./Main.c:24:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
           scanf("%s",a[i]);
           ^