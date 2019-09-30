#include<stdio.h>
#include<string.h>
#include<math.h>
int bigsort(const void *a,const void *b) {
    return *(int *)b-*(int *)a;
}

int smallsort(const void *a,const void *b) {
    return *(int *)a-*(int *)b;
}

int main(void) {
    FILE* out=fopen("e:/out","w");
    FILE* in=fopen("e:/A-large.in","r");
    int a[1000],b[1000];
    int t,n,i,j,c=0;
    fscanf(in,"%d",&t);
    while(t-->0) {
        c++;
        fscanf(in,"%d",&n);
        for(i=0;i<n;i++) {
            fscanf(in,"%d",&a[i]);
        }
        for(i=0;i<n;i++) {
            fscanf(in,"%d",&b[i]);
        }
        qsort(a,n,sizeof(int),bigsort);
        qsort(b,n,sizeof(int),smallsort);
        __int64 s1=0,s2=0;
        for(i=0;i<n;i++) {
            s1+=(__int64)a[i]*b[i];
            s2+=(__int64)a[n-1-i]*b[n-1-i];
        }
        fprintf(out,"Case #%d: %I64d\n",c,s1<s2?s1:s2);
    }
    system("pause");
    return 0;
}
