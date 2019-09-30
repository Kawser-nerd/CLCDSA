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
                var s = reader.ReadLine().Split();
                var n = long.Parse(s[0]);
                var m = long.Parse(s[1]);
                var a = long.Parse(s[2]);
                var res = f(n, m, a);
                writer.Write(
                    "Case #{0}: {1}",
                    i + 1,
                    res == null
                        ? "IMPOSSIBLE"
                        : res[0] + " " + res[1] + " " + res[2] + " " + res[3] + " " + res[4] + " " +
                          res[5]);
                writer.WriteLine();
            }
        }
    }

    static long[] f(long N, long M, long A)
    {
        if (A > N * M) return null;
        for (int x1 = 0; x1 <= N; x1++)
        {
            for (int y1 = 0; y1 <= M; y1++)
            {
                for (int x2 = 0; x2 <= N; x2++)
                {
                    for (int y2 = 0; y2 <= M; y2++)
                    {
                        if (Math.Abs(x1 * y2 - x2 * y1) == A) return new long[] {0, 0, x1, y1, x2, y2};
                    }
                }
            }
        }
        return null;
    }
}