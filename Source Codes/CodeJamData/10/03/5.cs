using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace CodeJam2010
{
    public class A
    {
        System.IO.StreamWriter writer = new System.IO.StreamWriter( "D:\\BackupPlace\\project\\MiscHelper\\MiscHelper\\Aout.txt" );

        public void Solve( )
        {
            ReadInput( );
            writer.Flush( );
        }

        private void ReadInput( )
        {
            string filename = "D:\\BackupPlace\\project\\MiscHelper\\MiscHelper\\A.in";
            string [ ] strAll = System.IO.File.ReadAllText( filename ).Split(
                new char[ ] { '\r', '\n' },
                StringSplitOptions.RemoveEmptyEntries );

            int T = int.Parse( strAll[ 0 ] );

            for ( int i = 1; i <= T; ++i )
            {
                string [] nk = strAll[ i ].Split(
                    new char[ ] { ' ' },
                    StringSplitOptions.RemoveEmptyEntries );
                int N = int.Parse( nk[ 0 ] );
                int K = int.Parse( nk[ 1 ] );

                ++K;
                bool good = ( K % ( 1L << N ) ) == 0;
                writer.WriteLine( "Case #" + i + ": " + ( good ? "ON" : "OFF" ) );
            }
        }
    }

    public class C
    {
        System.IO.StreamWriter writer = new System.IO.StreamWriter( "D:\\BackupPlace\\project\\MiscHelper\\MiscHelper\\Cout.txt" );

        public void Solve( )
        {
            ReadInput( );
            writer.Flush( );
        }

        private void ReadInput( )
        {
            string filename = "D:\\BackupPlace\\project\\MiscHelper\\MiscHelper\\A.in";
            string [ ] strAll = System.IO.File.ReadAllText( filename ).Split(
                new char[ ] { '\r', '\n' },
                StringSplitOptions.RemoveEmptyEntries );

            int T = int.Parse( strAll[ 0 ] );

            for ( int i = 1; i <= T; ++i )
            {
                string [] nk = strAll[ i * 2 - 1 ].Split(
                    new char[ ] { ' ' },
                    StringSplitOptions.RemoveEmptyEntries );
                int R = int.Parse( nk[ 0 ] );
                int K = int.Parse( nk[ 1 ] );
                int N = int.Parse( nk[ 2 ] );

                long sum = Calc( R, K, N, strAll[ i * 2 ] );

                writer.WriteLine( "Case #" + i + ": " + sum );
            }
        }

        private long Calc( int R, int K, int N, string s )
        {
            string [] gs = s.Split(
                new char[ ] { ' ' },
                StringSplitOptions.RemoveEmptyEntries );
            long [] gg = new long[ 2 * N ];
            for ( int i = 0; i < N; ++i )
            {
                gg[ i ] = long.Parse( gs[ i ] );
                gg[ N + i ] = gg[ i ];
            }

            long [] moneyAtTurn = new long[ 2500 ];
            Hashtable ht = new Hashtable( );

            int turn = 0;
            long sum = 0;
            int startIdx = 0;
            while ( turn < R )
            {
                if ( ht.ContainsKey( startIdx ) )
                {
                    break;
                }
                ht.Add( startIdx, turn );

                long pplCnt = 0;
                int currIdx = startIdx;
                for ( int i = 0; i < N; ++i, ++ currIdx )
                {
                    if ( pplCnt + gg[ currIdx ] > K )
                    {
                        break;
                    }

                    pplCnt += gg[ currIdx ];
                }

                sum += pplCnt;
                moneyAtTurn[ turn ] = pplCnt;
                startIdx = currIdx % N;

                ++turn;
            }

            if ( turn >= R )
            {
                return sum;
            }

            int lastSeen = (int) ht[ startIdx ];
            int loopLen = turn - lastSeen;
            long loopSum = 0;
            for ( int i = lastSeen; i < turn; ++i )
            {
                loopSum += moneyAtTurn[ i ];
            }
            sum += ( ( R - turn ) / loopLen ) * loopSum;

            int left = ( R - turn ) % loopLen;
            for ( int i = 0; i < left; ++i )
            {
                sum += moneyAtTurn[ lastSeen + i ];
            }

            return sum;
        }

        static void Main( string[ ] args )
        {
            new CodeJam2010.C( ).Solve( );
        }
    }
}
