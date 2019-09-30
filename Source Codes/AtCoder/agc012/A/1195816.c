#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define MOD 1000000007
#define END printf("\n");return 0;
#define QS09(how_data,data) qsort(data,how_data,sizeof(long),(int (*)(const void *,const void *))qsort_09);
#define QS90(how_data,data) qsort(data,how_data,sizeof(long),(int (*)(const void *,const void *))qsort_90);
void input_array(long how_data,long *data);
void output_array(long how_data,long *data);
void input_array2(long first , long second , long data[][2]);
long get_random(long min, long max);
long factorial(long n);
long fibonacci(long n);
int qsort_09(const int *sys1 , const int *sys2);
int qsort_90(const int *sys1 , const int *sys2);
long sel_max(long a , long b);
long sel_min(long a , long b);
long array_max(long how_data,long *data);
long array_min(long how_data,long *data);
long can_DP(long how_data,long *data,long how_can,bool *can);
long array_sum(long how_data,long *data);
long Leven_dist(char *now , char *target);
void prime_fact(long target, long *data);
long get_digit(long target);
long ncr(long n , long r);
long npr(long n , long r);
long nhr(long n , long r);
 
long loop1,loop2,loop3,loop4,loop5,i_temp;
char c_temp;
 
int main(void){
    int how_team;
    scanf("%d",&how_team);
    long how_man=how_team*3;
    long data[how_man];
    input_array(how_man,data);
    QS90(how_man,data);
    unsigned long ans=0;
    for(loop1=1;loop1<how_team*2;loop1+=2){
        ans+=data[loop1];
    }
    printf("%ld\n",ans);
    return 0;
    
}
 
 
 
void input_array(long how_data,long *data){
    long loop;
    for(loop=0;loop<how_data;loop++){
        scanf("%ld",&data[loop]);
    }
    return ;
}
void output_array(long how_data,long *data){
    long loop;
    for(loop=0;loop<how_data;loop++){
        printf("%ld\n",data[loop]);
    }
    return ;
}
 
void input_array2(long first,long second,long data[][2]){
    long loopA,loopB;
    for(loopA=0;loopA<first;loopA++){
        for(loopB=0;loopB<second;loopB++){
            scanf("%ld",&data[loopA][loopB]);
        }
    }
    return ;
}
 
long get_random(long min, long max){   //??????????1?????
    //srand((unsigned int)time(0));   //????????????
    rand();rand();rand();rand();    //??????
    return (rand()%(max+1-min))+min;
}
 
 
long factorial(long n){//n!?MOD10^9+7?????
    unsigned long long int ret=1;
    for(long i=1;i<=n;i++)ret=(ret*i)%1000000007;
    return (long)ret;
}
 
int qsort_09(const int *sys1 , const int *sys2){ //???????????
    //qsort(data,how_data,sizeof(long),(int (*)(const void *,const void *))qsort_09);
    if(*sys1<*sys2){
        return -1;
    }else if(*sys1==*sys2){
        return 0;
    }else{
        return 1;
    }
}
 
int qsort_90(const int *sys1 , const int *sys2){ //???????????
    //qsort(data,how_data,sizeof(long),(int (*)(const void *,const void *))qsort_90);
    if(*sys1<*sys2){
        return 1;
    }else if(*sys1==*sys2){
        return 0;
    }else{
        return -1;
    }
}
 
long fibonacci(long n){
    switch(n){
        case 0:return 0;
        case 1:return 1;
        default :return fibonacci(n-1)+fibonacci(n-2);
    }
}
 
long sel_max(long a,long b){
    if(a>b)return a;
    return b;
}
 
long sel_min(long a,long b){
    if(a>b)return b;
    return a;
}
 
long can_DP(long how_data,long *data,long how_can,bool *can){//Typical DP Contest A
    //data????????????can?0 or 1????
    //?????????
    long loopA,loopB;
    long ret=0;
    for(loopA=0;loopA<how_can;loopA++){//???
        can[loopA]=0;
    }
    can[0]=1;//???????
    for(loopA=0;loopA<how_data;loopA++){
        for(loopB=how_can-1;loopB>=0;loopB--){
            if(can[loopB]==1 && loopB+data[loopA]<how_can){
                can[loopB+data[loopA]]=1;
            }
        }
    }
    for(loopA=0;loopA<how_can;loopA++){
        if(can[loopA]==1){
            ret++;
        }
    }
    return ret;
}
long array_max(long how_data,long *data){
    long loop;
    long ret=data[0];
    for(loop=0;loop<how_data;loop++){
        if(ret<data[loop])ret=data[loop];
    }
    return ret;
}
long array_min(long how_data,long *data){
    long loop;
    long ret=data[0];
    for(loop=0;loop<how_data;loop++){
        if(ret>data[loop])ret=data[loop];
    }
    return ret;
}
long array_sum(long how_data,long *data){
    long ret=0;
    long loop;
    for(loop=0;loop<how_data;loop++){
        ret+=data[loop];
    }
    return ret;
}
long Leven_dist(char *now , char *target){
    long loopA,loopB;
    //???????????????
    // ????
    // http://nw.tsuda.ac.jp/class/algoB/c13.html  (????????)
    // http://d.hatena.ne.jp/ohnishiakira/20090809/1249845529  (??)
    long len_now=strlen(now)+1;
    long len_target=strlen(target)+1;
    long d[len_now][len_target]; //???
    for(loopA=0;loopA<len_now;loopA++) d[loopA][0]=loopA;
    for(loopA=0;loopA<len_target;loopA++) d[0][loopA]=loopA;
    for(loopA=1;loopA<len_now;loopA++){
        for(loopB=1;loopB<len_target;loopB++){
            long cost=(now[loopA-1]==target[loopB-1] ? 0:1);
            d[loopA][loopB]=sel_min(sel_min(d[loopA-1][loopB]+1,d[loopA][loopB-1]+1),d[loopA-1][loopB-1]+cost);
        }
    }
    return d[len_now-1][len_target-1];
}
void prime_fact(long target, long *data){
    long loopB=0;
    long loopA=2;
    long moto_target=target;
    while(target!=1){
        loopA-=1;
        while(1){
            loopA++;
            if(loopA>=sqrt(moto_target)+100){
                data[loopB]=target;
                target=1;
                break;
            }
            if(target%loopA==0){
                data[loopB]=loopA;
                target/=loopA;
                loopB++;
                break;
            }
        }
    }
    return ;
}
long get_digit(long target){
    return (long)(log10(target)+1);
}
long ncr(long n , long r){
    //????????
    long loopA,loopB;
    long pascal[100][102]={{0}};
    pascal[1][0]=1;
    pascal[1][1]=1;
    for(loopA=2;loopA<100;loopA++){
        pascal[loopA][0]=1;
        for(loopB=1;loopB<loopA;loopB++){
            pascal[loopA][loopB]=pascal[loopA-1][loopB-1]+pascal[loopA-1][loopB];
        }
        pascal[loopA][loopA]=1;
    }
    return pascal[n][r];
}
long npr(long n, long r){
    return ncr(n,r)*factorial(r);
}
long nhr(long n , long r){
    return ncr(n+r-1,r);
} ./Main.c: In function ‘main’:
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&how_team);
     ^
./Main.c: In function ‘input_array’:
./Main.c:56:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld",&data[loop]);
         ^
./Main.c: In function ‘input_array2’:
./Main.c:72:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%ld",&data[loopA][loopB]);
             ^