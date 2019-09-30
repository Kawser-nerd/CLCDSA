#include <stdio.h>
#include <math.h>

#define MAX 100
#define MAX_DIGIT 30

int min(int a, int b){
    if(a>b){
        return b;
    } else {
        return a;
    }
}

int max(int a, int b){
    if(a>b){
        return a;
    } else {
        return b;
    }
}

int main(int argc, const char * argv[])
{
    int T, i, j, k, l;
    long int A, B, K;
    int a_dig, b_dig, k_dig, dig, dig2;
    long long int poss;
    long long int result[MAX];
    int bigger;
    FILE *in, *out;
    in = fopen("/Users/ahn/Documents/round 1B/B/input.txt","r");
    fscanf(in,"%d",&T);
    for(i=0;i<T;i++){
        fscanf(in,"%ld %ld %ld",&A,&B,&K);
        a_dig = log(A)/log(2)+1;
        b_dig = log(B)/log(2)+1;
        dig = min(a_dig, b_dig);
        dig2 = max(a_dig, b_dig);
        k_dig = log(K)/log(2)+1;
        if(K >= A || K >= B){
            result[i] = A*B;
            continue;
        }
        result[i] = K*A + K*B - K*K;
        for(j=K;j<A;j++){
            for(k=K;k<B;k++){
                bigger=0;
                for(l=dig;l>=0;l--){
                    if( (((j>>l)%2) & ((k>>l)%2)) > ((K>>l)%2) ){
                        break;
                    } else if( (((j>>l)%2) & ((k>>l)%2)) < ((K>>l)%2) ){
                        bigger=1;
                        break;
                    }
                }
                if(bigger){
                    result[i]++;
                } else {
                    continue;
                }
            }
        }
    }
    
    fclose(in);
    
    out = fopen("/Users/ahn/Documents/round 1B/B/output","w");
    for(i=0;i<T;i++){
        fprintf(out,"Case #%d: %lld\n",i+1,result[i]);
    }
    fclose(out);
    return 0;
}

