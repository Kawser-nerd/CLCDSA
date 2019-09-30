using System;
using System.IO;
using System.Linq;
using System.Runtime;
using System.Reflection;
using System.Diagnostics;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Text;
using System.Text.RegularExpressions;
using static System.Math;


class P
{
    static void Main()
    {
        int[] nkl = Console.ReadLine().Split().Select(int.Parse).ToArray();
        UnionFind road = new UnionFind(nkl[0]);
        UnionFind train = new UnionFind(nkl[0]);
        for (int i = 0; i < nkl[1]; i++)
        {
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            road.Union(a[0] - 1, a[1] - 1);
        }
        for (int i = 0; i < nkl[2]; i++)
        {
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            train.Union(a[0] - 1, a[1] - 1);
        }
        Dictionary<long, int> dict = new Dictionary<long, int>();
        for (int i = 0; i < nkl[0]; i++)
        {
            long key = (long)road.Parent(i) * int.MaxValue + (long)train.Parent(i);
            if (!dict.ContainsKey(key)) dict.Add(key, 0);
            dict[key]++;
        }
        int[] ans = new int[nkl[0]];
        for (int i = 0; i < nkl[0]; i++)
        {
            long key = (long)road.Parent(i) * int.MaxValue + (long)train.Parent(i);
            ans[i] = dict[key];
        }
        Console.WriteLine(string.Join(" ", ans));
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