// requires .NET 4.0 System.Numerics

using System;
using System.IO;
using System.Collections.Generic;
using BI = System.Numerics.BigInteger;

namespace Google.CodeJam.Year2013.Round1A
{
    class ProblemA
    {
        static TextReader Fin = Console.In;
        static TextWriter Fout = Console.Out;
        static TextWriter Ferr = Console.Error;

        static void Main()
        {
            //Console.WriteLine( Solve(1,  9) );
            //Console.WriteLine( Solve(1, 10) );
            //Console.WriteLine( Solve(1, 2000000000000000000) );
            //return;

            int T = Int32.Parse( Fin.ReadLine() );

            for( int t=1; t<=T; t++ )
                Test(t);
        }

        static void Test(int testNo)
        {
            Int64 r = 0, t = 0;

            var tokens = Fin.ReadLine().Split(' ');
            r = Int64.Parse( tokens[0] );
            t = Int64.Parse( tokens[1] );

            var sol = Solve(r, t);
            Fout.Write( "Case #{0}: {1}\n", testNo, sol );
            Ferr.Write( "Case #{0}: {1}\r", testNo, sol );
        }

        static long Solve(long r, long t)
        {
            // D = (2r-1)^2 + 8t
            // C = (\D-2r-3)/4
            BI p = 2*r-1;
            var q = p*p;
            var d = q + 8*(BI)t;
            //Console.WriteLine( "p: {0}, q: {1}, d: {2}", p, q, d );

            var c = (Sqrt(d)-p)/4;

            //Console.WriteLine( "p: {0}, q: {1}, d: {2} -> {3}, c: {4}", p, q, d, Sqrt(d), c );

            return (long) c;
        }

        static BI Sqrt( BI n )
        {
            BI x0 = 1;
            //Console.WriteLine(">{0}", n);
            for(;;)
            {
                BI x1 = (x0 + n/x0)/2;
                BI dx = x1 - x0;
                x0 = x1;
                if( -1 <= dx && dx <= 1 )
                    break;
                //Console.WriteLine(">{0} {1}", x0, dx);
            }
            while( x0*x0 > n ) x0--;
            return x0;
        }
    }
}