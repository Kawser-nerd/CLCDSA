using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace Google.CodeJam.Year2013.Round1A
{
    class ProblemB
    {
        static TextReader Fin = Console.In;
        static TextWriter Fout = Console.Out;
        static TextWriter Ferr = Console.Error;

        static void Main()
        {
            int T = Int32.Parse( Fin.ReadLine() );

            for( int t=1; t<=T; t++ )
                Test(t);
        }

        static void Test(int testNo)
        {
            string[] _t;
            
            _t = Fin.ReadLine().Split(' ');
            var E = long.Parse( _t[0] );
            var R = long.Parse( _t[1] );
            var N = long.Parse( _t[2] );
            var V = new long[N];

            _t = Fin.ReadLine().Split(' ');
            for( long i=0; i<N; i++ )
                V[i] = long.Parse( _t[i] );

            var sol = Solve(E, R, N, V);
            Fout.Write( "Case #{0}: {1}\n", testNo, sol );
            Ferr.Write( "Case #{0}: {1}\r", testNo, sol );
        }

        static long Solve(long E, long R, long N, long[] V)
        {
            return new Simul(E, R, N, V).Solve();

            if( R > E ) R = E;
            E -= R;
            long G = R*V.Sum() + E*V.Max();

            return G;
        }
    }

    class Simul
    {
        long E, R, N;
        long[] V;

        public Simul(long e, long r, long n, long[] v)
        {
            E = e;
            R = r;
            N = n;
            V = v;
        }

        public long Solve()
        {
            return Recurse(E, 0);
        }

        long Recurse(long e, int i)
        {
            long gm = 0;
            if( i >= N ) return 0;
            for( long k=0; k<=e; k++ )
            {
                long g = k*V[i] + Recurse( Math.Min(e-k+R, E), i+1 );
                if( gm < g )
                    gm = g;
            }
            return gm;
        }
    }

}