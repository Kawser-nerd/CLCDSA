using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(ReadLine());
            int[] x = new int[N];
            int[] y = new int[N];
            for (int i = 0; i < N; i++)
            {
                int[] ar = ReadLine().Split(' ').Select(_ => int.Parse(_)).ToArray();
                x[i] = ar[0];
                y[i] = ar[1];
            }
            int cnt = 0;
            for (int i = 0; i < N - 2; i++)
            {
                for (int j = i + 1; j < N - 1; j++)
                {
                    for (int k = j + 1; k < N; k++)
                    {
                        int x1 = x[j] - x[i];
                        int y1 = y[j] - y[i];
                        int x2 = x[k] - x[i];
                        int y2 = y[k] - y[i];
                        long l = ((long)x1 * y2) - ((long)y1 * x2);
                        if (l != 0 && l % 2 == 0)
                            cnt++;
                    }
                }
            }
            WriteLine(cnt);
            ReadLine();
        }
    }
}