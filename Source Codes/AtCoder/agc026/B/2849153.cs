using System;
using System.Linq;

namespace AGC026.Task02
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            for (var i = 0; i < n; i++)
            {
                if (Solve())
                {
                    Console.WriteLine("Yes");
                }
                else
                {
                    Console.WriteLine("No");
                }
            }
        }

        public static bool Solve()
        {
            var line = Console.ReadLine().Split(' ').Select(value => long.Parse(value)).ToArray();
            var a = line[0];
            var b = line[1];
            var c = line[2];
            var d = line[3];

            if (b > a)
            {
                return false;
            }

            if (b > d)
            {
                return false;
            }

            if (c >= b) {
                return true;
            }

            var g = Gcd(b, d);
            var max = b - g + (a % g);

            return max <= c;
        }

        static long Gcd(long x, long y)
        {
            if (x < y)
            {
                var t = x;
                x = y;
                y = t;
            }
            while (y != 0)
            {
                var t2 = x % y;
                x = y;
                y = t2;
            }
            return x;
        }
    }
}