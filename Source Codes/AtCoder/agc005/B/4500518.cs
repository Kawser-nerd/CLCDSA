using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        SegmentTree<int> StartIndexes = new SegmentTree<int>(Enumerable.Repeat(-1, n).ToArray(), int.MinValue, (x, y) => y == int.MinValue ? x : y);
        SegmentTree<int> EndIndexes = new SegmentTree<int>(Enumerable.Repeat(n, n).ToArray(), int.MinValue, (x, y) => y == int.MinValue ? x : y);

        long res = 0;
        foreach (var item in Console.ReadLine().Split().Select((x, y) => new Tuple<int, int>(int.Parse(x), y)).OrderBy(x => x.Item1))
        {
            long num = item.Item1;
            int index = item.Item2;

            var lIndex = StartIndexes.Query(index);
            var rIndex = EndIndexes.Query(index);
            StartIndexes.Operate(index, rIndex, index);
            EndIndexes.Operate(lIndex + 1, index, index);
            Debug.WriteLine($"{lIndex} {index} {rIndex}");
            res += num * (lIndex - index) * (index - rIndex);
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

    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    public void Operate(int l, int r, T x)
    {
        l += LeafCount;
        r += LeafCount - 1;
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