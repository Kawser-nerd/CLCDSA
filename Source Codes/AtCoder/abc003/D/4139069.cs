using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_003
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int r = int.Parse(input[0]);
            int c = int.Parse(input[1]);
            input = Console.ReadLine().Split(' ');
            int x = int.Parse(input[0]);
            int y = int.Parse(input[1]);
            input = Console.ReadLine().Split(' ');
            int d = int.Parse(input[0]);
            int l = int.Parse(input[1]);
            if (x * y > d + l && d + l == 0)
            {
                Console.WriteLine(0);
                return;
            }

            int roomPat = (r - x + 1) * (c - y + 1);
            long mask = 1000000007;
            long pat = Combination(x * y, d + l, mask);
            if (x * y > d + l)
            {
                pat -= Combination((x - 1) * y, d + l, mask) * 2;
                pat -= Combination(x * (y - 1), d + l, mask) * 2;
                pat += Combination((x - 1) * (y - 1), d + l, mask) * 4;
                pat += Combination((x - 2) * y, d + l, mask);
                pat += Combination(x * (y - 2), d + l, mask);
                pat -= Combination((x - 2) * (y - 1), d + l, mask) * 2;
                pat -= Combination((x - 1) * (y - 2), d + l, mask) * 2;
                pat += Combination((x - 2) * (y - 2), d + l, mask);
            }
            while (pat < 0) pat += mask;
            pat %= mask;
            long allPat = Combination(d + l, d, mask);
            allPat = MultiMod(allPat, roomPat, mask);
            allPat = MultiMod(allPat, pat, mask);
            Console.WriteLine(allPat);
            //Console.WriteLine(Combination(7, 9, mask));
        }

        static long Combination(long n, long m, long mask)
        {
            if (n < m) return 0;
            if (n - m < m) m = n - m;

            long val = Permutation(n, m, mask);
            long div = Permutation(m, m, mask);
            return MultiMod(val, ReverseMod(div, mask - 2, mask), mask);
        }

        static long Permutation(long n, long m, long mask)
        {
            long val = 1;
            for (long i = 0; i < m; i++)
            {
                val *= ((n - i) % mask);
                val %= mask;
            }
            return val;
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