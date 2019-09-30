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

            string[] p = Console.ReadLine().Split();
            int N = int.Parse(p[0]);
            int M = int.Parse(p[1]);

            long[] a = new long[N];
            long[] A = new long[N];
            p = Console.ReadLine().Split();
            for (int i = 0; i < N; i++)
            {
                a[i] = long.Parse(p[i * 2]);
                A[i] = long.Parse(p[i * 2 + 1]);
            }

            long[] b = new long[M];
            long[] B = new long[M];
            p = Console.ReadLine().Split();
            for (int i = 0; i < M; i++)
            {
                b[i] = long.Parse(p[i * 2]);
                B[i] = long.Parse(p[i * 2 + 1]);
            }

            if (N < 1 || N > 3) throw new Exception();

            long ret = 0;
            for (int to = 0; to < M; to++)
            {
                for (int to2 = to; to2 < M; to2++)
                {
                    long[] na = (long[])a.Clone();
                    long[] nb = (long[])b.Clone();
                    long curret = 0;
                    for (int i = 0; i < M; i++)
                    {
                        if (i <= to && B[i] == A[0])
                        {
                            long take = Math.Min(na[0], nb[i]);
                            curret += take;
                            na[0] -= take;
                            nb[i] -= take;
                        }
                        if (N >= 2 && to <= i && i <= to2 && B[i] == A[1])
                        {
                            long take = Math.Min(na[1], nb[i]);
                            curret += take;
                            na[1] -= take;
                            nb[i] -= take;
                        }
                        if (N >= 3 && to2 <= i && B[i] == A[2])
                        {
                            long take = Math.Min(na[2], nb[i]);
                            curret += take;
                            na[2] -= take;
                            nb[i] -= take;
                        }
                    }
                    ret = Math.Max(ret, curret);
                }
            }
            Console.WriteLine("Case #" + CASE + ": " + ret);
        }
    }
}
