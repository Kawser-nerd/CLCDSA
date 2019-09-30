//????????
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define MOD 1000000007
#define INFTY 2147483646
#define DEBUG 1
#define END printf("\n");return 0;
#define QS09(how_data,data) qsort(data,how_data,sizeof(long),(int (*)(const void *,const void *))qsort_09);
#define QS90(how_data,data) qsort(data,how_data,sizeof(long),(int (*)(const void *,const void *))qsort_90);
//???2??CE?????????define??????????????????????????????
#define ST_NAME _GD
#define KEY_NAME how_vertex

#define ST09(how_data,data) qsort(data,how_data,sizeof(ST_NAME),(int (*)(const void *,const void *))qsort_st09);
#define ST90(how_data,data) qsort(data,how_data,sizeof(ST_NAME),(int (*)(const void *,const void *))qsort_st90);
#define In(a) long a;scanf("%ld",&a);
#define Out(a) printf("%ld\n",a);
#define dprintf if(DEBUG)printf
#define ifdebug if(DEBUG)
#define MAKE_ARRAY_DATA In(how_data);long data[how_data];input_array(how_data,data);


//???????????? ????main????????ST_NAME?KEY_NAME?????
/*
    #undef ST_NAME
    #undef KEY_NAME
    #define ST_NAME _GD
    #define KEY_NAME how_vertex
    ST09(how_data,data);
*/


//??
void input_array(long how_data,long *data); //?????
void output_array(long how_data,long *data); //?????
void input_array2(long first , long second , long data[][2]); //2???????
void format_array(long how_data ,long *data,long what); //?????
long get_random(long min, long max); //min?max???????
long factorial(long n); //n!
long fibonacci(long n); //n?????????
int qsort_09(const int *sys1 , const int *sys2);
int qsort_90(const int *sys1 , const int *sys2);
int qsort_st09(const void *c1, const void *c2);
int qsort_st90(const void *c1, const void *c2);
long sel_max(long a , long b);
long sel_min(long a , long b);
long array_max(long how_data,long *data);
long array_min(long how_data,long *data);
long array_search(long how_data,long *data,long what);
long can_DP(long how_data,long *data,long how_can,bool *can);
long array_sum(long how_data,long *data);
long Leven_dist(char *now , char *target);
long get_digit(long target);
long rounding(double target);
long roundingdown(double target);
long roundingup(double target);
long ncr(long n , long r);
long npr(long n , long r);
long nhr(long n , long r);
int fifw(long add,long *data);
long fifr(long *data);
void GRAPH_input(void);
void GRAPH_dfs(long now);
bool check_prime(long target);
long get_lcm(long a,long b);
long get_gcd(long a,long b);

//?????????
long fifo[1000]={0};//fifo[0]??????
long loop1,loop2,loop3,loop4,loop5,i_temp;
long g_ans=0; //answer????????

typedef struct{
    long how_vertex;
    long how_edge;
    long edge_data[1000][2];
    bool aleady_searched_vertex[500];
    bool all_searched;
} _GD;//GraphData

_GD GRAPH={0,0,{{0}},{0},0};

char c_temp;
//loop5 loop4 loop3 loop2 loop1
//--------------????

long map_data[100][100];

int main(void){
    In(x);In(y);In(xy);In(want_x);In(want_y);
    //AB???2?????????????????????2?????
    xy*=2;
    long ans=0; //?????
    //x+y?xy??????AB???????????????
    if(x+y>xy){//AB??????????
        if(want_x>want_y){
            ans+=xy*want_y; //B????????
            if(x<xy){ //A???????????(??????)
                ans+=x*(want_x-want_y);
                Out(ans);
                END;
            }else{
                ans+=xy*(want_x-want_y);
                Out(ans);
                END;
            }
            
        }else{
            ans+=xy*want_x;
            if(y<xy){
                ans+=y*(want_y-want_x);
                Out(ans);
                END;
            }else{
                ans+=xy*(want_y-want_x);
                Out(ans);
                END;
            }
        }
        
    }else{//AB???????????
        Out(want_x*x+want_y*y);
        END;
    }

}






