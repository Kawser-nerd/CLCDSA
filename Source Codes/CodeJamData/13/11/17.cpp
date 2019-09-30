#ifdef VX_PRECOMPILED
    #include "precomp.h"
    typedef mpz_class big;
    // I use 4 cores :)
    #define MAX_THREADS 4
#else
    #include<string>
    #include<iostream>
    #include<fstream>
    #include<sstream>
    #include<assert.h>
    #include<cstdio>
    #include<map>
    #include<algorithm>
    #include<bitset>
    #include<cmath>
    #include<queue>
    #include<functional>
    #include<set>
    #include<sys/stat.h>
    #include<numeric>
    #include<cstdio>
    #include<cstdlib>
    #include<cstring>
    // http://gmplib.org/ (uncomment if solution uses big nums)
    // most likely you'll get an error about mpz_class not being declared...
    //#include "gmpxx.h"
    #define big mpz_class
    // I figure that when other people want to test my solutions they shouldn't
    // get the whole multi-threaded mess that requires and deletes folders and files...
    #define MAX_THREADS 1
#endif

#define for_each(q,s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
typedef long long int64;
#define long int64

using namespace std;

//=========================================================
// program:
//
const long INF =  9223372036854775807LL;;
struct solver
{
    long r, t;
    
    
    long mul(long a, long b)
    {
        if (a >= INF / b) {
            return INF;
        }
        return a*b;
    }
    long add(long a, long b)
    {
        if (a >= INF - b) {
            return INF;
        }
        return a + b;
    }
    long sub(long a, long b)
    {
        if (a >= INF) {
            return INF;
        }
        return a - b;
    }
    
    long f(long x)
    {
        // sum 1 <= i <= x : (r + 2*i - 1)^2 - (r + 2*i - 2) ^2

        // ( (r + 2*i) - 1 ) ^ 2 = (r + 2*i)^ 2 - 2*(r + 2*i) + 1
        // ( (r + 2*i) - 2 ) ^ 2 = (r + 2*i)^ 2 - 4*(r + 2*i) + 4
        
        // (r + 2*i - 1)^2 - (r + 2*i - 2) ^2 
        // = 4*(r + 2*i) - 4 - 2*(r + 2*i) + 1
        // = 2*(r + 2*i) - 3
        // = 2*r + 4*i - 3
        // sum
        // = 2*r*x + 4*S - 3*x
        // = (2*r - 3)*x + 4*S
        
        
        
        //long S = x * (x+1) / 2;
        long S;
        if (x % 2 == 0) {
            S = mul( x/2, x + 1);
        } else {
            S = mul( (x+1)/2, x);
        }
        return add( mul(2*r - 3, x), mul(4, S) );
    }
    
    long solve()
    {
        // max x: t >= f(x)
        long hi = t + 1, lo = 0;
        
        while (lo + 1 < hi) {
            long ha = hi - (hi - lo) / 2;
            if ( f(ha) <= t) {
                lo = ha;
            } else {
                hi = ha;
            }
        }
        
        return lo;
    }
    void init() { }
    void read() {
        cin >> r >> t;
    }
    #if MAX_THREADS > 1
        ofstream cout;
    #endif
    void write(int cn) {
        cout << "Case #"<<cn<<": " << solve() << endl;
    }
    
};

//=========================================================
// I/O:
//
#if MAX_THREADS > 1
    void run(const char* x)
    {
        int r = system(x);
        cerr<<x<<" "<<"("<<r<<")"<<endl;
    }
#endif

int main(int argc, const char* argv[])
{
    int TestCases, mode;
    #if MAX_THREADS == 1
        // Simple and straight forward. 
        cin >> TestCases;
        solver * theSolver = new solver;
        theSolver->init();
        for (int i=1; i<= TestCases; i++) {
            theSolver->read();
            theSolver->write(i);
        }
        delete theSolver;    
    #else
        cin>>TestCases;
        //-------------------------------------------
        // Copy the whole input to a file...
        ofstream f;
        f.open("tests/.input");
        f << cin.rdbuf();
        f.close();
        // Yeah...wipe that folder... Cause we will need its files to be empty
        run("rm ./tests/.t*");
        int k = 0;
        mode = 0;
        // We create some extra threads...
        while (k < MAX_THREADS) {
            if ( fork() == 0 ) {
                mode = k + 1;
                break;
            }
            k++;
        }
        // Reopen the input, this happens for each of the threads...
        if (mode != 0) {
            assert( freopen( "tests/.input","r",stdin) );
        }
    
        solver * theSolver = new solver;
        theSolver->init();
        for (int i=1; i<= TestCases; i++) {
            // Yeah, I don't like this much either
            ofstream f;
            char fn1[200], fn2[200];
            sprintf(fn1, "tests/.test.%d", i);
            sprintf(fn2, "tests/.test.%d.done", i);
            if (mode == 0) {
                // main thread shall just join stuff together as it becomes ready
                struct stat stFileInfo;
                // When a thread finishes a test case, it writes the .done file
                // Wait for that...
                while ( stat(fn2, &stFileInfo) !=0 ) {
                    sleep(1);
                }
                // Now copy the output file...
                ifstream f(fn1);
                cout << f.rdbuf();
            } else {
                // The trick is to make each thread read all the inputs, whether
                // it will process it or not...
                theSolver->read();
                // If fn1 exists, it is being processed already. Else process it
                f.open(fn1, ios_base::out | ios_base::in);
                if ( !f ) {
                    theSolver->cout.open(fn1, ios_base::out);
                    cerr << "[" << i << "/"<<TestCases<<"] "<<mode << endl;
                    theSolver->write(i);
                    theSolver->cout.close();
                    f.open(fn2);
                    f << "1" << endl;
                }
            }
        }
        delete theSolver;
    #endif

    
    return 0;
}
