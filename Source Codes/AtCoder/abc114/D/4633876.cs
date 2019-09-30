using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace AtCoderABC114
{
    class Program
    {
        static int[] e;
        public static int Num(int m)
        {
            return e.Where(x => x >= m - 1).Count();
        }
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            e = new int[N + 1];
            for (int i = 2; i <= N; i++)
            {
                int cur = i;
                for (int j = 2; j <= N; j++)
                {
                    while (cur % j == 0)
                    {
                        e[j]++;
                        cur /= j;
                    }
                }
            }

            Console.WriteLine(
                Num(75) + Num(25) * (Num(3) - 1) + Num(15) * (Num(5) - 1) + Num(5) * (Num(5) - 1) * (Num(3) - 2) / 2
            );
        }
    }
}