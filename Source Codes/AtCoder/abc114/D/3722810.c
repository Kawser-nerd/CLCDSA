#include<stdio.h>
int SosuIndex[100];
int Soinsu[100];
int c=1;
void Sosu(int N){
    int b=0;
    for(int n=3;n<=N;n++){
        b=0;
        for(int i=0;i<c;i++){
            if(n%SosuIndex[i]==0)b++;
        }
        if(b==0){SosuIndex[c]=n;c++;}
    }
}
int main(void){
    SosuIndex[0]=2;
    long N,cou1=0,cou2=0,x=0,y=0,z=0,q=0;
    scanf("%ld",&N);
    Sosu(N);
    for(int i=0;i<100;i++){Soinsu[i]=0;}
    for(int i=0;i<c;i++){
        for(int j=2;j<=N;j++){
            int J=j;
            while(J%SosuIndex[i]==0 && J!=0){
                Soinsu[i]++;
                J/=SosuIndex[i];
            }
        }
    }
    for(int i=0;i<c;i++){
        if(Soinsu[i]>=14)cou1++;
        if(Soinsu[i]<14 && Soinsu[i]>=4)cou2++;
    }
    if(cou1>=2 || (cou1>=1 && cou2>=1))
        x=cou2*cou1+(cou1)*(cou1-1);
    cou1=0;cou2=0;
    
    for(int i=0;i<c;i++){
        if(Soinsu[i]>=24)cou1++;
        if(Soinsu[i]<24 && Soinsu[i]>=2)cou2++;
    }
    if(cou1>=2 || (cou1>=1 && cou2>=1))
        y=cou2*cou1+(cou1)*(cou1-1);
    cou1=0;cou2=0;
    
    for(int i=0;i<c;i++){if(Soinsu[i]>=74)cou1++;}
    z=cou1;
    cou1=0;cou2=0;
    
    for(int i=0;i<c;i++){
        if(Soinsu[i]>=4)cou1++;
        if(Soinsu[i]<4 && Soinsu[i]>=2)cou2++;
    }
    if(cou1>=3 || (cou1>=2 && cou2>=1))
        q=cou2*(cou1)*(cou1-1)/2+(cou1)*(cou1-1)*(cou1-2)/2;
    cou1=0;cou2=0;
    
    long p=x+y+z+q;
    printf("%ld\n",p);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&N);
     ^