using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_027
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            long n = long.Parse(Console.ReadLine());
            if (n == 1)
            {
                Console.WriteLine("Aoki");
                return;
            }

            int depth = 0;
            for (long nn = n; nn > 0; nn /= 2) depth++;

            long nc = 1;
            bool isTakahashi = true;
            while (nc <= n)
            {
                nc *= 2;
                if ((depth % 2 == 1 && isTakahashi)
                    || (depth % 2 == 0 && !isTakahashi))
                {
                    nc++;
                }
                isTakahashi = !isTakahashi;
            }

            string s = isTakahashi ? "Takahashi" : "Aoki";
            Console.WriteLine(s);
        }

        //?????????
        static bool DFS(long n, long x)
        {
            if (x >=     n / 2 + 1) return false;

            return !DFS(n, x * 2) || !DFS(n, x * 2 + 1);
        }
    }
}