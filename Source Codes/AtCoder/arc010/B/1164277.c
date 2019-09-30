#include<stdio.h>

int mtod(int m){
    int d=0;
    switch (m-1) {
        case 11: d += 30;
        case 10: d += 31;
        case 9: d += 30;
        case 8: d += 31;
        case 7: d += 31;
        case 6: d += 30;
        case 5: d += 31;
        case 4: d += 30;
        case 3: d += 31;
        case 2: d += 29;
        case 1: d += 31;
    }
    return d;
}

int main(){
    int n, i, j, s[366];
    scanf("%d\n", &n);
    for (i = 0; i < n; i++) {
        int m, d;
        scanf("%d/%d\n", &m, &d);
        s[i] = mtod(m) + d;
    }

    int max=0, curr=0, flag=0;
    for(i=1; i<=366; i++){
        if(i % 7 == 0 || i % 7 == 1){
            flag++;
        }
        for(j=0; j<n; j++){
            if(s[j] == i) flag++;
        }

        if(flag > 0){
            curr++;
            flag--;
        }else{
            curr=0;
        }

        if(max < curr) max = curr;
    }
    printf("%d\n", max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n", &n);
     ^
./Main.c:26:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d/%d\n", &m, &d);
         ^