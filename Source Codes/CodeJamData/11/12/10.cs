using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace CodeJam2011R1A
{
    public class Common
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

    public class A : Common
    {
        override public void ParseAndSolve( string[ ] strAll )
        {
            int idx = 0;
            int T = int.Parse( strAll[ idx++ ] );

            for ( int i = 1; i <= T; ++i )
            {
                long [] ss = StringToLongA( strAll[ idx++ ] );

                string sres = "Case #" + i + ": ";
                sres += Solve( ss );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve( long[ ] ss )
        {
            string poss = "Possible";
            string broken = "Broken";

            int n = ( ss[ 0 ] > INF ) ? INF : (int)ss[ 0 ];
            int pd = (int)ss[ 1 ];
            int pg = (int)ss[ 2 ];

            if ( pd > 0 && pg == 0 )
            {
                return broken;
            }

            if ( pd < 100 && pg == 100 )
            {
                return broken;
            }

            for ( int i = 1; i <= n; ++i )
            {
                if ( ( pd * i ) % 100 == 0 )
                {
                    return poss;
                }
            }

            return broken;
        }
    }

    public class B : Common
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
        int[ ] flag;

        private void PreCalc( )
        {
            this.flag = new int[ dict.Length ];
            for ( int i = 0; i < dict.Length; ++i )
            {
                string s = dict[ i ];
                int[ ] cnt = new int[ 26 ];
                for ( int j = 0; j < s.Length; ++j )
                {
                    ++ cnt[ s[ j ] - 'a' ];
                }

                for ( int j = 0; j < 26; ++j )
                {
                    if ( cnt[ j ] > 0 )
                    {
                        flag[ i ] |= ( 1 << j );
                    }
                }
            }
        }

        private string Solve( string[ ] list )
        {
            PreCalc( );

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

            for ( int i = 0; i < dict.Length; ++i )
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

            return dict[ choice ];
        }

        private void Calc( string s, int i )
        {
            int[ ] curr = new int[ dict.Length ];
            int idx = 0;
            for ( int j = 0; j < dict.Length; ++j )
            {
                if ( dict[ j ].Length == dict[ i ].Length )
                {
                    curr[ idx++ ] = j;
                }
            }

            Calc( s, 0, curr, idx, 0, i );
        }

        private void Calc( string s, int dep, int[ ] curr, int size, int sofar, int tgt )
        {
            if ( size <= 0 )
            {
                return;
            }

            if ( dep >= s.Length )
            {
                return;
            }

            if ( size == 1 )
            {
                score[ tgt ] = sofar;
                return;
            }

            int allflag = 0;
            for ( int i = 0; i < size; ++i )
            {
                allflag |= flag[ curr[ i ] ];
            }

            if ( ( allflag & ( 1 << ( s[ dep ] - 'a' ) ) ) == 0 )
            {
                Calc( s, dep + 1, curr, size, sofar, tgt );
            }
            else
            {
                int idx = 0;
                int[ ] next = new int[ size ];
                for ( int i = 0; i < size; ++i )
                {
                    if ( Match( curr[ i ], tgt, s[ dep ] ) )
                    {
                        next[ idx++ ] = curr[ i ];
                    }
                }

                int delta = ( flag[ tgt ] & ( 1 << ( s[ dep ] - 'a' ) ) ) > 0 ? 0 : -1;
                Calc( s, dep + 1, next, idx, sofar + delta, tgt );
            }
        }

        private bool Match( int p, int tgt, char c )
        {
            if ( dict[ p ].Length != dict[ tgt ].Length )
            {
                return false;
            }

            for ( int i = 0; i < dict[ tgt ].Length; ++i )
            {
                if ( dict[ p ][ i ] == c || dict[ tgt ][ i ] == c )
                {
                    if ( dict[ p ][ i ] != dict[ tgt ][ i ] )
                    {
                        return false;
                    }
                }
            }

            return true;
        }
    }

    public class C : Common
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

    public class D : Common
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
            //new A( ).Solve( dir + "A-large.in", dir + "out.txt" );

            //new B( ).Solve( dir + "BSample.txt", dir + "out.txt" );
            new B( ).Solve( dir + "B-small-attempt0.in", dir + "out.txt" );
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
