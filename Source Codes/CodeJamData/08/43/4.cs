using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;

public class Program
{
    public static void Main()
    {
        using (var reader = new StreamReader("input.txt"))
        using (var writer = new StreamWriter("output.txt"))
        {
            var N = int.Parse(reader.ReadLine());
            for (var i = 0; i < N; i++)
            {
                var n = long.Parse(reader.ReadLine());
                long[] x = new long[n], y = new long[n], z = new long[n], p = new long[n];
                for (int j = 0; j < n; j++)
                {
                    var s = reader.ReadLine().Split();
                    x[j] = long.Parse(s[0]);
                    y[j] = long.Parse(s[1]);
                    z[j] = long.Parse(s[2]);
                    p[j] = long.Parse(s[3]);
                }
                var res = f(n, x, y, z, p);
                writer.Write(
                    "Case #{0}: {1:0.000000}",
                    i + 1,
                    res);
                writer.WriteLine();
            }
        }
    }

    static double f(long N, long[] x, long[] y, long[] z, long[] p)
    {
        double res = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                long x1 = x[i], y1 = y[i], z1 = z[i];
                long x2 = x[j], y2 = y[j], z2 = z[j];
                {
                    long t1 = x1 + y1 + z1;
                    long t2 = x2 + y2 + z2;
                    double l = Math.Abs(t1 - t2);// / Math.Sqrt(3);
                    res = Math.Max(res, l / (p[i] + p[j]));
                }
                {
                    long t1 = x1 + y1 - z1;
                    long t2 = x2 + y2 - z2;
                    double l = Math.Abs(t1 - t2);// / Math.Sqrt(3);
                    res = Math.Max(res, l / (p[i] + p[j]));
                }
                {
                    long t1 = x1 - y1 - z1;
                    long t2 = x2 - y2 - z2;
                    double l = Math.Abs(t1 - t2);// / Math.Sqrt(3);
                    res = Math.Max(res, l / (p[i] + p[j]));
                }
            }
        }
        return res;
    }
}