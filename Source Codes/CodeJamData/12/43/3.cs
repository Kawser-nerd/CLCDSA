using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class C
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);
            int N = int.Parse(Console.ReadLine());
            int[] x = new int[N - 1];
            string[] p = Console.ReadLine().Split();
            for (int i = 0; i < N - 1; i++)
                x[i] = int.Parse(p[i]) - 1;
            long[] h = new long[N];
            for (int i = 0; i < N; i++)
                h[i] = 1;
            h[0] = 1000;
            bool changed = false;
            for (int num = 0; num <= 10000000; num++)
            {
                changed = false;
                for (int i = 0; i < N - 1; i++)
                {
                    long dx = x[i] - i;
                    long dy = h[x[i]] - h[i];
                    for (int j = i + 1; j < x[i]; j++)
                    {
                        long ndx = j - i;
                        if (ndx * dy <= dx * (h[j] - h[i])) // j is te hoog
                        {
                            changed = true;
                            //if (dy >= 0)
                            { // hoog laatste op
                                long ndy = h[j] - h[i];
                                h[x[i]] = h[i] + (int)Math.Ceiling(dx * (double)ndy / ndx);
                                if (ndx * dy <= dx * (h[j] - h[i])) h[x[i]]++;
                            }
                            //else
                            { // hoog tussen op
                            //    h[j] = (int)Math.Ceiling(1 + ndx * (double)dy / dx);
                            }

                            i = N;
                            break;
                        }
                    }
                    if (i == N) break;

                    for (int j = x[i] + 1; j < N; j++)
                    {
                        long ndx = j - i;
                        // h[i] + ndx * (dy / dx) < h[j]
                        if (ndx * dy < dx * (h[j] - h[i]))
                        {
                            changed = true;
                            long ndy = h[j] - h[i];
                            h[x[i]] = h[i] + (int)Math.Ceiling(dx * (double)ndy / ndx);
                            if (ndx * dy < dx * (h[j] - h[i])) h[x[i]]++;
                            i = N;
                            break;
                        }
                    }
                }

                if (!changed) break;
            }
            if (changed)
                Console.WriteLine("Case #" + CASE + ": Impossible");
            else
            {
                Console.Write("Case #" + CASE + ":");
                for (int i = 0; i < N; i++) Console.Write(" " + h[i]);
                Console.WriteLine();
            }
            Console.Out.Flush();
        }
    }
}
