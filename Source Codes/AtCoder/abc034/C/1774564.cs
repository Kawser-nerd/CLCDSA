using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] Array = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int W = Array[0];
            int H = Array[1];
            long jn = 1000000007;
            long hw2 = 1;
            //(H+W-2)!???
            for (long i = H + W - 2; i != 1; i--)
            {
                hw2 *= i;
                hw2 = hw2 % jn;

            }
            long h1 = 1;
            for (long i = H - 1; i != 1; i--)
            {
                h1 *= i;
                h1 = h1 %jn;

            }
            long w1 = 1;
            for (long i = W - 1; i != 1; i--)
            {
                w1 *= i;
                w1 = w1 % jn;
            }

            long output = hw2;
            long futatume = a?b??p??????(h1, jn - 2, jn);
            long mittume = (a?b??p??????(w1, jn - 2, jn))%jn;

            ;
            output *= futatume;
            output = output % jn;

            output *= mittume;
            output = output % jn;

            Console.WriteLine(output%jn);

        }

        static long a?b??p??????(long a, long b, long p)
        {
            if (b == 0) return 1;
            else if (b % 2 == 0)
            {
                long d = a?b??p??????(a, b / 2, p);
                return (d * d) % p;

            }
            else
            {
                return (a * a?b??p??????(a, b - 1, p)) % p;

            }
        }
    }
}