using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        public static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            long A = long.Parse(s[0]);
            long B = long.Parse(s[1]);
            Console.WriteLine(XorGet(A - 1) ^ XorGet(B));
        }

        static long XorGet(long x)
        {
            return (((x + 1) % 4) == 0) ? 0
                 : (((x + 1) % 4) == 1) ? x
                 : (((x + 1) % 4) == 2) ? 1
                                        : x + 1;
        }
    }
}