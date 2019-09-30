using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class B
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);
            string[] p = Console.ReadLine().Split();
            int N = int.Parse(p[0]);
            int W = int.Parse(p[1]);
            int L = int.Parse(p[2]);
            p = Console.ReadLine().Split();
            int[] r = new int[N];
            int[] or = new int[N];
            for (int i = 0; i < N; i++)
                or[i] = r[i] = int.Parse(p[i]);
            Array.Sort(r); Array.Reverse(r);
            double[] x = new double[N];
            double[] y = new double[N];
            x[0] = 0; y[0] = 0;
            int fstr = 0;
            for (int i = 1; i < N; i++)
            {
                x[i] = x[i - 1] + r[i - 1] + r[i];
                y[i] = y[i - 1];
                if (x[i] > W)
                { // skip to next row
                    x[i] = 0;
                    y[i] = y[fstr] + r[fstr] + r[i];
                    fstr = i;
                }
            }

            Console.Write("Case #" + CASE + ":");
            bool correct = true;
            for (int i = 0; i < N; i++)
            {
                if (x[i] < 0 || x[i] > W || y[i] < 0 || y[i] > L)
                    correct = false;
                for (int j = i + 1; j < N; j++)
                {
                    double dx = x[i] - x[j];
                    double dy = y[i] - y[j];
                    double dr = r[i] + r[j];
                    if (dx * dx + dy * dy < dr * dr)
                        correct = false;
                }
            }
            if (!correct)
            {
                Console.WriteLine("IMPOSSIBLE");
            }
            else
            {
                bool[] used = new bool[N];
                for (int i = 0; i < N; i++)
                {
                    int idx = 0;
                    while (or[i] != r[idx] || used[idx]) idx++;
                    used[idx] = true;
                    Console.Write(" {0} {1}", x[idx], y[idx]);
                }
                Console.WriteLine();
            }
        }
    }
}
