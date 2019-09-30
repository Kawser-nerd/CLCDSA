using System;
using System.Collections.Generic;
using System.Linq;

namespace arc_013_B
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[,] a = new int[n,3];
            for(int i = 0; i < n; i++)
            {
                int[] h = Console.ReadLine().Split().Select(int.Parse).ToArray();
                Array.Sort(h);
                a[i, 0] = h[0];
                a[i, 1] = h[1];
                a[i, 2] = h[2];
            }
            int ans = 1;
            for(int i = 0; i < 3; i++)
            {
                int max = 0;
                for(int k = 0; k < n; k++)
                {
                 max=   Math.Max(max,a[k,i]);
                }
                ans *= max;
            }
            Console.WriteLine(ans);
            Console.ReadLine();
        }
    }
}