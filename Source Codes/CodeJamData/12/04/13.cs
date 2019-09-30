using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace CodeJam2012R1
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

        virtual public void ParseAndSolve( string[ ] strAll )
        {
            throw new NotImplementedException( );
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
                string sres = "Case #" + i + ": ";
                sres += Solve( strAll[ idx++ ] );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve( string s )
        {
            var map = new Dictionary<char, char>();
            string a = @"
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv";
            string b = @"
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up";
            for ( int i = 0; i < a.Length; ++i )
            {
                map[ a[ i ] ] = b[ i ];
            }

            //for ( char c = 'a'; c <= 'z'; ++ c)
            //{
            //    if ( !map.ContainsKey( c ) )
            //    {
            //        Console.WriteLine( c );
            //    }
            //}

            map[ 'q' ] = 'z';
            map[ 'z' ] = 'q';

            string res = string.Empty;
            for ( int i = 0; i < s.Length; ++i )
            {
                res += map[ s[ i ] ];
            }

            return res;
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
                int[ ] nm = StringToIA( strAll[ idx++ ] );
                string sres = "Case #" + i + ": ";
                sres += Solve( nm );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve( int[ ] d )
        {
            int n = d[ 0 ];
            int sur = d[ 1 ];
            int target = d[ 2 ];
            int[ ] a = new int[ d.Length - 3 ];
            Array.Copy( d, 3, a, 0, a.Length );
            Array.Sort( a );

            int[ , ] can = new int[ 100, 20 ];
            int[ , ] cansur = new int[ 100, 20 ];
            for ( int i = 0; i <= 10; ++i )
            {
                for ( int j = 0; j <= 10; ++j )
                {
                    for ( int k = 0; k <= 10; ++k )
                    {
                        int sum = i + j + k;
                        int best = Math.Max( i, Math.Max( j, k ) );

                        if ( Math.Abs( i - j ) > 2 || Math.Abs( i - k ) > 2 || Math.Abs( j - k ) > 2 )
                        {
                            continue;
                        }

                        if ( Math.Abs( i - j ) == 2 || Math.Abs( i - k ) == 2 || Math.Abs( j - k ) == 2 )
                        {
                            for ( int t = best; t >= 0; --t )
                            {
                                cansur[ sum, t ] = 1;
                            }
                        }
                        else
                        {
                            for ( int t = best; t >= 0; --t )
                            {
                                can[ sum, t ] = 1;
                            }
                        }
                    }
                }
            }

            int cancount = 0;
            int cansurcount = 0;
            for ( int i = 0; i < n; ++i )
            {
                if ( can[ a[ i ], target ] == 1 )
                {
                    ++cancount;
                }
                else if ( cansur[ a[ i ], target ] == 1 )
                {
                    ++cansurcount;
                }
            }

            int res = Math.Min( n, cancount + Math.Min( cansurcount, sur ) );

            return res + "";
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
                int[ ] ss = StringToIA( strAll[ idx++ ] );

                string sres = "Case #" + i + ": ";
                sres += Solve( ss[ 0 ], ss[ 1 ] );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve( int a, int b )
        {
            long count = 0;
            int len = ( a + "" ).Length;
            int min = ( int ) Math.Pow( 10, len - 1 );
            int factor = min;
            bool[ ] used = new bool[ 3000000 ];
            for ( int i = a; i < b; ++i )
            {
                int curr = i;
                for ( int loop = 0; loop < len - 1; ++loop )
                {
                    curr = curr / 10 + ( curr % 10 ) * factor;
                    if ( curr > i && curr <= b )
                    {
                        if ( !used[ curr ] )
                        {
                            used[ curr ] = true;
                            ++count;
                        }
                    }
                }

                curr = i;
                for ( int loop = 0; loop < len - 1; ++loop )
                {
                    curr = curr / 10 + ( curr % 10 ) * factor;
                    if ( curr > i && curr <= b )
                    {
                        used[ curr ] = false;
                    }
                }
            }

            return count + "";
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
                sres += Solve( strAll[ idx++ ], strAll, ref idx );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve( string s, string [] strAll, ref int idx )
        {
            int[ ] aa = StringToIA( s );
            int h = aa[ 0 ];
            int w = aa[ 1 ];
            int d = aa[ 2 ];
            bool[ , ] board = new bool[ h, w ];
            int mx = -1;
            int my = -1;
            for ( int i = 0; i < h; ++i )
            {
                string sa = strAll[ idx++ ];
                for ( int j = 0; j < w; ++j )
                {
                    board[ i, j ] = sa[ j ] == '#';
                    if ( sa[ j ] == 'X' )
                    {
                        mx = i;
                        my = j;
                    }
                }
            }

            // Only for small.
            for ( int i = 1; i < h - 1; ++i )
            {
                for ( int j = 1; j < w - 1; ++j )
                {
                    if ( board[ i, j ] )
                    {
                        return "ignore";
                    }
                }
            }

            mx = mx * 2 - 1;
            my = my * 2 - 1;
            h = ( h - 2 ) * 2;
            w = ( w - 2 ) * 2;
            d *= 2;
            var xPos = GetImages2( mx, h, Math.Max( d, Math.Max( h, w ) ) * 2 );
            //foreach (var a in GetImages( mx, h, Math.Max( d, Math.Max( h, w ) ) * 2, false ))
            //{
            //    xPos[ a.Key ] = 1;
            //}

            var yPos = GetImages2( my, w, Math.Max( d, Math.Max( h, w ) ) * 2 );
            //foreach ( var a in GetImages( my, w, Math.Max( d, Math.Max( h, w ) ) * 2, false ) )
            //{
            //    yPos[ a.Key ] = 1;

            //}

            int count = 0;
            var used = new Dictionary<Tuple<int,int>, int>( );
            foreach ( var xx in xPos )
            {
                foreach ( var yy in yPos )
                {
                    int x = xx.Key;
                    int y = yy.Key;
                    if ( x == mx && y == my )
                    {
                        continue;
                    }

                    if ( Square( mx - x ) + Square( my - y ) <= d * d )
                    {
                        int xdelta = mx - x;
                        int ydelta = my - y;
                        int gcd = (int) GCD( xdelta, ydelta );
                        xdelta /= gcd;
                        ydelta /= gcd;
                        if ( used.ContainsKey( new Tuple<int, int>( xdelta, ydelta ) ) )
                        {
                            continue;
                        }

                        used[ new Tuple<int, int>( xdelta, ydelta ) ] = 1;
                        //Console.WriteLine( x + " " + y + " " + ( Square( mx - x ) + Square( my - y ) ) );
                        ++count;
                    }
                }
            }

            return count + "";
        }

        Int64 GCD( Int64 a, Int64 b )
        {
            a = Math.Abs( a );
            b = Math.Abs( b );
            if ( a < b ) return GCD( b, a );
            if ( b == 0 ) return a;
            return GCD( b, a % b );
        }
        Int64 LCM( Int64 a, Int64 b )
        {
            return a / GCD( a, b ) * b;
        }
        
        int Square( int a )
        {
            return a * a;
        }

        private static Dictionary<int, int> GetImages2( int mx, int h, int d )
        {
            var pos = new Dictionary<int, int>( );
            for ( int i = 0; i * h <= d; ++i )
            {
                int image = i * 2 * h + mx;
                if ( image <= d )
                {
                    pos[ image ] = 1;
                }
                image = i * 2 * h - mx;
                if ( image <= d )
                {
                    pos[ image ] = 1;
                }
                image = -i * 2 * h + mx;
                if ( image <= d )
                {
                    pos[ image ] = 1;
                }
                image = - i * 2 * h - mx;
                if ( image <= d )
                {
                    pos[ image ] = 1;
                }
            }

            return pos;
        }
    }

    public class RunMain
    {
        static void Main( string[ ] args )
        {
            string dir = "D:\\ProgrammingContest\\CodeJam\\";

            //new A( ).Solve( dir + "ASample.txt", dir + "out.txt" );
            //new A( ).Solve( dir + "A-small-attempt1.in", dir + "out.txt" );
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
