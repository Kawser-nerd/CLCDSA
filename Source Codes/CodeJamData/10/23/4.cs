using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace CodeJam2010R1B
{
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

            Pre( );

            int T = int.Parse( strAll[ 0 ] );

            for ( int i = 1; i <= T; ++i )
            {
                int n = int.Parse( strAll[ i ] );

                writer.WriteLine( "Case #" + i + ": " + cnt[ n ] );
            }
        }

        const int UP = 505;
        long[ ] cnt = new long[ UP ];
        const long MOD = 100003;

        private void Pre( )
        {
            long[ , ] ncr = new long[ UP, UP ];

            for ( int i = 0; i < UP; ++i )
            {
                ncr[ i, 0 ] = 1;
            }

            for ( int i = 1; i < UP; ++i )
            {
                for ( int j = 1; j <= i; ++j )
                {
                    ncr[ i, j ] = ncr[ i - 1, j ] + ncr[ i - 1, j - 1 ];
                    ncr[ i, j ] %= MOD;
                }
            }

            long[ , ] dp = new long[ UP, UP ];
            for ( int i = 2; i < UP; ++i )
            {
                dp[ i, 1 ] = 1;
            }

            for ( int i = 2; i < UP; ++i )
            {
                for ( int elem = 2; elem < i; ++elem )
                {
                    for ( int k = 1; k < elem; ++k )
                    {
                        if ( i - elem - 1 < 0
                            || elem - k - 1 < 0 )
                        {
                            continue;
                        }

                        dp[ i, elem ] += dp[ elem, k ] * ncr[ i - elem - 1, elem - k - 1 ];
                        dp[ i, elem ] %= MOD;
                    }

                    //Console.WriteLine( "dp[ " + i + ", " + elem + " ] = " + dp[ i, elem ] );
			
                }
            }

            for ( int i = 0; i < UP; ++i )
            {
                cnt[ i ] = 0;
                for ( int j = 0; j < i; ++j )
                {
                    cnt[ i ] += dp[ i, j ];
                    cnt[ i ] %= MOD;
                }
            }
        }
    }

    public class RunMain
    {
        static void Main( string[ ] args )
        {
            new CodeJam2010R1B.C( ).Solve( );
        }
    }
}
