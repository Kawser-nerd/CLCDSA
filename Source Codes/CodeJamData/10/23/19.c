#include <stdio.h>


#define modulo 100003

#define pascalsmax 501
unsigned int pascals[pascalsmax][pascalsmax];


//use long longs as modulo^2>2^32
int fill(int len, int min, int max) {
    if (len==0)return 1;
    
    if (max<min) {
        return 0;
    }
    
    return (pascals[max-min+1][len]);
}

int count( int len, int max, int include ) {
    if (len==0) return 1;
    if (len==1) return (include==2)?1:0;
    
    int i;
    
    int result=0;
    
    for (i=1; i<=len; i++) {
        result += (int)(((long long)count( i-1, include-1, i ) * (long long)fill( len-i, include+1, max )) %(long long)modulo);
        result %= modulo;
    }
    
    return result;
}

int main () {
    
    int numCases, kase;
    int i,j,n, result;
    
    pascals[0][0] = 1;
    pascals[0][1] = 0;
    for (i=1; i<pascalsmax; i++) {
        pascals[i][0]=1;
        for (j=1; j<=i; j++) {
            pascals[i][j]=(pascals[i-1][j]+pascals[i-1][j-1])%modulo;
        }
        pascals[i][j]=0;
    }
    
    //printf("%d %d %d\n", count(1,4,2),count(2,4,3),count(3,4,4));
    
    scanf("%d", &numCases );
    
    for (kase=1; kase<=numCases; kase++) {
        
        // do stuff
        scanf("%d",&n);
        
        result = 0;
        for (i=1; i<n; i++) {
            result += count( i, n-1, i+1);
            result %= modulo;
        }
        
        printf("Case #%d: %d\n", kase, result);
        
    }
    
    
    return 0;
    
}
