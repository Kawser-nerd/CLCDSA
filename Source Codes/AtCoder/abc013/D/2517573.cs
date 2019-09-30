using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        if (m == 0)
        {
            for (int i = 1; i <= n; i++) Console.WriteLine(i);
            goto m0;
        }
        var d = int.Parse(line[2]);
        var a = Enumerable.Range(0, n).ToArray();
        line = Console.ReadLine().Trim().Split(' ');
        var hs = line.Select(x => int.Parse(x) - 1).ToArray();
        for (int i = 0; i < m; i++) swapAB(a, hs[i]);
        var ba = new int[n];
        for (int i = 0; i < n; i++) ba[a[i]] = i;
        printAns(ba, d);
    m0:;
    }
    public static void printAns(int[] ba, int d)
    {
        var n = ba.Length;
        var dt = getDTable(ba, d);
        var dmax = (int)(Math.Log10(d) / Math.Log10(2)) + 1;
        var w = Enumerable.Range(0, n).ToArray();
        for (int i = 0; i <= dmax; i++)
        {
            if (((d >> i) & 1) == 1)
                for (int j = 0; j < n; j++)
                    w[j] = dt[i,w[j]];
        }
        foreach (var x in w) Console.WriteLine(x + 1);
    }
    public static void swapAB(int[] a, int x)
    {
        var w = a[x];
        a[x] = a[x + 1];
        a[x + 1] = w;
    }
    public static int[,] getDTable(int[] ba, int d)
    {
        var n = ba.Length;
        var dmax = (int)(Math.Log10(d) / Math.Log10(2)) + 1;
        var amax = 31;
        //for (int i = 0; i <= 30; i++)
        //    if ((1L << i) >= dmax) { amax = i+10; break; }
        var ret = new int[amax, n];
        for (int i = 0; i < n; i++) ret[0, i] = ba[i];
        for (int i = 1; i < amax; i++)
            for (int j = 0; j < n; j++)
                ret[i, j] = ret[i - 1, ret[i - 1, j]];
        return ret;
    }
}