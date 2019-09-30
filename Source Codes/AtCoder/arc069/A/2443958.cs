using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC69_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine().Split();
            var n = long.Parse(s[0]);
            var m = long.Parse(s[1]);
            if (m >= 2 * n)
            {
                long i = (m - 2 * n) / 4;
                Console.WriteLine(n + i);
            }
            else
            {
                Console.WriteLine(Math.Min(n, m/2));
            }
        }
    }
}