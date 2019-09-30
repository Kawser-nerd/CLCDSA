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

        SegmentTree<int> segTree = new SegmentTree<int>(m + 1, 0, (x, y) => x + y);
        int sectionIndex = 0;
        int[][] sections = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).OrderBy(x => x[1] - x[0]).ToArray();
        int[] resArr = new int[m];
        for (int i = 1; i <= m; i++)
        {
            var res = 0;
            //???i????????????(??????????????)
            while (sectionIndex < sections.Length && sections[sectionIndex][1] - sections[sectionIndex][0] + 1 < i)
            {
                segTree.Operate(sections[sectionIndex][0], sections[sectionIndex][1] + 1, 1);
                sectionIndex++;
            }

            //??????????(????i?????????????sectionIndex?????????)
            res += nm[0] - sectionIndex;

            for (int j = 0; j <= m; j += i)
            {
                var query = segTree.Query(j);
                res += query;
            }

            resArr[i - 1] = res;
        }
        Console.WriteLine(string.Join("\n", resArr));
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