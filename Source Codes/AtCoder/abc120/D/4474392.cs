using System;

public class UnionFind
{
    private int[] data;
    public UnionFind(int size)
    {
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = -1;
    }
    public bool Unite(int x, int y)
    {
        x = Root(x);
        y = Root(y);
        if (x != y)
        {
            if (data[y] < data[x])
            {
                var tmp = y;
                y = x;
                x = tmp;
            }
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    public bool IsSameGroup(int x, int y) => Root(x) == Root(y);
    public int Root(int x) => data[x] < 0 ? x : data[x] = Root(data[x]);
    public int getMem(int x) => -data[Root(x)];
}


public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var a = new int[m];
        var b = new int[m];
        for (int i = 0; i < m; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            a[i] = int.Parse(line[0]) - 1;
            b[i] = int.Parse(line[1]) - 1;
        }
        Array.Reverse(a);
        Array.Reverse(b);
        putAns(a, b, n, m);
    }
    static void putAns(int[] a, int[] b, int n, int m)
    {
        var ans = new long[m + 1];
        var uf = new UnionFind(n + 10);
        ans[0] =(long) n * (n - 1) / 2L;
        for (int i = 0; i < m; i++)
        {
            if (uf.IsSameGroup(a[i], b[i])) ans[i + 1] = ans[i];
            else
            {
                long wa = uf.getMem(a[i]);
                long wb = uf.getMem(b[i]);
                ans[i + 1] = ans[i] - wa * wb;
                uf.Unite(a[i], b[i]);
            }
        }
        Array.Reverse(ans);
        for (int i = 1; i <= m; i++) Console.WriteLine(ans[i]);
    }
}