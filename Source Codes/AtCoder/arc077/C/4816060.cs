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
        var nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = nm[0];
        int m = nm[1];

        //?????????????????????????????????????
        //y?????
        SegmentTree<Tuple<long, long>> segTree = new SegmentTree<Tuple<long, long>>
        (
            m,
            new Tuple<long, long>(0, 0),
            (x, y) => new Tuple<long, long>(x.Item1 + y.Item1, x.Item2 + y.Item2)
        );
        var a = Console.ReadLine().Split().Select(x => int.Parse(x) - 1).ToArray();

        long total = 0;
        int lastLevel = a[0];
        for (int i = 1; i < a.Length; i++)
        {
            var elem = a[i];
            //1?????????????????????
            if (elem < lastLevel)
            {
                //
                segTree.Operate(lastLevel + 1, m, new Tuple<long, long>(-1 - lastLevel, 1));
                lastLevel -= m;
            }
            segTree.Operate(Max(0, lastLevel + 1), elem + 1, new Tuple<long, long>(-1 - lastLevel, 1));
            total += elem - lastLevel;
            lastLevel = elem;
        }

        long res = long.MaxValue;
        for (int i = 0; i < segTree.Size; i++)
        {
            var queryRes = segTree[i];
            res = Min(res, total - (queryRes.Item1 + queryRes.Item2 * i));
        }
        Console.WriteLine(res);
    }
}

class SegmentTree<T>
{
    public int Size { get; private set; }
    T IdentityElement;
    Func<T, T, T> Merge;
    int LeafCount;
    int TreeHeight;
    T[] Datas;

    public SegmentTree(int size, T identityElement, Func<T, T, T> merge) : this(Enumerable.Repeat(identityElement, size).ToArray(), identityElement, merge) { }

    public SegmentTree(T[] elems, T identityElement, Func<T, T, T> merge)
    {
        Size = elems.Length;
        IdentityElement = identityElement;
        Merge = merge;
        LeafCount = 1;
        TreeHeight = 1;
        while (LeafCount < elems.Length)
        {
            LeafCount <<= 1;
            TreeHeight++;
        }

        Datas = Enumerable.Repeat(identityElement, LeafCount).Concat(elems).Concat(Enumerable.Repeat(identityElement, LeafCount - Size)).ToArray();
    }

    public T this[int index]
    {
        get { return Query(index); }
        set { Operate(index, index + 1, value); }
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public void Operate(int l, int r, T x)
    {
        l = l + LeafCount;
        r = r + LeafCount - 1;

        if (l < LeafCount || LeafCount * 2 <= l) return; 
        if (r < LeafCount || LeafCount * 2 <= r) return; 
        Propagate(l);
        Propagate(r);
        while (l <= r)
        {
            if (l % 2 == 1) Datas[l] = Merge(Datas[l], x);
            if (r % 2 == 0) Datas[r] = Merge(Datas[r], x);
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public T Query(int index)
    {
        index += LeafCount;
        Propagate(index);
        return Datas[index];
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    private void Propagate(int sectionIndex)
    {
        for (int i = TreeHeight - 1; i >= 1; i--) Eval(sectionIndex >> i);
    }

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    private void Eval(int sectionIndex)
    {
        Datas[sectionIndex * 2] = Merge(Datas[sectionIndex * 2], Datas[sectionIndex]);
        Datas[sectionIndex * 2 + 1] = Merge(Datas[sectionIndex * 2 + 1], Datas[sectionIndex]);
        Datas[sectionIndex] = IdentityElement;
    }
}