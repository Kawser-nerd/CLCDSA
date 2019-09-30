using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_006
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);
            int a, b, c;
            for (int i = 0; i <= n; i++)
            {
                c = i;
                a = 3 * n - m + c;
                b = m - 2 * n - 2 * c;
                if (a + b + c == n && a * 2 + b * 3 + c * 4 == m
                    && a >= 0 && b >= 0 && c >= 0)
                {
                    Console.WriteLine(string.Format("{0} {1} {2}", a, b, c));
                    return;
                }
            }
            Console.WriteLine("-1 -1 -1");
        }
    }
}