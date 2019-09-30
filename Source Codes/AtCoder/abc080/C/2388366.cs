using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[][] f = new int[n][];
            int[][] p = new int[n][];
            int output = int.MinValue;
            for(int i = 0; i < n; i++)
            {
                f[i] = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            }
            for(int i =0; i<n;i++)
            {
                p[i] = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            }
            for(int i = 1; i <= 1023;i++)
            {
                int ans = 0;
                for(int j = 0; j < n; j++)
                {
                    int open = 0;
                    for(int k = 0; k < 10;k++)
                    {
                        if ((i >> k & f[j][k]) == 1) open++;
                    }
                    ans += p[j][open];
                }
                output = Math.Max(output, ans);
            }
            Console.WriteLine(output);
        }
    }
}