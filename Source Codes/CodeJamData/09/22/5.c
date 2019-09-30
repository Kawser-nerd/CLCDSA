#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int N,k; 	
    char ch;	  
    scanf("%d",&N);
    ch= getchar();
	
    k=1;
    while(k<=N){
	
        printf("Case #%d: ",k);
	k++; 

        int n=0;
        char c;
        char string[100];
        int i, to_flip, ar[10];

        while((c=getchar())!='\n'){
            string[n++]=c;
        }

        to_flip = n;
        for(i=n-1;i>0;i--){
            if(string[i]>string[i-1]){
                to_flip = i-1;
                break;
            }
        }

        for(i=0;i<10;i++) ar[i]=0;

        if(to_flip!=n){
            for(i=to_flip;i<n;i++) ar[string[i]-48]++;
            for(i=0;i<to_flip;i++)
                putchar(string[i]);
            for(i=string[to_flip]-47;i<10;i++){
                if(ar[i]!=0){
                    putchar(48+i);
                    ar[i]--;
                    break;
                }
            }
            for(i=0;i<10;i++){
                while(ar[i]!=0){
                    putchar(48+i);
                    ar[i]--;
                }
            }
        }
        else{
            for(i=0;i<n;i++)
                ar[string[i]-48]++;
            for(i=1;i<10;i++){
                if(ar[i]!=0){
                    putchar(48+i);
                    ar[i]--;
                    break;
                }
            }
            putchar('0');
            for(i=0;i<10;i++){
                while(ar[i]!=0){
                    putchar(48+i);
                    ar[i]--;
                }
            }
        }
        putchar('\n');
    }

    return 1;

}
