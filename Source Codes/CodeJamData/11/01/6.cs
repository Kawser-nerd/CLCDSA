using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace CodeJam2011Qual
{
    public class A
    {
        #region Helper
        private static int[ ] SAToIA( string[ ] strSplit )
        {
            int[ ] nums = new int[ strSplit.Length ];
            for ( int iTemp = 0; iTemp < strSplit.Length; ++iTemp )
            {
                nums[ iTemp ] = int.Parse( strSplit[ iTemp ] );
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

        const int INF = 1000 * 1000 * 1000;
        const int OFFSET = 1000;

        System.IO.StreamWriter writer;
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

//        The first line of the input gives the number of test cases, T. T test cases follow. 

//Each test case consists of a single line beginning with a positive integer N, representing the number of buttons that need to be pressed. This is followed by N terms of the form "Ri Pi" where Ri is a robot color (always 'O' or 'B'), and Pi is a button position. 


        private void ParseAndSolve( string[ ] strAll )
        {
            int idx = 0;
            int T = int.Parse( strAll[ idx++ ] );

            for ( int i = 1; i <= T; ++i )
            {
                string [ ] ss = StringToSA( strAll[ idx++ ] );

                string sres = "Case #" + i + ": ";
                sres += Solve( ss );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private int Solve( string[ ] ss )
        {
            int N = int.Parse( ss[ 0 ] );

            int[ ] all = new int[ N ];
            int[ ] blue = new int[ N ];
            int[ ] orange = new int[ N ];
            int blueCnt = 0;
            int orangeCnt = 0;

            int FLAG = 10000;
            for ( int i = 0; i < N; ++i )
            {
                all[ i ] = ( ss[ 2 * i + 1 ] == "B" ? FLAG : 0 ) + int.Parse( ss[ 2 * i + 2 ] );
                if ( all[ i ] > FLAG )
                {
                    blue[ blueCnt++ ] = all[ i ] % FLAG;
                }
                else
                {
                    orange[ orangeCnt++ ] = all[ i ] % FLAG;
                }
            }

            int T = 0;
            int bluePos = 1;
            int orangePos = 1;
            int blueIdx = 0;
            int orangeIdx = 0;
            int allIdx = 0;
            while ( true )
            {
                if ( blueIdx == blueCnt && orangeIdx == orangeCnt )
                {
                    return T;
                }

                ++T;

                bool blueAct = false;
                bool orangeAct = false;

                if ( bluePos < blue[ blueIdx ] )
                {
                    ++bluePos;
                }
                else if ( bluePos > blue[ blueIdx ] )
                {
                    --bluePos;
                }
                else
                {
                    blueAct = true;
                }

                if ( orangePos < orange[ orangeIdx ] )
                {
                    ++orangePos;
                }
                else if ( orangePos > orange[ orangeIdx ] )
                {
                    --orangePos;
                }
                else
                {
                    orangeAct = true;
                }

                if ( all[ allIdx ] > FLAG && bluePos == blue[ blueIdx ] && blueAct )
                {
                    ++blueIdx;
                    ++allIdx;
                }
                else if ( all[ allIdx ] < FLAG && orangePos == orange[ orangeIdx ] && orangeAct )
                {
                    ++orangeIdx;
                    ++allIdx;
                }
            }

        }
    }

    public class RunMain
    {
        static void Main( string[ ] args )
        {
            string dir = "D:\\ProgrammingContest\\CodeJam\\";

            //new CodeJam2011Qual.A( ).Solve( dir + "ASample.txt", dir + "Aout.txt" );
            //new CodeJam2011Qual.A( ).Solve( dir + "A-small-attempt0.in", dir + "Aout.txt" );
            new CodeJam2011Qual.A( ).Solve( dir + "A-large.in", dir + "Aout.txt" );
        }
    }
}
