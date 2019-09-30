#include <stdio.h>
#include <math.h>
int main(void){
    long long int X,Y;
    scanf("%lld/%lld",&X,&Y);
    long long int seisubu=2*X/Y+1;
    long long int kasubu=seisubu*Y-2*X;
    //N?seisubu????seisubu-1
    int flag=0;
    long long int homo=kasubu*(seisubu-1)/Y;
    if(homo*Y==kasubu*(seisubu-1)&&homo>0&&homo%2==0&&homo<=seisubu-1){
    printf("%lld %lld\n",seisubu-1,homo/2);
    flag=1;
    }
    homo=kasubu*seisubu/Y;
    if(homo*Y==kasubu*seisubu&&homo>=0&&(homo+seisubu)%2==0&&homo<=seisubu)
    {
    printf("%lld %lld\n",seisubu,(homo+seisubu)/2);
    flag=1;
    }
    if(flag==0)printf("Impossible\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld/%lld",&X,&Y);
     ^