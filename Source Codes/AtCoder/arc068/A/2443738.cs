using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC68_C
{
    class Program
    {
        static void Main(string[] args)
        {

            var x = long.Parse(Console.ReadLine());

            long m = 0;
            if (x % 11 > 0 && x % 11 < 7) m = 1;
            if (x % 11 > 6) m = 2;
            Console.WriteLine( 2 * (x / 11) + m);
        }
    }
}