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
                var M = long.Parse(s[0]);
                var V = long.Parse(s[1]);
                var G = new long[(M - 1) / 2];
                var C = new long[(M - 1) / 2];
                var I = new long[(M + 1) / 2];
                for (int j = 0; j < G.Length; j++)
                {
                    s = reader.ReadLine().Split();
                    G[j] = long.Parse(s[0]);
                    C[j] = long.Parse(s[1]);
                }
                for (int j = 0; j < I.Length; j++)
                {
                    I[j] = long.Parse(reader.ReadLine());
                }
                var res = f(M, V, G, C, I);
                writer.Write("Case #{0}: {1}", i + 1, res < 0 ? "IMPOSSIBLE" : res.ToString());
                writer.WriteLine();
            }
        }
    }

    static long[] values;
    static bool[] changed;
    static long f(long M, long V, long[] G, long[] C, long[] I)
    {
        values = new long[M];
        changed = new bool[C.Length];
        for (int i = 0; i < G.Length; i++)
        {
            values[i] = G[i];
            changed[i] = C[i] != 0;
        }
        for (int i = 0; i < I.Length; i++)
        {
            values[i + G.Length] = I[i];
        }
        cache.Clear();
        return f(0, V);
    }

    static Dictionary<KeyValuePair<long, long>, long> cache =
        new Dictionary<KeyValuePair<long, long>, long>();

    static long f(long i, long V)
    {
        var pair = new KeyValuePair<long, long>(i, V);
        if (cache.ContainsKey(pair)) return cache[pair];
        if (i >= changed.Length)
        {
            return cache[pair] = (values[i] == V ? 0 : -1);
        }
        else
        {
            int b1 = -1, b2 = -1, b3 = -1, b4 = -1;
            if (V == 1 && values[i] == 1) b1 = 0;
            else if (V == 1 && values[i] == 0 && changed[i]) b1 = 1;
            if (V == 1 && values[i] == 0) b2 = 0;
            else if (V == 1 && values[i] == 1 && changed[i]) b2 = 1;
            if (V == 0 && values[i] == 1) b3 = 0;
            else if (V == 0 && values[i] == 0 && changed[i]) b3 = 1;
            if (V == 0 && values[i] == 0) b4 = 0;
            else if (V == 0 && values[i] == 1 && changed[i]) b4 = 1;
            
            long res = long.MaxValue;
            long v10 = f(2 * i + 1, 0),
                 v11 = f(2 * i + 1, 1),
                 v20 = f(2 * i + 2, 0),
                 v21 = f(2 * i + 2, 1);
            if (b1 >= 0)
            {
                if (v11 != -1 && v21 != -1)
                    res = Math.Min(v11 + v21 + b1, res);
            }
            if (b2 >= 0)
            {
                if (v11 != -1 && v21 != -1)
                    res = Math.Min(v11 + v21 + b2, res);
                if (v10 != -1 && v21 != -1)
                    res = Math.Min(v10 + v21 + b2, res);
                if (v11 != -1 && v20 != -1)
                    res = Math.Min(v11 + v20 + b2, res);
            }
            if (b3 >= 0)
            {
                if (v10 != -1 && v20 != -1)
                    res = Math.Min(v10 + v20 + b3, res);
                if (v10 != -1 && v21 != -1)
                    res = Math.Min(v10 + v21 + b3, res);
                if (v11 != -1 && v20 != -1)
                    res = Math.Min(v11 + v20 + b3, res);
            }
            if (b4 >= 0)
            {
                if (v10 != -1 && v20 != -1)
                    res = Math.Min(v10 + v20 + b4, res);
            }
            if (res == long.MaxValue) res = -1;
            return cache[pair] = res;
        }
    }
}