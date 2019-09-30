using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;
using System.Text;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        long[][] f = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine().Split().Select(long.Parse).ToArray()).ToArray();
        long[][] p = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine().Split().Select(long.Parse).ToArray()).ToArray();
        long[] sister = new long[10];
        long ans = -10000000 * 100 - 1;
        for (int i = 1; i <= 1023; i++)
        {
            long tmp = 0;
            string binary = String.Format("{0:0000000000}", int.Parse(Convert.ToString(i, 2)));
            for(int j = 0; j < 10; j++)
            {
                    sister[j] = binary[j] - '0';
            }
            for(int j = 0; j < n; j++)
            {
                int cnt = 0;
                for(int k = 0; k < 10; k++)
                {
                    if(f[j][k] == 1 && sister[k] == 1) cnt++;
                }
                tmp += p[j][cnt];
            }
            ans = Math.Max(ans, tmp);
        }
        Console.WriteLine(ans);
    }
}