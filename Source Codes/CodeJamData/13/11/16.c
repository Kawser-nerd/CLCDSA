#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


#include "gmp.h"



#define bst( AA, BB_l, BB_u, CC_c, DD_d )    int64_t lower##AA = BB_l; int64_t upper##AA = BB_u; int64_t AA; while ( lower##AA < upper##AA ) { AA = lower##AA + ((upper##AA - lower##AA)/2); DD_d; if ( ! (CC_c) ) { lower##AA = AA + 1; } else { upper##AA = AA; } } AA = upper##AA;


int main( int argc, char ** argv, char ** envp ) {
int File = open(argv[1], O_RDONLY);
size_t Size = lseek(File, 0, SEEK_END);
char * Mem = malloc(Size);
lseek(File, 0, SEEK_SET);
read(File, Mem, Size);
close(File);
unsigned int q = 0;
while ( q < Size ) {
	if ( Mem[q] == 0x0a ) { Mem[q] = 0x00; }
	if ( Mem[q] == 0x20 ) { Mem[q] = 0x00; }
	q++;
}
unsigned int Cases = atoi(Mem);
q = strlen(Mem) + 1;
fprintf(stderr, "Cases: %u\n", Cases);
unsigned int Case_T = 0;



mpz_t One;
mpz_t Two;
mpz_t Three;

mpz_init_set_str( One, "1", 10 );
mpz_init_set_str( Two, "2", 10 );
mpz_init_set_str( Three, "3", 10 );

mpz_t tempmpz;
mpz_t ansmpz;
mpz_t a;

mpz_t tmpz;
mpz_t rmpz;

mpz_init( tempmpz);
mpz_init( ansmpz);
mpz_init( a);



while ( Case_T < Cases ) {
/* --------------------- */
	mpz_init_set_str(rmpz, Mem + q, 10); q += ( strlen(Mem + q) + 1 );
	mpz_init_set_str(tmpz, Mem + q, 10); q += ( strlen(Mem + q) + 1 );




	bst( ans, 1, 2000999000LL, (mpz_cmp(tempmpz, tmpz) > 0) , {

mpz_set_si( ansmpz, ans); 

mpz_mul( a, Two, rmpz); 
mpz_sub( a, a, Three); 
mpz_mul( a, a, ansmpz); 

mpz_add( tempmpz, One, ansmpz); 

mpz_mul( tempmpz, tempmpz, ansmpz); 

mpz_mul( tempmpz, Two, tempmpz); 


mpz_add( tempmpz, tempmpz, a);


}  );

// bst( ans, 1, 900099900LL, (((ans*((2*r)-3)) + (2*ans*(ans+1))) > t)  );

	ans --;

	printf("Case #%u: %lld\n", Case_T + 1, (long long)ans );

	mpz_clear(rmpz);
	mpz_clear(tmpz);

	Case_T ++;
/* --------------------- */
}

return 0;
}
