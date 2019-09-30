using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.Linq;

namespace CodeJam2012R2
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
                string [] board = new string[4];
                Array.Copy(strAll, idx, board, 0, 4);
                idx += 4;
                sres += Solve(board);
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve(string[] board)
        {
            char[,] bd = new char[4,4];
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    bd[i, j] = board[i][j];
                }
            }

            for (int i = 0; i < 4; ++i)
            {
                string s = string.Empty;
                for (int j = 0; j < 4; ++j)
                {
                    s += bd[i, j];
                }

                char check = GetOne(s);
                if (check == 'X')
                {
                    return "X won";
                }
                else if (check == 'O')
                {
                    return "O won";
                }
            }

            for (int i = 0; i < 4; ++i)
            {
                string s = string.Empty;
                for (int j = 0; j < 4; ++j)
                {
                    s += bd[j, i];
                }

                char check = GetOne(s);
                if (check == 'X')
                {
                    return "X won";
                }
                else if (check == 'O')
                {
                    return "O won";
                }
            }

            {
                string s = bd[0, 0] + "";
                s += bd[1, 1];
                s += bd[2, 2];
                s += bd[3, 3];
                char check = GetOne(s);
                if (check == 'X')
                {
                    return "X won";
                }
                else if (check == 'O')
                {
                    return "O won";
                }
            }

            {
                string s = bd[0, 3] + "";
                s += bd[1, 2];
                s += bd[2, 1];
                s += bd[3, 0];
                char check = GetOne(s);
                if (check == 'X')
                {
                    return "X won";
                }
                else if (check == 'O')
                {
                    return "O won";
                }
            }

            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    if (bd[i, j] == '.')
                    {
                        return "Game has not completed";
                    }
                }
            }

            return "Draw";
        }

        private char GetOne(string s)
        {
            for (int i = 0; i < 4; ++i)
            {
                if (s[i] == '.')
                {
                    return 'U';
                }
            }

            int xcount = 0;
            int ocount = 0;
            int tcount = 0;
            for (int i = 0; i < 4; ++i)
            {
                if (s[i] == 'X')
                {
                    ++xcount;
                }
                else if (s[i] == 'O')
                {
                    ++ocount;
                }
                else
                {
                    ++tcount;
                }
            }

            if (xcount + tcount == 4)
            {
                return 'X';
            }

            if (ocount + tcount == 4)
            {
                return 'O';
            }

            return 'U';
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
                int n = int.Parse( strAll[ idx++ ] );
                int[ ] see = StringToIA( strAll[ idx++ ] );
                string sres = "Case #" + i + ": ";
                sres += Solve( see );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        string res = "Impossible";
        bool found = false;
        int[ ] local;
        int count = 0;
        private string Solve( int[ ] see )
        {
            int n = see.Length + 1;
            local = see;
            res = "Impossible";
            found = false;
            count = 0;

            CalcSlow( n );
            Console.WriteLine( count );
            return res;
        }

        private void CalcSlow( int n )
        {
            Calc( 0, new int[ n ], new bool[ n ] );
            if ( !found )
            {
                Calc2( 0, new int[ n ], new bool[ n ] );
            }

            if ( !found )
            {
                Calc3( 0, new int[ n ], new bool[ n ] );
            }
        }

        private void Calc( int dep, int[ ] hgt, bool[ ] used )
        {
            if ( found )
            {
                return;
            }

            if ( dep == hgt.Length )
            {
                ++count;
                if ( Good( hgt ) )
                {
                    found = true;
                    res = string.Join( " ", hgt.Select( a => a + "" ) );
                }

                return;
            }

            for ( int i = 0; i < hgt.Length; ++i )
            {
                if ( !used[ i ] )
                {
                    used[ i ] = true;
                    hgt[ dep ] = i + 1;
                    Calc( dep + 1, hgt, used );
                    used[ i ] = false;
                }
            }
        }

        private void Calc2( int dep, int[ ] hgt, bool[ ] used )
        {
            if ( found )
            {
                return;
            }

            if ( dep == hgt.Length )
            {
                ++count;
                if ( Good( hgt ) )
                {
                    found = true;
                    res = string.Join( " ", hgt.Select( a => a + "" ) );
                }

                return;
            }

            for ( int i = 0; i < hgt.Length; ++i )
            {
                if ( !used[ i ] )
                {
                    used[ i ] = true;
                    hgt[ dep ] = 1 << i;
                    Calc( dep + 1, hgt, used );
                    used[ i ] = false;
                }
            }
        }

        private void Calc3( int dep, int[ ] hgt, bool[ ] used )
        {
            if ( found )
            {
                return;
            }

            if ( dep == hgt.Length )
            {
                ++count;
                if ( Good( hgt ) )
                {
                    found = true;
                    res = string.Join( " ", hgt.Select( a => a + "" ) );
                }

                return;
            }

            for ( int i = 0; i < hgt.Length; ++i )
            {
                if ( !used[ i ] )
                {
                    used[ i ] = true;
                    hgt[ dep ] = i * ( i + 1 ) / 2;
                    Calc( dep + 1, hgt, used );
                    used[ i ] = false;
                }
            }
        }

        private bool Good( int[ ] hgt )
        {
            //Console.WriteLine( string.Join( " ", hgt.Select( a => a + "" ) ) );

            for ( int i = 0; i < hgt.Length - 1; ++i )
            {
                int best = i + 1;
                for ( int j = i + 2; j < hgt.Length; ++ j)
                {
                    long aa = ( hgt[ j ] - hgt[ i ] ) * ( best - i );
                    long bb = ( hgt[ best ] - hgt[ i ] ) * ( j - i );
                    //Console.WriteLine( aa + " " + bb );

                    if ( ( hgt[ j ] - hgt[ i ] ) * ( best - i ) > ( hgt[ best ] - hgt[ i ] ) * ( j - i ) )
                    {
                        best = j;
                    }
                }

                //Console.WriteLine( "from {0} = {1}", i, best);
                if ( best != local[ i ] - 1 )
                {
                    return false;
                }
            }

            return true;
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
        static void Main(string[] args)
        {
            string dir = "D:\\MyProj\\CodeJam\\";

            //new A( ).Solve( dir + "ASample.txt", dir + "out.txt" );
            //new A( ).Solve( dir + "A-small-attempt0.in", dir + "out.txt" );
            new A( ).Solve( dir + "A-large.in", dir + "out.txt" );

            //new B( ).Solve( dir + "BSample.txt", dir + "out.txt" );
            //new B( ).Solve( dir + "B-small-attempt0.in", dir + "out.txt" );
            //new B( ).Solve( dir + "B-large.in", dir + "out.txt" );
            //new B( ).Solve( dir + "B-large-practice.in", dir + "out.txt" );

            //new C( ).Solve( dir + "CSample.txt", dir + "out.txt" );
            //new C().Solve(dir + "C-small-attempt0.in", dir + "out.txt");
            //new C( ).Solve( dir + "C-large.in", dir + "out.txt" );

            //new D( ).Solve( dir + "DSample.txt", dir + "out.txt" );
            //new D( ).Solve( dir + "D-small-attempt0.in", dir + "out.txt" );
            //new D( ).Solve( dir + "D-large.in", dir + "out.txt" );
        }
    }
}
