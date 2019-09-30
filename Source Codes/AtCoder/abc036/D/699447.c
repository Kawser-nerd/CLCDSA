#include<stdio.h>

typedef struct{
    int no;
    int next;
}wl;

wl wood[200000];
int wlmax,head[100000];
unsigned long long memo[100000][2];
char done[100000][2];

void in(int a,int b){
    wood[wlmax].next = head[a];
    wood[wlmax].no = b;
    head[a] = wlmax;
    wlmax++;
}
void delpare(int a){
    int i,n,m,*pre;
    n = head[a];
    while(n != (-1)){
        m = head[wood[n].no];
        pre = &(head[wood[n].no]);
        while(m != (-1)){
            if(wood[m].no == a){
                *pre = wood[m].next;
                break;
            }
            pre = &wood[m].next;
            m = wood[m].next;
        }
        n = wood[n].next;
    }
    n = head[a];
    while(n != (-1)){
        i = wood[n].next;
        delpare(wood[n].no);
        n = (wood[n].next);
    }
}

unsigned long long treedp(char pare,int now){
    int n;
    unsigned long long total = 1,a = 1,b = 1;

    if(head[now] == (-1)){
        return (unsigned long long)pare;
    }

    if(done[now][pare - 1] == 1)
        return memo[now][pare - 1];

    if(pare == 1){
        n = head[now];
        while(n != (-1)){
            total *= treedp(2,wood[n].no);
            total %= 1000000007;
            n = wood[n].next;
        }
    }
    else{
        n = head[now];
        while(n != (-1)){
            a *= treedp(1,wood[n].no);b *= treedp(2,wood[n].no);a %= 1000000007;b %= 1000000007;
            n = wood[n].next;
        }
        total = (a + b) % 1000000007;
    }
    done[now][pare - 1] = 1;
    memo[now][pare - 1] = total;
    return total;
}


int main(void){
    int a,b,i,j,k,n;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
        head[i] = (-1);
    for(i = 0;i < n - 1;i++){
        scanf("%d %d",&a,&b);
        in(a - 1,b - 1);
        in(b - 1,a - 1);
    }
    delpare(0);
    printf("%lld\n",treedp(2,0));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:78:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:82:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&a,&b);
         ^