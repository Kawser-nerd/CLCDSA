using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using LayoutKind = System.Runtime.InteropServices.LayoutKind;
using StructLayoutAttribute = System.Runtime.InteropServices.StructLayoutAttribute;
using FieldOffsetAttribute = System.Runtime.InteropServices.FieldOffsetAttribute;

class P
{
    static void Main()
    {
        var abq = Console.ReadLine().Split().Select(int.Parse).ToList();
        List<long> s = Enumerable.Repeat(long.MinValue / 8, 1).Concat(Enumerable.Repeat(0, abq[0]).Select(_ => long.Parse(Console.ReadLine()))).Concat(Enumerable.Repeat(long.MaxValue / 8, 1)).ToList();
        List<long> t = Enumerable.Repeat(long.MinValue / 8, 1).Concat(Enumerable.Repeat(0, abq[1]).Select(_ => long.Parse(Console.ReadLine()))).Concat(Enumerable.Repeat(long.MaxValue / 8, 1)).ToList();
        for (int i = 0; i < abq[2]; i++)
        {
            long query = long.Parse(Console.ReadLine());
            int sres = s.BinarySearch(query);
            if (sres < 0) sres = ~sres;
            int tres = t.BinarySearch(query);
            if (tres < 0) tres = ~tres;
            Console.WriteLine(Min(Min(GetDist(query, s[sres - 1], t[tres - 1]), GetDist(query, s[sres], t[tres - 1])), Min(GetDist(query, s[sres - 1], t[tres]), GetDist(query, s[sres], t[tres]))));

        }
    }
    static long GetDist(long q, long s, long t) => Min(Abs(q - s) + Abs(s - t), Abs(q - t) + Abs(t - s));
}


class PartialPersistentUnionFind
{
    public int Now { get; private set; }
    public int Size { get; private set; }
    int[] Parents;
    int[] Time;
    int[] Sizes;
    List<Tuple<int, int>>[] SizeHistories;

    public PartialPersistentUnionFind(int size)
    {
        Size = size;
        Parents = Enumerable.Range(0, Size).ToArray();
        Time = Enumerable.Repeat(int.MaxValue, Size).ToArray();
        Sizes = Enumerable.Repeat(1, Size).ToArray();
        SizeHistories = Enumerable.Repeat(0, Size).Select(_ => new List<Tuple<int, int>>() { new Tuple<int, int>(0, 1) }).ToArray();
    }

    public bool TryUnite(int x, int y)
    {
        Now++;
        x = Find(x);
        y = Find(y);
        if (x == y) return false;
        if (Sizes[x] < Sizes[y])
        {
            var tmp = x;
            x = y;
            y = tmp;
        }
        Parents[y] = x;
        Time[y] = Now;
        Sizes[x] += Sizes[y];
        SizeHistories[x].Add(new Tuple<int, int>(Now, Sizes[x]));
        return true;
    }
    public int Find(int i, int t = int.MaxValue - 1) => Time[i] <= t ? Find(Parents[i], t) : i;
    public int GetSize(int i, int t = int.MaxValue - 1)
    {
        var root = Find(i, t);
        return SizeHistories[root][~SizeHistories[root].BinarySearch(new Tuple<int, int>(t, int.MaxValue)) - 1].Item2;
    }
}