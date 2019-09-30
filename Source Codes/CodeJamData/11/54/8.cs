using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace CodeJam2011R3
{
    public class SolverBase
    {
        #region Helper
        public static int[ ] SAToIA( string[ ] strSplit )
        {
            int[ ] nums = new int[ strSplit.Length ];
            for ( int iTemp = 0; iTemp < strSplit.Length; ++iTemp )
            {
                nums[ iTemp ] = int.Parse( strSplit[ iTemp ] );
            }

            return nums;
        }

        public static long[ ] SAToLongA( string[ ] strSplit )
        {
            long[ ] nums = new long[ strSplit.Length ];
            for ( int iTemp = 0; iTemp < strSplit.Length; ++iTemp )
            {
                nums[ iTemp ] = long.Parse( strSplit[ iTemp ] );
            }

            return nums;
        }

        public static int[ ] StringToIA( string s, char[ ] delim )
        {
            string[ ] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries );
            return SAToIA( strSplit );
        }

        public static int[ ] StringToIA( string s, char c )
        {
            return StringToIA( s, new char[ ] { c } );
        }

        public static int[ ] StringToIA( string s )
        {
            return StringToIA( s, new char[ ] { ' ' } );
        }

        public static long[ ] StringToLongA( string s, char[ ] delim )
        {
            string[ ] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries );
            return SAToLongA( strSplit );
        }

        public static long[ ] StringToLongA( string s, char c )
        {
            return StringToLongA( s, new char[ ] { c } );
        }

        public static long[ ] StringToLongA( string s )
        {
            return StringToLongA( s, new char[ ] { ' ' } );
        }

        public static string[ ] StringToSA( string s, char[ ] delim )
        {
            string[ ] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries );
            return strSplit;
        }

        public static string[ ] StringToSA( string s, char c )
        {
            return StringToSA( s, new char[ ] { c } );
        }

        public static string[ ] StringToSA( string s )
        {
            return StringToSA( s, new char[ ] { ' ' } );
        }
        #endregion Helper

        public const int INF = 1000 * 1000 * 1000;
        public const int OFFSET = 1000;

        protected System.IO.StreamWriter writer;

        public void Solve( string input, string output )
        {
            string filename = input;
            writer = new System.IO.StreamWriter( output );
            string[ ] strAll = System.IO.File.ReadAllText( filename ).Split(
                new char[ ] { '\r', '\n' },
                StringSplitOptions.RemoveEmptyEntries );

            ParseAndSolve( strAll );
            writer.Flush( );
        }

        virtual public void ParseAndSolve(string[] strAll)
        {
 	        throw new NotImplementedException();
        }
    }

    public class A : SolverBase
    {
        override public void ParseAndSolve( string[ ] strAll )
        {
            int idx = 0;
            int T = int.Parse( strAll[ idx++ ] );

            for ( int i = 1; i <= T; ++i )
            {
                // Each test case begins with a line containing five integers:
                // X (the length of the corridor, in meters), S (your walking speed, in meters per second),
                // R (your running speed, in meters per second), t (the maximum time you can run, in seconds) and N (the number of walkways). 
                // Each of the next N lines contains three integers:
                // Bi, Ei and wi - the beginning and end of the walkway (in meters from your starting point) and the speed of the walkway (in meters per second). 
                int [] ss = StringToIA( strAll[ idx++ ] );
                int X = ss[ 0 ];
                int S = ss[ 1 ];
                int R = ss[ 2 ];
                int t = ss[ 3 ];
                int N = ss[ 4 ];
                ++N;

                int[ ] B = new int[ N ];
                int[ ] E = new int[ N ];
                int[ ] W = new int[ N ];

                int sum = 0;
                for ( int j = 0; j < N - 1; ++j )
                {
                    int[ ] tt = StringToIA( strAll[ idx++ ] );
                    B[ j ] = tt[ 0 ];
                    E[ j ] = tt[ 1 ];
                    W[ j ] = tt[ 2 ];
                    sum += E[ j ] - B[ j ];
                }
                B[ N - 1 ] = 0;
                E[ N - 1 ] = X - sum;
                W[ N - 1 ] = 0;

                string sres = "Case #" + i + ": ";
                sres += Solve( X, S, R, t, N, B, E, W );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve( int X, int S, int R, int t, int N, int[ ] B, int[ ] E, int[ ] W )
        {
            double res = 0;
            const long MULT = 1000 * 1000 * 10;

            long[ ] tag = new long[ N ];
            for ( int i = 0; i < N; ++i )
            {
                tag[ i ] = ( long ) W[ i ] * MULT + i;
            }

            Array.Sort( tag );

            double left = t;
            for ( int i = 0; i < N; ++i )
            {
                int cw = ( int ) ( tag[ i ] / MULT );
                int idx = ( int ) ( tag[ i ] % MULT );

                double tRun = ( double ) ( E[ idx ] - B[ idx ] ) / ( W[ idx ] + R );
                double tWalk = ( double ) ( E[ idx ] - B[ idx ] ) / ( W[ idx ] + S );

                if ( tRun <= left )
                {
                    left -= tRun;
                    res += tRun;
                }
                else if ( left == 0 )
                {
                    res += tWalk;
                }
                else
                {
                    double runD = left * ( W[ idx ] + R );
                    double walkD = E[ idx ] - B[ idx ] - runD;
                    res += left + walkD / ( W[ idx ] + S );
                    left = 0;
                }
            }

            return "" + res;
        }
    }

    public class B : SolverBase
    {
        override public void ParseAndSolve( string[ ] strAll )
        {
            int idx = 0;
            int T = int.Parse( strAll[ idx++ ] );

            for ( int i = 1; i <= T; ++i )
            {
                //Each one starts with a line containing 3 integers: R, C and D
                //— the dimensions of the grid and the mass you expected each cell to have.
                // The next R lines each contain C digits wij each,

                int [] nm = StringToIA( strAll[ idx++ ] );
                int R = nm[ 0 ];
                int C = nm[ 1 ];
                int D = nm[ 1 ];

                string[ ] board = new string[ R ];
                for ( int j = 0; j < R; ++j )
                {
                    board[ j ] = strAll[ idx++ ];
                }

                string sres = "Case #" + i + ": ";
                sres += Solve( R, C, D, board );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        string impo = "IMPOSSIBLE";
        private string Solve( int R, int C, int D, string[ ] board )
        {
            int [,] diff = new int [ R, C ];
            for (int i = 0; i < R; ++ i)
			{
                for (int j = 0; j < C; ++ j)
			{
                    diff[ i, j ] = board[ i ][ j ] - '0';
			}
			}

            int best = 0;
            for ( int i = 0; i < R; ++i )
            {
                for ( int j = 0; j < C; ++j )
                {
                    for ( int size = 3; i + size <= R && j + size <= C; ++size )
                    {
                        if ( size <= best ) continue;

                        int cx = 2 * i + size;
                        int cy = 2 * j + size;

                        int sumx = 0;
                        int sumy = 0;

                        for ( int ix = i; ix < i + size; ++ix )
                        {
                            for ( int iy = j; iy < j + size; ++iy )
                            {
                                if ( ix == i && iy == j + size - 1 ) continue;
                                if ( ix == i + size - 1 && iy == j + size - 1 ) continue;
                                if ( ix == i && iy == j ) continue;
                                if ( ix == i + size - 1 && iy == j ) continue;

                                sumx += ( 2 * ix - cx + 1 ) * diff[ ix, iy ];
                                sumy += ( 2 * iy - cy + 1 ) * diff[ ix, iy ];
                            }
                        }

                        if ( sumx == 0 && sumy == 0 && size > best )
                        {
                            best = size;
                        }
                    }
                }
            }

            return ( best == 0 ) ? impo : ( best + "" );
        }
    }

    public class C : SolverBase
    {
        override public void ParseAndSolve( string[ ] strAll )
        {
            int idx = 0;
            int T = int.Parse( strAll[ idx++ ] );

            Precalc( );

            for ( int i = 1; i <= T; ++i )
            {
                long[ ] ss = StringToLongA( strAll[ idx++ ] );

                string sres = "Case #" + i + ": ";
                sres += Solve( ss[ 0 ] );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        const int UP = 1000 * 1000 + 100;
        bool[ ] isPrime = new bool[ UP ];
        private void Precalc( )
        {
            for ( int i = 0; i < UP; ++i )
            {
                isPrime[ i ] = true;
            }

            isPrime[ 0 ] = false;
            isPrime[ 1 ] = false;
            for ( int i = 2; i < UP; ++i )
            {
                if ( isPrime[ i ] )
                {
                    for ( int j = i + i; j < UP; j += i )
                    {
                        isPrime[ j ] = false;
                    }
                }
            }
        }

        private string Solve( long n )
        {
            if ( n == 1 ) return "0";
            if ( n == 2 ) return "1";

            int cnt = 1;
            for ( int i = 2; n / i >= i; ++i )
            {
                if ( isPrime[ i ] )
                {
                    long prod = i;
                    prod *= i;

                    while ( prod <= n )
                    {
                        ++cnt;
                        prod *= i;
                    }
                }
            }

            return cnt + "";
        }
    }

    public class D : SolverBase
    {
        override public void ParseAndSolve( string[ ] strAll )
        {
            int idx = 0;
            int T = int.Parse( strAll[ idx++ ] );

            for ( int i = 1; i <= T; ++i )
            {
                string sres = "Case #" + i + ": ";
                sres += Solve( strAll[ idx++ ] );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        string res = string.Empty;
        private string Solve( string s )
        {
            Calc( s, 0 );

            return res;
        }

        private void Calc( string s, int p )
        {
            if ( p == s.Length )
            {
                long a = Convert.ToInt64( s, 2 );
                long sq = ( long ) Math.Sqrt( a );
                //Console.WriteLine( s + " " + a + " " + sq);

                if ( sq * sq == a )
                {
                    res = s;
                }

                return;
            }

            if ( s[ p ] != '?' )
            {
                Calc( s, p + 1 );
            }
            else
            {
                Calc( s.Substring( 0, p ) + '1' + s.Substring( p + 1 ), p + 1 );
                Calc( s.Substring( 0, p ) + '0' + s.Substring( p + 1 ), p + 1 );
            }
        }
    }

    public class RunMain
    {
        static void Main( string[ ] args )
        {
            string dir = "D:\\ProgrammingContest\\CodeJam\\";

            //new A( ).Solve( dir + "ASample.txt", dir + "out.txt" );
            //new A( ).Solve( dir + "A-small-attempt0.in", dir + "out.txt" );
            //new A( ).Solve( dir + "A-large.in", dir + "out.txt" );

            //new B( ).Solve( dir + "BSample.txt", dir + "out.txt" );
            //new B( ).Solve( dir + "B-small-attempt0.in", dir + "out.txt" );
            //new B( ).Solve( dir + "B-large.in", dir + "out.txt" );
            //new B( ).Solve( dir + "B-large-practice.in", dir + "out.txt" );

            //new C( ).Solve( dir + "CSample.txt", dir + "out.txt" );
            //new C( ).Solve( dir + "C-small-attempt0.in", dir + "out.txt" );
            //new C( ).Solve( dir + "C-large.in", dir + "out.txt" );

            //new D( ).Solve( dir + "DSample.txt", dir + "out.txt" );
            new D( ).Solve( dir + "D-small-attempt0.in", dir + "out.txt" );
            //new D( ).Solve( dir + "D-large.in", dir + "out.txt" );
        }
    }
}
