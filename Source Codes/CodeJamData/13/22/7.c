#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#define TRUE 1
#define FALSE 0

unsigned long factorial(int n)
{
    if (n == 0)
        return 1L;
    if (n == 1)
        return 1L;
    else
        return n * factorial(n - 1);
}


solve () {
    int i,j,k;
    int n, x, y;
    scanf("%d %d %d\n", &n, &x, &y);

    unsigned long a = abs(x)+y;

    unsigned long a1 = a * (a - 1) / 2;


    // if the area is on top of a pyramid (x=0) the condition is stronger
    if(x == 0){
      if(((y+1) * (y+2)/2) > n){
	printf("0.0\n");
	return;
      }
      else{
	printf("1.0\n");
	return;
      }
    }

    // if the pyramid will be too small to get the area, p=0
    if(a1 + y >= n){
      printf("0.0\n");
      return;
    }
    // if the pyramid is large enough to be sure we reach the area, p=1
    if(a1 + a + y + 1 <= n){
      printf("1.0\n");
      return;
    }
    
    // 0 < p < 1
    unsigned long b = n - a1;
    mpz_t tot;
    mpz_init_set_ui(tot,0);
    //    printf("b=%d y=%d\n", b, y);
    mpz_t fac1;
    mpz_init(fac1);
    mpz_t fac2;
    mpz_init(fac2);
    mpz_t fac3;
    mpz_init(fac3);
    mpz_t c;
    mpz_init_set_ui(c,0);


    for(i=y+1; i <= b; i++){
    /*   coin = 1L; */
    /*   if(i < b/2){ */
    /*   	for(j = b - i + 1 ; j <= b; j++){ */
    /*   	  coin = coin * j; */
    /*   	} */
    /*   	coin = coin / factorial(i); */
    /*   } */
    /*   else{ */
    /*   	for(j = i+1; j <= b; j++){ */
    /*   	  coin = coin * j; */
    /*   	} */
    /*   	coin = coin / factorial(b-i); */
    /*   } */
    /*   tot += coin; */
      mpz_fac_ui(fac1,b);
      mpz_fac_ui(fac2,i);
      mpz_fac_ui(fac3,b-i);
      
      mpz_div(c,fac1,fac2);
      mpz_div(c,c,fac3);
      
      mpz_add(tot,tot,c);
      
      //      tot += factorial(b) /(factorial(i) * factorial(b-i));
    }

    mpf_t res;
    mpf_init(res);
    mpf_set_z(res,tot);

    mpf_t p;
    mpf_init(p);
    mpf_set_ui(p,2);
    mpf_pow_ui(p,p,b);
    
    mpf_div(res, res, p);
    mpf_out_str(NULL, 10, 6, res);
    printf("\n");
    //printf("tot = %ld\n",tot);
    /* double res = (tot + 0.); */
    /* for(i=0; i<b;i++){ */
    /*   res = res/2.; */
    /* } */
    //    printf("%f\n",res);

}


int main () {
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int t,i,j;
    scanf ("%d ", &t);
    for (i = 0; i < t; i++) {
      printf("Case #%d: ",i+1);
      solve ();
    }
    return 0;
}