//--------------????
 
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
        printf("%ld ",data[loop]);
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
void format_array(long how_data ,long *data,long what){
    long loopA;
    for(loopA=0;loopA<how_data;loopA++){
        data[loopA]=what;
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
int qsort_st09(const void *c1, const void *c2){
    ST_NAME hikaku1= *(ST_NAME *)c1;
    ST_NAME hikaku2= *(ST_NAME *)c2;
    return hikaku1.KEY_NAME - hikaku2.KEY_NAME;
}
int qsort_st90(const void *c1, const void *c2){
    ST_NAME hikaku1= *(ST_NAME *)c1;
    ST_NAME hikaku2= *(ST_NAME *)c2;
    return hikaku2.KEY_NAME - hikaku1.KEY_NAME;
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
long array_search(long how_data,long *data,long what){
    long loop;
    for(loop=0;loop<how_data;loop++){
        if(data[loop]==what){
            return loop;
        }
    }
    return -1;
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
}
long rounding(double target){
    return (long)target+0.50;
}
long roundingup(double target){
    return (long)ceil(target);
}
long roundingdown(double target){
    return (long)floor(target);
}
int fifw(long add,long *data){
    data[data[0]+1]=add;
    data[0]++;
    return data[0]; //???????????
}
long fifr(long *data){
    long ret=data[1];
    data[0]--;
    for(int i=1;i<999;i++){
        data[i]=data[i+1];
    }
    return ret;
}
void GRAPH_input(void){
    scanf("%ld %ld\n",&GRAPH.how_vertex,&GRAPH.how_edge);
    for(long loopA=0;loopA<GRAPH.how_edge;loopA++){
        scanf("%ld %ld\n",&GRAPH.edge_data[loopA][0],&GRAPH.edge_data[loopA][1]);
    }
    return;
}
void GRAPH_dfs(long now){
    GRAPH.aleady_searched_vertex[now]=1;
    for(int loopA=0;loopA<GRAPH.how_edge;loopA++){
        if(GRAPH.edge_data[loopA][0]==now && GRAPH.aleady_searched_vertex[GRAPH.edge_data[loopA][1]]==0){
            GRAPH_dfs(GRAPH.edge_data[loopA][1]);
        }
        if(GRAPH.edge_data[loopA][1]==now && GRAPH.aleady_searched_vertex[GRAPH.edge_data[loopA][0]]==0){
            GRAPH_dfs(GRAPH.edge_data[loopA][0]);
        }
    }
    return ;
}
bool check_prime(long target){//?????????1
    if(target==2)return 1;
    if(target<=1 || target%2==0)return 0;
    for(int loopA=3;loopA<=sqrt(target)+1;loopA+=2)if(target%loopA==0)return 0;
    return 1;
}
long get_lcm(long a,long b){//?????
    return (a*b)/get_gcd(a,b);
}
long get_gcd(long a,long b){//????? ???https://webkaru.net/clang/find-gcd-of-two-number/
    // a>b
    if(a<b){
        int tem=a;
        a=b;
        b=tem;
    }
    long r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
} ./Main.c: In function ‘main’:
./Main.c:20:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define In(a) long a;scanf("%ld",&a);
                      ^
./Main.c:94:5: note: in expansion of macro ‘In’
     In(x);In(y);In(xy);In(want_x);In(want_y);
     ^
./Main.c:20:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define In(a) long a;scanf("%ld",&a);
                      ^
./Main.c:94:11: note: in expansion of macro ‘In’
     In(x);In(y);In(xy);In(want_x);In(want_y);
           ^
./Main.c:20:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define In(a) long a;scanf("%ld",&a);
                      ^
./Main.c:94:17: note: in expansion of macro ‘In’
     In(x);In(y);In(xy);In(want_x);In(want_y);
                 ^
./Main.c:20:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-r...