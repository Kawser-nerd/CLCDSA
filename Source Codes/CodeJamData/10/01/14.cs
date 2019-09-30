using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _Code_JAM__Snapper_Chain
{
    class Program
    {
        static void Main( string[] args )
        {
            StreamReader read = new StreamReader( "in.in" );
            StreamWriter write = new StreamWriter( "out.txt", false );

            write.AutoFlush = true;

            string line = read.ReadLine();

            int testCaseCount = int.Parse( line );

            bool[] ans = new bool[ testCaseCount ];



            for( int i = 1 ; i <= testCaseCount ; i++ )
            {
                line = read.ReadLine();

                string[] testCase = line.Split( ' ' );

                int snapper = int.Parse( testCase[ 0 ] );
                int snap = int.Parse( testCase[ 1 ] );

                ans[ i - 1 ] = ( ( snap & ( 1 << ( snapper - 1 ) ) ) != 0 );

                int allOn = ( ( 1 << snapper ) - 1 );

                write.WriteLine( "Case #{0}: {1}", i, ( ( snap & allOn ) == allOn ) ? "ON" : "OFF" );

            }

            write.Close();
        }
    }
}