using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[][] vertexes = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).ToArray();
        long res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (int k = 0; k < j; k++)
                {
                    int[] a = vertexes[i];
                    int[] b = vertexes[j];
                    int[] c = vertexes[k];
                    long h = Math.Abs((long)(a[0] - c[0]) * (long)(b[1] - c[1]) - (long)(b[0] - c[0]) * (long)(a[1] - c[1]));
                    if (h % 2 == 0 && h != 0) res++;
                }
            }
        }
        Console.WriteLine(res);
    }
}