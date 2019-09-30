using System;

class Program
{
    static int n;
    static int m;
    static int[] a;
    static int[] b;

    static void Main(string[] args)
    {
        var nm = Console.ReadLine().Split();
        n = int.Parse(nm[0]);
        m = int.Parse(nm[1]);

        a = new int[m];
        b = new int[m];
        for (int i = 0; i < m; i++)
        {
            var ab = Console.ReadLine().Split();
            a[i] = int.Parse(ab[0]);
            b[i] = int.Parse(ab[1]);
        }

        var v = new bool[n];
        v[0] = true;
        var ans = m1(1, v);
        Console.WriteLine(ans);
    }

    static int m1(int x, bool[] v)
    {
        var all = true;
        for (int i = 0; i < n; i++) all &= v[i];
        if (all) return 1;

        var ans = 0;
        for (int i = 0; i < m; i++)
        {
            if (a[i] == x && !v[b[i] - 1])
            {
                v[b[i] - 1] = true;
                ans += m1(b[i], v);
                v[b[i] - 1] = false;
            }
            else if (b[i] == x && !v[a[i] - 1])
            {
                v[a[i] - 1] = true;
                ans += m1(a[i], v);
                v[a[i] - 1] = false;
            }
        }
        return ans;
    }
}