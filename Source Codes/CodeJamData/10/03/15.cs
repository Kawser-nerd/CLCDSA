using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _Code_JAM__Theme_Park
{
    class Program
    {
        static void Main( string[] args )
        {

            StreamReader read = new StreamReader( "in.in" );
            StreamWriter write = new StreamWriter( "out.txt", false );

            write.AutoFlush = true;

            int round = int.Parse( read.ReadLine() );

            for( int i = 1 ; i <= round ; i++ )
            {
                string[] line = read.ReadLine().Split( ' ' );

                int runTime = int.Parse( line[ 0 ] );
                int limit = int.Parse( line[ 1 ] );
                int group = int.Parse( line[ 2 ] );

                int[] groups = new int[ group ];

                line = read.ReadLine().Split( ' ' );

                int[ , ] tmpRoundAns = new int[ group, 2 ];

                for( int j = 0 ; j < group ; j++ )
                {
                    groups[ j ] = int.Parse( line[ j ] );

                }

                int startPointer = 0;
                int currentPointer = startPointer;

                long money = 0;

                for( int k = 1 ; k <= runTime ; k++ )
                {
                    if( tmpRoundAns[ startPointer, 0 ] == 0 )
                    {
                        int sum = 0;

                        do
                        {
                            //Console.WriteLine( "ADD {0}", groups[ currentPointer ] );
                            sum += groups[ currentPointer ];
                            currentPointer = ( currentPointer + 1 ) % group;
                        }
                        while( currentPointer != startPointer && ( sum + groups[ currentPointer ] ) <= limit );

                        //Console.WriteLine( "=SUM {0}", sum );
                        tmpRoundAns[ startPointer, 0 ] = sum;
                        tmpRoundAns[ startPointer, 1 ] = currentPointer;

                        startPointer = tmpRoundAns[ startPointer, 1 ];

                        money += sum;
                    }
                    else
                    {
                        //Console.WriteLine( "+SUM {0}", tmpRoundAns[ startPointer, 0 ] );
                        money += tmpRoundAns[ startPointer, 0 ];
                        startPointer = tmpRoundAns[ startPointer, 1 ];
                    }
                }
                //Console.WriteLine( "Case #{0}: {1}", i, money );
                write.WriteLine( "Case #{0}: {1}", i, money );
            }
            //Console.ReadLine();
        }

    }
}