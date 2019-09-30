using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace CodeJam2012R1A
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

                int[ ] ab = StringToIA( strAll[ idx++ ] );
                string[ ] pro = StringToSA( strAll[ idx++ ] );

                sres += Solve( ab, pro );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve( int[ ] ab, string[ ] pro )
        {
            int sofar = ab[ 0 ];
            int total = ab[ 1 ];
            double[ ] p = new double[ total ];
            for ( int i = 0; i < sofar; ++i )
            {
                p[ i ] = double.Parse( pro[ i ] );
            }

////            1.Finish typing the password, then press "enter". I know I'll type the rest of the characters perfectly. If it turns out that one of the earlier characters was wrong, I'll have to retype the whole thing and hit "enter" again -- but I know I'll get it right the second time.
////2.Hit "backspace" some number of times, deleting the last character(s) I typed, and then complete the password and press "enter" as in option 1. If one of the characters I didn't delete was wrong, I'll have to retype the whole thing and press "enter", knowing I'll get it right the second time.
////3.Give up by pressing "enter", retyping the password from the start, and pressing "enter" again. I know I'll get it right this time.

            double best = total + 2;
            double correctP = 1;
            for ( int i = 0; i < sofar; ++i )
            {
                correctP *= p[ i ];
                double exp = ( sofar - i - 1 ) + ( total - i ) + ( 1 - correctP ) * ( total + 1 );
                if ( exp < best )
                {
                    best = exp;
                }
            }

            return best + "";
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
                int n = int.Parse( strAll[ idx++ ] );
                int[ , ] need = new int[ n, 2 ];
                for ( int j = 0; j < n; ++j )
                {
                    int[ ] aa = StringToIA( strAll[ idx++ ] );
                    need[ j, 0 ] = aa[ 0 ];
                    need[ j, 1 ] = aa[ 1 ];
                }

                string sres = "Case #" + i + ": ";
                sres += Solve( n, need );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve( int n, int[ , ] need )
        {
            int star = 0;
            int game = 0;
            int left = n;
            int[ ] used = new int[ n ];
            for ( int loop = 0; left > 0 && loop < 2 * n; ++loop )
            {
                int best = 0;
                int idx = -1;
                bool level2 = false;
                for ( int j = 0; j < n; ++j )
                {
                    if ( used[ j ] >= 2 )
                    {
                        continue;
                    }

                    if ( need[ j, 1 ] <= star )
                    {
                        game += 1;
                        star += ( used[ j ] == 0 ) ? 2 : 1;
                        level2 = true;
                        --left;
                        used[ j ] = 2;
                        break;
                    }

                    if ( used[ j ] >= 1 )
                    {
                        continue;
                    }

                    if ( need[ j, 0 ] <= star && need[ j, 1 ] >= best )
                    {
                        best = need[ j, 1 ];
                        idx = j;
                    }
                }

                if ( !level2 )
                {
                    if ( idx < 0 )
                    {
                        return "Too Bad";
                    }

                    used[ idx ] = 1;
                    game += 1;
                    star += 1;
                }
            }

            return game + "";
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
                sres += Solve( strAll[ idx++ ], strAll, ref idx );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve( string s, string [] strAll, ref int idx )
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
            //new A( ).Solve( dir + "A-small-attempt0.in", dir + "out.txt" );
            //new A( ).Solve( dir + "A-large.in", dir + "out.txt" );

            //new B( ).Solve( dir + "BSample.txt", dir + "out.txt" );
            //new B( ).Solve( dir + "B-small-attempt0.in", dir + "out.txt" );
            new B( ).Solve( dir + "B-large.in", dir + "out.txt" );
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
