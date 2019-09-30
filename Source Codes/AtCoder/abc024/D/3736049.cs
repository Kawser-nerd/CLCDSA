using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_024
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            long a = ReadLong();
            long b = ReadLong();
            long c = ReadLong();
            long mask = 1000000000 + 7;

            long ab = MultiMod(a, b, mask);
            long bc = MultiMod(b,c, mask);
            long ca = MultiMod(c,a, mask);

            long div = ab - bc + ca;
            while (div < 0) div += mask;
            div = ReverseMod(div, mask - 2, mask);
            long rr = bc - ca;
            while (rr < 0) rr += mask;
            rr = MultiMod(rr, div, mask);
            long cc = bc - ab;
            while (cc < 0) cc += mask;
            cc = MultiMod(cc, div, mask);
            Console.WriteLine(rr + " " + cc);
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

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}