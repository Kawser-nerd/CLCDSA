#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/
struct pair {
    long long data;
    long long num;
};

int compare(struct pair *t, struct pair *s) {
    long long tmp = t->data - s->data;
    if(tmp > 0) return 1;
    if(tmp < 0) return -1;
    return 0;
}


struct list {
    long long ent;
    long long pas;
    struct list *next;
} *first;



struct pair enter[1000];
struct pair dest[1000];

long long N;
long long max;

long long bill(long long start, long long dest) {
    long long tmp = N-(dest-start);
    return max-(tmp*(tmp+1))/2;
}

int main(void) {
    int num;
    int i, j, k;
    long long cur;
    long long M;

    scanf("%d", &num);
    for(i = 1; i <= num; ++i) {
        scanf("%lld %lld", &N, &M);
        max = (N*(N+1))/2;
        cur = 0;
        for(j = 0; j < M; ++j) {
            long long enter_;
            long long dest_;
            long long p;
            scanf("%lld %lld %lld", &enter_, &dest_, &p);
            enter[j].data = enter_;
            enter[j].num = p;
            dest[j].data = dest_;
            dest[j].num = p;
            cur += bill(enter_, dest_)*p; // modulo...
        }
        qsort(enter, M, sizeof(struct pair), compare);
        qsort(dest, M, sizeof(struct pair), compare);
        j = 0;
        k = 0;
        while(j < M) {
            long long guest = dest[j].num;
            long long des = dest[j].data;
            while(k < M && enter[k].data <= des) k++;
            k--;
            while(guest != 0) {
                long long pas;
                while(enter[k].num == 0) k--;
                pas = enter[k].num;
                //printf("%lld-%lld, %lld\n", enter[k].data, dest[j].data, bill(enter[k].data, dest[j].data));
                if(pas >= guest) {
                    enter[k].num -= guest;
                    cur -= bill(enter[k].data, des)*guest;
                    guest = 0;
                }
                else {
                    guest -= pas;
                    cur -= bill(enter[k].data, des)*pas;
                    enter[k].num = 0;
                    --k;
                }

            }
            ++j;
        }

        printf("Case #%d: %lld\n", i, cur % 1000002013LL);
       
    }

    return 0;
}
