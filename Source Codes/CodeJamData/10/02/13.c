#include <stdio.h>
#include <gmp.h>	// GNU Multiple Precision Arithmetic Library
		 			// http://gmplib.org/

#define MAXN 1000

void gcdMpzArr(mpz_t res, mpz_t a[], int n)
{
 	int i;
 	
 	if(n<2)
 	{
       mpz_abs(res,a[0]);
  	   return;
    }
    mpz_gcd(res,a[0],a[1]);
    for(i=2;i<n;i++)
    {
       mpz_gcd(res,res,a[i]);
       if(mpz_cmp_si(res,1) == 0)
          break;
	}
}

int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int i,tcase,C,N;
    mpz_t t[MAXN],T,k0;
    
    if (argc>1)
       fin=fopen(argv[1],"r");
    else
       fin=fopen("fairWarning.in.txt","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=fopen(argv[2],"w");
    else
       fout=fopen("fairWarning.out.txt","w");
    if (!fout){
       fclose(fin);
       return 1;
 	   }
    mpz_init(T);
    mpz_init(k0);
    for(i=0;i<MAXN;i++)
       mpz_init(t[i]);
    fscanf(fin,"%d",&C);
    for (tcase=1;tcase<=C;tcase++)
    {
       fscanf(fin,"%d",&N);
       if(N<1)
          continue;
       mpz_inp_str(t[0],fin,10);
       for(i=1;i<N;i++)
       {
       	  mpz_inp_str(t[i],fin,10);
       	  mpz_sub(t[i],t[i],t[0]);
       }
       gcdMpzArr(T, t+1, N-1);
       mpz_cdiv_q(k0,t[0],T);
       mpz_mul(k0,k0,T);
       mpz_sub(k0,k0,t[0]);
       fprintf(fout,"Case #%d: ",tcase);
       mpz_out_str(fout,10,k0);
       fprintf(fout,"\n");
    }
    fclose(fin);
    fclose(fout);
	mpz_clear(T);
	mpz_clear(k0);
    for(i=0;i<MAXN;i++)
       mpz_clear(t[i]);
    return 0;
}
