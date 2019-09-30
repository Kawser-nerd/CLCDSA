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
        int[][] csf = Enumerable.Repeat(0, n - 1).Select(_ => Console.ReadLine().Split(' ').Select(int.Parse).ToArray()).ToArray();
        
        for(int i = 0; i < n; i++)
        {
            long time = 0;
            for (int j = i; j < n - 1; j++)
            {
                if (time < csf[j][1])
                {
                    time = csf[j][1];
                }
                long tmp = time / csf[j][1];
                time = tmp * csf[j][1] + ((time - tmp * csf[j][1] + csf[j][2] - 1) / csf[j][2]) * csf[j][2];
                time += csf[j][0];
            }
            Console.WriteLine(time);
        }
    }
}