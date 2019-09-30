// A - Two Abbreviations
#include <stdio.h>
#include <string.h>
#define MAXSIZE 100000
typedef long long int ll;

ll get_gcd(ll a, ll b);

int main(void){
    char s[MAXSIZE+1], t[MAXSIZE+1];
    ll n, m;
    scanf("%d %d %s %s", &n, &m, s, t);

    ll lcm_length = n * m / get_gcd(n, m);
    //printf("lcm_length = %lld\n", lcm_length);
    int success_flag = 9;
    if(n == m){
        //printf("gcd_length = 1\n");
        success_flag = (strcmp(s, t) == 0);
    }else{
        if(n > m){
            char tmp_s[MAXSIZE + 1];
            strcpy(tmp_s, s);
            strcpy(s, t);
            strcpy(t, tmp_s);

            n = strlen(s);
            m = strlen(t);
        }

        //printf("s: %s, t: %s\n", s, t);
        if(lcm_length == n * m){
            //printf("TAGAINISO\n");
            success_flag = (s[0] == t[0]);
        }else{
            //printf("GCD = %lld > 1\n", get_gcd(n, m));
            ll delta_m = lcm_length / m;
            ll delta_n = lcm_length / n;
            ll index_m = 0, index_n = 0;
            while(index_n < lcm_length){
                //printf("index_n = %lld, index_m = %lld\n", index_n, index_m);
                //printf("index_n / delta_n = %lld index_m / delta_m = %lld\n", index_n / delta_n, index_m / delta_m);
                if(index_m == index_n){
                    if(t[index_m / delta_m] != s[index_n / delta_n]){
                        success_flag = 0;
                        break;
                    }
                }

                if(index_n == index_m){
                    index_n += delta_n;
                }else if(index_n > index_m){
                    index_m += delta_m;
                }else{
                    index_n += delta_n;
                }
            }
            
            success_flag = (success_flag == 9);
        }
    }
    printf("%lld\n", (success_flag)? lcm_length : -1);
    return 0;
}

ll get_gcd(ll a, ll b){
    if(a < b){
        ll tmp;
        tmp = a;
        a = b;
        b = tmp;
    }

    if(a % b == 0) return b;
    return get_gcd(b, a % b);
} ./Main.c: In function ‘main’:
./Main.c:12:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘ll * {aka long long int *}’ [-Wformat=]
     scanf("%d %d %s %s", &n, &m, s, t);
           ^
./Main.c:12:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘ll * {aka long long int *}’ [-Wformat=]
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %s %s", &n, &m, s, t);
     ^