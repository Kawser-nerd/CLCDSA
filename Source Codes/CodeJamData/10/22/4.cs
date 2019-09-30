using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace CodeJam2010R1B
{
    public class B
    {
        System.IO.StreamWriter writer = new System.IO.StreamWriter( "D:\\ProgrammingContest\\TopCoder\\ProgrammingContest\\ProgrammingContest\\Aout.txt" );
        const int INF = 1000 * 1000 * 1000;
        const int OFFSET = 1000;

        public void Solve( )
        {
            ReadInput( );
            writer.Flush( );
        }

        private void ReadInput( )
        {
            string filename = "D:\\ProgrammingContest\\TopCoder\\ProgrammingContest\\ProgrammingContest\\A.in";
            string[ ] strAll = System.IO.File.ReadAllText( filename ).Split(
                new char[ ] { '\r', '\n' },
                StringSplitOptions.RemoveEmptyEntries );

            int T = int.Parse( strAll[ 0 ] );

            int idx = 1;
            for ( int i = 1; i <= T; ++i )
            {
                string[ ] nk = strAll[ idx ++ ].Split(
                    new char[ ] { ' ' },
                    StringSplitOptions.RemoveEmptyEntries );
                int N = int.Parse( nk[ 0 ] );
                int K = int.Parse( nk[ 1 ] );
                int B = int.Parse( nk[ 2 ] );
                int t = int.Parse( nk[ 3 ] );

                int[ ] xx = new int[ N ];
                string[ ] xxs = strAll[ idx ++ ].Split(
                    new char[ ] { ' ' },
                    StringSplitOptions.RemoveEmptyEntries );
                for ( int j = 0; j < N; ++j )
                {
                    xx[ j ] = int.Parse( xxs[ j ] );
                }

                int[ ] vv = new int[ N ];
                string[ ] vvs = strAll[ idx++ ].Split(
                    new char[ ] { ' ' },
                    StringSplitOptions.RemoveEmptyEntries );
                for ( int j = 0; j < N; ++j )
                {
                    vv[ j ] = int.Parse( vvs[ j ] );
                }

                writer.WriteLine( "Case #" + i + ": " + Calc( N, K, B, t, xx, vv ) );
            }
        }

        private string Calc( int N, int K, int B, int t, int[ ] xx, int[ ] vv )
        {
            int swapcnt = 0;
            int have = 0;
            int cannotSoFar = 0;

            for ( int i = N - 1; i >= 0; --i )
            {
                if ( have >= K )
                {
                    return swapcnt + "";
                }

                int need = ( B - xx[ i ] + vv[ i ] - 1 ) / vv[ i ];

                if ( need > t )
                {
                    ++cannotSoFar;
                }
                else
                {
                    ++have;
                    swapcnt += cannotSoFar;
                }

                if ( have >= K )
                {
                    return swapcnt + "";
                }
            }

            return "IMPOSSIBLE";
        }
    }


    public class C
    {
        System.IO.StreamWriter writer = new System.IO.StreamWriter( "D:\\ProgrammingContest\\TopCoder\\ProgrammingContest\\ProgrammingContest\\Aout.txt" );
        const int INF = 1000 * 1000 * 1000;
        const int OFFSET = 1000;

        public void Solve( )
        {
            ReadInput( );
            writer.Flush( );
        }

        private void ReadInput( )
        {
            string filename = "D:\\ProgrammingContest\\TopCoder\\ProgrammingContest\\ProgrammingContest\\A.in";
            string[ ] strAll = System.IO.File.ReadAllText( filename ).Split(
                new char[ ] { '\r', '\n' },
                StringSplitOptions.RemoveEmptyEntries );

            int T = int.Parse( strAll[ 0 ] );

            for ( int i = 1; i <= T; ++i )
            {
                string[ ] nk = strAll[ 2 * i - 1 ].Split(
                    new char[ ] { ' ' },
                    StringSplitOptions.RemoveEmptyEntries );
                int D = int.Parse( nk[ 0 ] );
                int I = int.Parse( nk[ 1 ] );
                int M = int.Parse( nk[ 2 ] );
                int N = int.Parse( nk[ 3 ] );

                //writer.WriteLine( "Case #" + i + ": " + Calc( D, I, M, N, dot ) );
            }
        }
    }

    public class RunMain
    {
        static void Main( string[ ] args )
        {
            new CodeJam2010R1B.B( ).Solve( );
        }
    }
}
