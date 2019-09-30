using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using static System.Math;
using Debug = System.Diagnostics.Debug;
using LayoutKind = System.Runtime.InteropServices.LayoutKind;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;


static class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<Tuple<long, long>> d = Enumerable.Repeat(0, n).Select(_ => int.Parse(Console.ReadLine())).GroupBy(x => x).Select(x => new Tuple<long, long>(x.Key, x.Count())).OrderBy(x => x.Item1).ToList();
        SegmentTree<long> segTree = new SegmentTree<long>(n, 0, (x, y) => (x + y) % 1000000007);

        segTree.Operate(0, n, 1);
        for (int i = 1; i < 4; i++)
        {
            SegmentTree<long> newSegTree = new SegmentTree<long>(n, 0, (x, y) => (x + y) % 1000000007);
            for (int j = 0; j < d.Count; j++)
            {
                // int List<T>.BinarySeach(T) ?T??????????index????????T????????Index(????????List<T>.Count)??????
                var searchRes = ~d.BinarySearch(new Tuple<long, long>(d[j].Item1 * 2, -1));
                newSegTree.Operate(searchRes, n, segTree.Query(j) * d[j].Item2);
            }
            segTree = newSegTree;
        }
        Console.WriteLine(Enumerable.Range(0, d.Count).Aggregate(0L, (x, y) => (x + segTree.Query(y) * d[y].Item2) % 1000000007));
    }
}

class SegmentTree<T>
{
    public int Size { get; private set; }
    T IdentityElement;
    T[] Operators;
    Func<T, T, T> Merge;
    int LeafCount;

    public SegmentTree(int size, T identityElement, Func<T, T, T> merge) : this(Enumerable.Repeat(identityElement, size).ToArray(), identityElement, merge) { }

    public SegmentTree(T[] elems, T identityElement, Func<T, T, T> merge)
    {
        Size = elems.Length;
        Merge = merge;
        IdentityElement = identityElement;
        LeafCount = 1;
        while (LeafCount < elems.Length) LeafCount <<= 1;

        Operators = new T[LeafCount * 2];
        elems.CopyTo(Operators, LeafCount);
        for (int i = LeafCount - 1; i >= 1; i--) Operators[i] = Merge(Operators[i * 2], Operators[i * 2 + 1]);
    }

    public T this[int index]
    {
        get { return Query(index); }
        set { Operate(index, index + 1, value); }
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public void Operate(int l, int r, T x)
    {
        l += LeafCount;
        r += LeafCount - 1;
        while (l <= r)
        {
            if (l % 2 == 1) Operators[l] = Merge(x, Operators[l]);
            if (r % 2 == 0) Operators[r] = Merge(x, Operators[r]);
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public T Query(int i)
    {
        i += LeafCount;
        T res = Operators[i];
        while (0 < (i >>= 1)) res = Merge(res, Operators[i]);
        return res;
    }
}