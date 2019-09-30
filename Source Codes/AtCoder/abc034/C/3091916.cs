using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_034
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            long w = int.Parse(input[0])-1;
            long h = int.Parse(input[1])-1;

            long max = w + h;
            long min = w < h ? w : h;
            long mask = 1000000007;
            long ptn = 1;
            long div = 1;

            for (int i = 0; i < min; i++)
            {
                ptn = MultiMod(ptn, max - i, mask);
                div = MultiMod(div, min - i, mask);
            }
            Console.WriteLine(
                MultiMod(ptn, ReverseMod(div, mask - 2, mask), mask));
        }

        static long MultiMod(long a, long b, long mask)
        {
            return ((a % mask) * (b % mask)) % mask;
        }

        static long ReverseMod(long a, long pow, long mask)
        {
            if (pow == 0) return 1;
            else if (pow == 1) return a % mask;
            else
            {
                long halfMod = ReverseMod(a, pow / 2, mask);
                long nextMod = MultiMod(halfMod, halfMod, mask);
                if (pow % 2 == 0)
                {
                    return nextMod;
                }
                else
                {
                    return MultiMod(nextMod, a, mask);
                }
            }
        }
    }
}