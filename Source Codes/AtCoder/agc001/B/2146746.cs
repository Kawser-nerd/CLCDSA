using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Piramide_de_luz
{
    class Program
    {

        static long MCD(long a, long b)
        {
            return b == 0 ? a : MCD(b, a % b);
        }

        static void Main(string[] args)
        {
            long[] r = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);

            Console.WriteLine((long)3 * (r[0] - MCD(r[0], r[1])));
        }
    }
}