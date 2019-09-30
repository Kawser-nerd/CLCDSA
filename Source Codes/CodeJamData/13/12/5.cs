using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Problem
{
    private static StreamReader reader;

    static void improveMax(ref int a, int b)
    {
        a = Math.Max(a, b);
    }

    static int Solve()
    {
        string[] ss = reader.ReadLine().Split();
        int e = int.Parse(ss[0]), r = int.Parse(ss[1]), n = int.Parse(ss[2]);

        int[, ] p = new int[n + 1, e + 1];

        ss = reader.ReadLine().Split();
        foreach (int i in Enumerable.Range(0, n))
        {
            int v = int.Parse(ss[i]);
            foreach (int j in Enumerable.Range(0, e + 1))
            {
                for (int k = 0; j - k >= 0; k++)
                    improveMax(ref p[i + 1, Math.Min(e, j - k + r)], p[i, j] + v * k);
            }
        }

        return Enumerable.Range(0, e + 1).Max(j => p[n, j]);
    }

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        reader = new StreamReader(bs);

        foreach (int i in Enumerable.Range(1, int.Parse(reader.ReadLine())))
            Console.WriteLine("Case #{0}: {1}", i, Solve());
    }
}
