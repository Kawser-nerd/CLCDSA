using System;

class Program
{
    static int[] p;
    static int[] c;
    static int G;
    static int D;

    static void Main(string[] args)
    {
        var dg = Console.ReadLine().Split(' ');
        D = int.Parse(dg[0]);
        G = int.Parse(dg[1]);
        p = new int[D];
        c = new int[D];
        for (int i = 0; i < D; i++)
        {
            var s = Console.ReadLine().Split(' ');
            p[i] = int.Parse(s[0]);
            c[i] = int.Parse(s[1]);
        }

        var ans = dfs(0, new bool[D]);
        Console.WriteLine(ans);
    }

    static int dfs(int n, bool[] v)
    {
        if (v.Length <= n)
        {
            return m1(v);
        }

        v[n] = true;
        var left = dfs(n + 1, v);
        v[n] = false;
        var right = dfs(n + 1, v);
        return Math.Min(left, right);
    }

    static int m1(bool[] v)
    {
        var g = 0;
        var ans = 0;

        for (int i = 0; i < D; i++)
        {
            if (v[i])
            {
                ans += p[i];
                g += (i + 1) * 100 * p[i];
                g += c[i];
            }
        }

        if (G <= g)
        {
            return ans;
        }

        var j = D - 1;
        for (; j >= 0 && v[j]; j--) { }

        var n = Math.Min(
            p[j],
            ceil(G - g, (j + 1) * 100));
        ans += n;
        g += (j + 1) * 100 * n;

        if (G <= g)
        {
            return ans;
        }
        else
        {
            return int.MaxValue;
        }
    }

    static int ceil(int a, int b)
    {
        return a / b + (a % b > 0 ? 1 : 0);
    }
}