#include <stdio.h>
#include <math.h>

#define MAX 101

int min(int a, int b){
    if(a>b){
        return b;
    } else {
        return a;
    }
}

int sum(int *a, int length){
    int i, summation = 0;
    for(i=0;i<length;i++){
        summation += a[i];
    }
    return summation;
}

int dev(int *a, int b, int length){
    int i, summation = 0;
    for(i=0;i<length;i++){
        summation += abs(a[i]-b);
    }
    return summation;
}

int mean(int *a, int length){
    return sum(a,length)/length;
}

int main(int argc, const char * argv[])
{
    int T, N, i, j, k;
    char str[MAX][MAX];
    int result[MAX];
    char core[MAX];
    int norpt, norpt2;
    int rpt[MAX][MAX];
    int change;
    FILE *in, *out;
    in = fopen("/Users/ahn/Documents/round 1B/A/input.txt","r");
    fscanf(in,"%d",&T);
    for(i=0;i<T;i++){
        result[i]=0;
        fscanf(in,"%d",&N);
        for(j=0;j<N;j++){
            fscanf(in,"%s",str[j]);
        }
        norpt = 0;
        core[0] = str[0][0];
        for(j=1;j<MAX;j++){
            if(str[0][j] == 0){
                break;
            }
            if(core[norpt] == str[0][j]){
                continue;
            } else {
                core[++norpt] = str[0][j];
            }
        }
        core[norpt+1] = 0;
        for(j=0;j<=norpt;j++){
            for(k=0;k<N;k++){
                rpt[j][k]=0;
            }
        }
        for(j=0;j<N;j++){
            norpt2=0;
            for(k=0;k<MAX;k++){
                if(str[j][k] == 0 || norpt2 > norpt){
                    break;
                }
                else if(str[j][k] != core[norpt2]){
                    if(rpt[norpt2][j] == 0){
                        result[i] = -1;
                        break;
                    } else if(str[j][k] == core[++norpt2]){
                        rpt[norpt2][j]++;
                    } else {
                        result[i] = -1;
                        break;
                    }
                } else {
                    rpt[norpt2][j]++;
                }
            }
            if(str[j][k] != 0 || norpt2 != norpt){
                result[i] = -1;
                break;
            }
        }
        if(result[i] == -1){
            continue;
        }
        for(j=0;j<=norpt;j++){
            change = min(dev(rpt[j],mean(rpt[j],N),N),dev(rpt[j],mean(rpt[j],N),N));
            result[i] += change;
        }
    }
    
    fclose(in);
    
    out = fopen("/Users/ahn/Documents/round 1B/A/output","w");
    for(i=0;i<T;i++){
        fprintf(out,"Case #%d: ",i+1);
        if(result[i] == -1){
            fprintf(out,"Fegla Won\n");
        } else {
            fprintf(out,"%d\n",result[i]);
        }
    }
    fclose(out);
    return 0;
}

