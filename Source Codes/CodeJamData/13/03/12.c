#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
int fair(long long n) {
    long long num = n;
    if(num < 10) return 1;
    long long fake = 0;
    
    while(num) {
        fake = 10 * fake + (num % 10);
        num /= 10;
    }
    return fake == n;
}

int check(int num) {
    float fnum = (float) num;
    float sq = sqrt(fnum);
    if(sq > (int)sq) return 0;

    int sqr = (int) sq;
    return fair(num) && fair(sqr);
}
*/
long long fs[39] = {
1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001,
10221412201,
12102420121,
12345654321,
40000800004,
1000002000001,
1002003002001,
1004006004001,
1020304030201,
1022325232201,
1024348434201,
1210024200121,
1212225222121,
1214428244121,
1232346432321,
1234567654321,
4000008000004,
4004009004004
};


int main() {
    char* filename = "test.in";
    int numCase =0;
    
    FILE* fin = fopen(filename, "r");
    fscanf(fin, "%d\n", &numCase);

    int i,j,k;
    for(i = 0; i < numCase; i ++ ) {
        long long  from;
        long long  to;
        fscanf(fin, "%lld %lld", &from, &to);

        int count = 0;
        for(j = 0; j < 39; j ++ ) {
            if(fs[j] < from) continue;
            if(fs[j] > to) break;
            count ++;
        }
        printf("Case #%d: %d\n", i+1, count);

    }
    return 0;
}
