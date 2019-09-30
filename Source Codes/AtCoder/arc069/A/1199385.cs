using System;
using System.Linq;

namespace abc_055_C
{
    class Program
    {
        public static long a = 0;
        static void Main(string[] args)
        {
            long[] gf = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long s = gf[0], c = gf[1];
            if (s * 2 < c)
            {
                c -= s * 2;
                Console.WriteLine(s + c / 4);
            }
            else
            {
                Console.WriteLine(c / 2);
            }
            Console.ReadLine();
        }
    }
}