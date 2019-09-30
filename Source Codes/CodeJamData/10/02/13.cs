using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;

namespace _Code_JAM__Fair_Warning
{
    class Program
    {
        static void Main( string[] args )
        {
            StreamReader read = new StreamReader( "in.in" );
            StreamWriter write = new StreamWriter( "out.txt", false );

            write.AutoFlush = true;

            int count = int.Parse( read.ReadLine() );

            for( int i = 1 ; i <= count ; i++ )
            {
                string[] line = read.ReadLine().Split( ' ' );

                int para = int.Parse( line[ 0 ] );

                BigInteger[] paras = new BigInteger[ para ];

                for( int j = 0 ; j < para ; j++ )
                {
                    paras[ j ] = BigInteger.Parse( line[ j + 1 ] );
                }

                BigInteger min = BigInteger.Min( paras[ 0 ], paras[ 1 ] );
                BigInteger gcd = BigInteger.Abs( paras[ 0 ] - paras[ 1 ] );

                for( int k = 2 ; k < para ; k++ )
                {
                    min = BigInteger.Min( min, paras[ k ] );
                    gcd = BigInteger.GreatestCommonDivisor( gcd, BigInteger.Abs( paras[ k - 1 ] - paras[ k ] ) );
                }

                BigInteger rmd = BigInteger.Remainder( min, gcd );

                if( rmd.IsZero )
                    write.WriteLine( "Case #{0}: {1}", i, 0 );
                else
                {
                    BigInteger ans = gcd - rmd;

                    write.WriteLine( "Case #{0}: {1}", i, ans.ToString() );
                }
            }

        }
    }
}