using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace c
{
    class Program
    {
        static bool simple(long a, long b)
        {
            bool won = true;

            while (b != 0)
            {
                if (a >= 2 * b) return won;
                long x = a % b;
                a = b;
                b = x;
                won = !won;
            }
            return won;
        }

        static long solvea(long a1, long a2, long b)
        {
            long ret = 0;
            long win = 2 * b;

            if (a1 < b + 1)
            {
                a1 = b + 1;
            }

            if (a2 > win)
            {
                ret += a2 - win+1;
                a2 = win-1;
            }

            if (a1 == a2)
            {

                if (simple(a1, b)) ret++;
            }
            else
            {
                ret += (a2 - a1) - solveb(b, a1 - b, a2 - b);
            }


            return ret;
        }

        static long solveb(long a, long b1, long b2)
        {
            long win = a / 2;
            long ret = 0;

            if (b1 <= win)
            {
                ret += win - b1;
                b1 = win;
            }

            if (b1 == b2)
            {

                if (simple(a, b1)) ret++;
            }
            else
            {
                ret += (b2-b1) - solvea(b1-a, b2-a, a);
            }

            return ret;
        }

        static long solve(int a1, int a2, int b1, int b2)
        {
            long ret = 0;
            for (int a = a1; a <= a2; a++)
            {
                if (b1 < a)
                    ret += solveb(a, b1, Math.Min(b2, a));
                if (b2 > a)
                    ret += solvea(Math.Max(a, b1), b2, a);
                              
            }
            return ret;
        }

        static void Main(string[] args)
        {
            System.IO.TextReader r = Console.In;

            int t = int.Parse(r.ReadLine());
            for (int i = 0; i < t; i++)
            {
                string [] s = r.ReadLine().Split(' ');

                
                int a1 = int.Parse(s[0]);
                int a2 = int.Parse(s[1]);
                int b1 = int.Parse(s[2]);
                int b2 = int.Parse(s[3]);

                int ret = 0;
                for (int a = a1; a <= a2; a++)
                    for (int b = b1; b <= b2; b++)
                    {
                        if (a > b)
                            if (simple(a, b)) ret++;

                        if (b > a)
                            if (simple(b, a)) ret++;
                    }

                Console.WriteLine("Case #{0}: {1}", i + 1, ret);
            }
        }
        

    }
}
