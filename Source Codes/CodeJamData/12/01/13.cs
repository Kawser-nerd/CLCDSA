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
            return "";
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
                long[ ] ss = StringToLongA( strAll[ idx++ ] );

                string sres = "Case #" + i + ": ";
                sres += Solve( ss[ 0 ] );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve( long p )
        {
            throw new NotImplementedException( );
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

        private string Solve( string p )
        {
            throw new NotImplementedException( );
        }
    }

    public class RunMain
    {
        static void Main( string[ ] args )
        {
            string dir = "D:\\ProgrammingContest\\CodeJam\\";

            //new A( ).Solve( dir + "ASample.txt", dir + "out.txt" );
            new A( ).Solve( dir + "A-small-attempt1.in", dir + "out.txt" );
            //new A( ).Solve( dir + "A-large.in", dir + "out.txt" );

            //new B( ).Solve( dir + "BSample.txt", dir + "out.txt" );
            //new B( ).Solve( dir + "B-small-attempt1.in", dir + "out.txt" );
            //new B( ).Solve( dir + "B-large.in", dir + "out.txt" );
            //new B( ).Solve( dir + "B-large-practice.in", dir + "out.txt" );

            //new C( ).Solve( dir + "CSample.txt", dir + "out.txt" );
            //new C( ).Solve( dir + "C-small-attempt0.in", dir + "out.txt" );
            //new C( ).Solve( dir + "C-large.in", dir + "out.txt" );

            //new D( ).Solve( dir + "DSample.txt", dir + "out.txt" );
            //new D( ).Solve( dir + "D-small-attempt0.in", dir + "out.txt" );
            //new D( ).Solve( dir + "D-large.in", dir + "out.txt" );
        }
    }
}
