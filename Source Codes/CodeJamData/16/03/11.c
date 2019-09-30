#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

/* array of bits, up to 512MB (32 bits) */
uint64_t is_prime[((uint64_t)1<<32)/64];
int is_prime_max = 0;

#define IS_PRIME(i)  (is_prime[i/64] &   ((uint64_t) 1 << (i%64)))
#define CLR_PRIME(i) (is_prime[i/64] &= ~((uint64_t) 1 << (i%64)))

void sieve(int N)
{
    is_prime_max = N;
    
    int size = N / 8;
    fprintf(stderr, "prime numbers...(%g MB)\n", size/1024.0/1024.0);
    
    FILE* f = fopen("sieve.dat", "r");
    
    /* try reading the cached version of is_prime */
    if (f && (fread(is_prime, 1, size, f) == size))
    {
        fprintf(stderr, "cached\n");
        fclose(f);
    }
    else
    {
        fprintf(stderr, "computing\n");
        /* compute is_prime for first N numbers and save it to file */
        memset(is_prime, -1, size);

        CLR_PRIME(0);
        CLR_PRIME(1);
        
        int sN = sqrt(N);
        
        for (int i = 2; i <= sN; i++)
        {
            for (int j = 2*i; j < N; j += i)
            {
                CLR_PRIME(j);
            }
            
            if ((i & 0xFF) == 0)
            {
                fprintf(stderr, "%d %g%%\n", i, i * 100.0 / sN);
            }
        }

        FILE* f = fopen("sieve.dat", "w");
        assert(fwrite(is_prime, 1, size, f) == size);
        fclose(f);
    }
}

long interpret(long x, long base)
{
    long n = 0;
    long b = 1;
    for (int i = 0; i < 32; i++)
    {
        if (x & (1<<i))
        {
            n += b;
        }
        b *= base;
    }
    return n;
}

long find_div(long x)
{
    if (x < is_prime_max && IS_PRIME(x))
    {
        return 0;
    }
    
    long sx = sqrt(x);
    for (long k = 2; k <= sx; k++)
    {
        if (x % k == 0)
        {
            return k;
        }
    }
    
    return 0;
}

int build_sol(int x, long divs[11])
{
    for (int b = 2; b <= 10; b++)
    {
        long xi = interpret(x, b);
        divs[b] = find_div(xi);
        //~ printf("%d %d->%ld %d\n", b, x, xi, divs[b]);
        if (divs[b] == 0)
        {
            return 0;
        }
    }
    
    return 1;
}

void main(int argc, char* argv[])
{
    FILE* f = fopen(argv[1], "r");
    assert(f);
    
    int t, n, j;
    assert(fscanf(f, "%d\n", &t) == 1);
    assert(t == 1);
    assert(fscanf(f, "%d %d\n", &n, &j) == 2);
    fprintf(stderr, "%d %d\n", n, j);
    
    sieve(1 << 24);
    
    printf("Case #1:\n");

    int num = 0;
    for (int x = 1 + (1 << (n-1)); x < (1 << n) && num < j; x += 2)
    {
        if (!IS_PRIME(x))
        {
            long divs[11];
            if (build_sol(x, divs))
            {
                for (int i = n-1; i >= 0; i--)
                {
                    printf(x & (1<<i) ? "1" : "0");
                }
                
                for (int b = 2; b <= 10; b++)
                {
                    printf(" %ld", divs[b]);
                }
                printf("\n");
                num++;
            }
        }
    }
}
