#include<cstdio>
 
char have[200000];
 
int main(void) {
    int n;
    scanf("%d",&n);
 
    int dup=0;
    for(int i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        if(have[a]) dup++;
        else have[a]++;
    }
    printf("%d\n",n-(dup+1)/2*2);
    return 0;
}