using System;
using System.Linq;

namespace ABC121D_3
{
    class Program
    {
        static void Main()
        {
            var input = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long A = input[0], B = input[1];
            Console.WriteLine(F(A - 1) ^ F(B));
        }

        static long F(long x) => new[] {x, 1, x + 1, 0}[(x + 4) % 4];
    }
}