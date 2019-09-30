using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace CodeJam2011R2
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
                int [] nm = StringToIA( strAll[ idx++ ] );
                int n = nm[ 0 ];
                int m = nm[ 1 ];

                this.dict = new string[ n ];
                string[ ] list = new string[ m ];
                for ( int j = 0; j < n; ++j )
                {
                    dict[ j ] = strAll[ idx++ ];
                }

                for ( int j = 0; j < m; ++j )
                {
                    list[ j ] = strAll[ idx++ ];
                }

                string sres = "Case #" + i + ": ";
                sres += Solve( list );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        string[ ] dict;

        private string Solve( string[ ] list )
        {
            string res = "";
            for ( int i = 0; i < list.Length; ++i )
            {
                if ( i > 0 )
                {
                    res += " ";
                }

                res += Solve( list[ i ] );
            }

            return res;
        }

        int[ ] score;
        private string Solve( string s )
        {
            score = new int[ dict.Length ];
            for ( int i = 1; i < 12; ++i )
            {
                Calc( s, i );
            }

            int worst = INF;
            int choice = -1;
            for ( int i = 0; i < score.Length; ++i )
            {
                if ( score[ i ] < worst )
                {
                    worst = score[ i ];
                    choice = i;
                }
            }

            Console.WriteLine( dict[ choice ] );

            return dict[ choice ];
        }

        private void Calc( string s, int len )
        {
            int[ ] curr = new int[ dict.Length ];
            int idx = 0;
            for ( int j = 0; j < dict.Length; ++j )
            {
                if ( dict[ j ].Length == len )
                {
                    curr[ idx++ ] = j;
                }
            }

            Calc( s, 0, curr, idx, 0 );
        }

        private void Calc( string s, int dep, int[ ] curr, int size, int sofar )
        {
            if ( size <= 0 || dep >= s.Length )
            {
                return;
            }

            if ( size == 1 )
            {
                score[ curr[ 0 ] ] = sofar;
                return;
            }

            Dictionary<string, Hashtable> group = new Dictionary<string,Hashtable>( );

            for ( int i = 0; i < size; ++i )
            {
                string key = GetKey( dict[ curr[ i ] ], s[ dep ] );

                if ( !group.ContainsKey( key ) )
                {
                    group[ key ] = new Hashtable( );
                }

                group[ key ].Add( curr[ i ], 1 );
            }

            foreach ( KeyValuePair<string, Hashtable> entry in group )
            {
                int[ ] next = new int[ entry.Value.Count ];
                int nidx = 0;
                foreach ( int nn in entry.Value.Keys )
                {
                    next[ nidx++ ] = nn;
                }

                int delta = -1;
                for ( int i = 0; i < entry.Key.Length; ++i )
                {
                    if ( entry.Key[ i ] != '.' )
                    {
                        delta = 0;
                    }
                }

                Calc( s, dep + 1, next, nidx, sofar + delta );
            }
        }

        private string GetKey( string s, char c )
        {
            string res = "";
            for ( int i = 0; i < s.Length; ++i )
            {
                res += ( s[ i ] == c ) ? "X" : ".";
            }

            return res;
        }
    }

    public class C : SolverBase
    {
        override public void ParseAndSolve( string[ ] strAll )
        {
            int idx = 0;
            int T = int.Parse( strAll[ idx++ ] );

            for ( int i = 1; i <= T; ++i )
            {
                ++idx;
                int[ ] ss = StringToIA( strAll[ idx++ ] );

                string sres = "Case #" + i + ": ";
                sres += Solve( ss );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve( int[ ] dd )
        {
            return "";
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
                ++idx;

                int[ ] dd = StringToIA( strAll[ idx++ ] );
                string sres = "Case #" + i + ": ";
                sres += Solve( dd );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve( int[ ] dd )
        {
            return "";
        }
    }

    public class RunMain
    {
        static void Main( string[ ] args )
        {
            string dir = "D:\\ProgrammingContest\\CodeJam\\";

            //new A( ).Solve( dir + "ASample.txt", dir + "out.txt" );
            //new A( ).Solve( dir + "A-small-attempt0.in", dir + "out.txt" );
            new A( ).Solve( dir + "A-large.in", dir + "out.txt" );

            //new B( ).Solve( dir + "BSample.txt", dir + "out.txt" );
            //new B( ).Solve( dir + "B-small-attempt0.in", dir + "out.txt" );
            //new B( ).Solve( dir + "B-large.in", dir + "out.txt" );

            //new C( ).Solve( dir + "CSample.txt", dir + "out.txt" );
            //new C( ).Solve( dir + "C-small-attempt0.in", dir + "out.txt" );
            //new C( ).Solve( dir + "C-large.in", dir + "out.txt" );

            //new D( ).Solve( dir + "DSample.txt", dir + "out.txt" );
            //new D( ).Solve( dir + "D-small-attempt0.in", dir + "out.txt" );
            //new D( ).Solve( dir + "D-large.in", dir + "out.txt" );
        }
    }
}
