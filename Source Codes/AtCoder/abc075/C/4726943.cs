using System;

class Program
{
    static int[] a;
    static int[] b;
    static int n;
    static int m;

    static void Main(string[] args)
    {
        var nm = Console.ReadLine().Split(' ');
        n = int.Parse(nm[0]);
        m = int.Parse(nm[1]);

        a = new int[m];
        b = new int[m];
        for (int i = 0; i < m; i++)
        {
            var ab = Console.ReadLine().Split(' ');
            a[i] = int.Parse(ab[0]);
            b[i] = int.Parse(ab[1]);
        }

        var ans = 0;
        for (int i = 0; i < m; i++)
        {
            var v = new bool[n];
            m1(1, i, v);

            var all = true;
            for (int j = 0; j < n; j++) all &= v[j];
            if (!all) ans++;
        }

        Console.WriteLine(ans);
    }

    static void m1(int x, int i, bool[] v)
    {
        v[x - 1] = true;
        for (int j = 0; j < m; j++)
        {
            if (j != i)
            {
                if (a[j] == x && !v[b[j] - 1])
                {
                    m1(b[j], i, v);
                }
                else if (b[j] == x && !v[a[j] - 1])
                {
                    m1(a[j], i, v);
                }
            }
        }
    }
}