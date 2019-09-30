using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_013
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
            long h = long.Parse(input[1]);

            input= Console.ReadLine().Split(' ');
            long a = long.Parse(input[0]);
            long b = long.Parse(input[1]);
            long c = long.Parse(input[2]);
            long d = long.Parse(input[3]);
            long e = long.Parse(input[4]);

            long minPay = a * n;
            for (int i = 0; i <= n; i++)
            {
                int j = (int)Math.Floor(1.0 * (e * n - h - (b + e) * i) / (d + e) + 1);
                if (j < 0) j = 0;
                long pay = a * i + c * j;
                if (pay < minPay) minPay = pay;
            }
            Console.WriteLine(minPay);
        }
    }
}