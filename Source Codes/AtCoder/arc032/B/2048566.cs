using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        UnionFind uf = new UnionFind(nm[0]);
        for (int i = 0; i < nm[1]; i++)
        {
            int[] ab = Console.ReadLine().Split().Select(int.Parse).ToArray();
            uf.Union(ab[0] - 1, ab[1] - 1);
        }
        Console.WriteLine(uf.AllParents().Count() - 1);
    }
}
class UnionFind
{
    int[] data;
    public UnionFind(int count)
    {
        data = Enumerable.Range(0, count).ToArray();
    }
    public void Union(int x, int y)
    {
        int xp = Parent(x);
        int yp = Parent(y);
        if (xp != yp)
        {
            data[yp] = xp;
        }
    }
    public bool IsSameGroup(int x, int y) => Parent(x) == Parent(y);
    public int[] AllParents() => data.Where((x, y) => x == y).ToArray();
    public int Parent(int x)
    {
        form(x);
        return data[x];
    }
    private void form(int x)
    {
        while (data[x] != data[data[x]])
        {
            data[x] = data[data[x]];
        }
    }
}