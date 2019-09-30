using System;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {

        static void Main(string[] args)
        {
            var Y = int.Parse( Console.ReadLine() );
            if( Y%400 == 0 )
            {
                Console.WriteLine( "YES" );
            }
            else if( Y%100 == 0 )
            {
                Console.WriteLine( "NO" );
            }
            else if( Y%4 == 0 )
            {
                Console.WriteLine( "YES" );
            }
            else
            {
                Console.WriteLine( "NO" );
            }
        }

    }
}