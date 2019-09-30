using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace CodeJam2010R1B
{
    public class A
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
                int M = int.Parse( nk[ 1 ] );

                string[ ] have = new string[ N ];
                for ( int j = 0; j < N; ++j )
                {
                    have[ j ] = strAll[ idx++ ];
                }

                string[ ] need = new string[ M ];
                for ( int j = 0; j < M; ++j )
                {
                    need[ j ] = strAll[ idx++ ];
                }

                writer.WriteLine( "Case #" + i + ": " + Calc( have, need ) );
            }
        }

        private int Calc( string[ ] have, string[ ] need )
        {
            Hashtable ht = new Hashtable( );

            for ( int i = 0; i < have.Length; ++i )
            {
                Add( ref ht, have[ i ] );
            }

            int havecnt = ht.Count;

            for ( int i = 0; i < need.Length; ++i )
            {
                Add( ref ht, need[ i ] );
            }

            return ht.Count - havecnt;
        }

        private void Add( ref Hashtable ht, string s )
        {
            while ( s.Length > 0 )
            {
                ht[ s ] = 1;
                int pos = s.LastIndexOf( '/' );
                s = s.Substring( 0, pos );
            }
        }
    }

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
            new CodeJam2010R1B.A( ).Solve( );
        }
    }
}
