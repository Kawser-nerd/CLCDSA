using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var k = int.Parse(line[1]);
        var w = new List<int>();
        var count = 0;
        for (int i = 0; i < n; i++)
        {
            var t = int.Parse(Console.ReadLine().Trim());
            if (t <= k) { w.Add(t); count++; }
        }
        var c1 = count / 2; var c2 = count - c1;
        var a1 = new int[c1]; var a2 = new int[c2];
        var p1 = 0; var p2 = 0;
        for (int i = 0; i < count; i++)
        {
            if (i < c1) a1[p1++] = w[i];
            else a2[p2++] = w[i];
        }
        var d1 = makeDic(a1, k);
        var d2 = makeDic(a2, k);
        var ret = 0;
        foreach (var x in d1)
        {
            var wk = k - x.Key;
            if (d2.ContainsKey(wk)) ret += x.Value * d2[wk];
        }
        Console.WriteLine(ret);
    }
    public static Dictionary<int, int> makeDic(int[] a, int k)
    {
        var d = new Dictionary<int, int>();
        var n = a.Length;
        var imax = (int)Math.Pow(2, n);
        for (int i = 0; i < imax; i++)
        {
            var t = 0;
            for (int j = 0; j < n; j++)
                if (((i >> j) & 1) == 1)
                {
                    t += a[j];
                    if (t > k) goto next;
                }
            if (d.ContainsKey(t)) d[t]++;
            else d[t] = 1;
            next:;
        }
        return d;
    }
}