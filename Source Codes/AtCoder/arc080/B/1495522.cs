using System;
using System.Collections.Generic;
using System.Linq;

namespace arc080_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int n = int.Parse(Console.ReadLine());
            List<int> a = Console.ReadLine().Split().Select(int.Parse).ToArray().ToList();
            int now = 1;
            for (int i = 0; i < x[0]; i++)
            {
                int[] ret = new int[x[1]];
                for (int j = 0; j < x[1]; j++)
                {
                    ret[j] = now;
                    a[0]--;
                    if (a[0] == 0)
                    {
                        a.RemoveAt(0); now++;
                    }
                }
                if (i % 2 == 1) Array.Reverse(ret);
                Console.Write(ret[0]);
                for (int j = 1; j < x[1]; j++)
                {
                    Console.Write(" " + ret[j]);
                }
                Console.WriteLine();
            }
        }
    }
}