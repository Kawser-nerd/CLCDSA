using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Tuple<int[], int>[] vert = Enumerable.Range(0, n).Select(x => new Tuple<int[], int>(Console.ReadLine().Split().Select(int.Parse).ToArray(), x)).ToArray();

        Tuple<int[], int>[] sortbyx = vert.OrderBy(x => x.Item1[0]).ToArray();
        Tuple<int[], int>[] sortbyy = vert.OrderBy(x => x.Item1[1]).ToArray();

        List<Edge> edges = new List<Edge>();
        edges.AddRange(temp(sortbyx));
        edges.AddRange(temp(sortbyy));

        Edge[] edge = edges.OrderBy(x => x.Length).ToArray();
        UnionFind uf = new UnionFind(n);
        int cost = 0;
        for (int i = 0; i < edge.Length; i++)
        {
            if(!uf.IsSameGroup(edge[i].Start, edge[i].End))
            {
                uf.Union(edge[i].Start, edge[i].End);
                cost += edge[i].Length;
            }
        }
        Console.WriteLine(cost);
    }
    static List<Edge> temp(Tuple<int[], int>[] sortbyx)
    {
        List<Edge> edges = new List<Edge>();
        for (int i = 1; i < sortbyx.Length; i++)
        {
            edges.Add(new Edge(sortbyx[i - 1].Item2, sortbyx[i].Item2, Math.Min(Math.Abs(sortbyx[i - 1].Item1[0] - sortbyx[i].Item1[0]), Math.Abs(sortbyx[i - 1].Item1[1] - sortbyx[i].Item1[1]))));
        }
        return edges;
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
struct Edge
{
    public int Start;
    public int End;
    public int Length;
    public Edge(int s, int e, int l)
    {
        Start = s;
        End = e;
        Length = l;
    }
}