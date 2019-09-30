using System;

public class UnionFind
{
    private int[] data;
    public UnionFind(int size)
    {
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = -1;
    }
    public bool Union(int x, int y)
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
    public int getRoot(int x) => Root(x);
    private int Root(int x) => data[x] < 0 ? x : data[x] = Root(data[x]);
}

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var uf = new UnionFind(n + 10);
        for (int i = 0; i < m; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var a = int.Parse(line[0]);
            var b = int.Parse(line[1]);
            uf.Union(a, b);
        }
        var count = 0;
        for (int i = 1; i <= n; i++)
            if (uf.getRoot(i) == i) count++;
        Console.WriteLine(count - 1);
    }
}