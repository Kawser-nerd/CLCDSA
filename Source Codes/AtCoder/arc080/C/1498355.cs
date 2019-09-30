using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public sealed class BinaryHeap<TValue, TComparer>
    : IReadOnlyCollection<TValue>
    where TComparer : struct, IComparer<TValue>
{
    readonly List<TValue> list;
    readonly TComparer comparer;

    int compare(TValue l, TValue r)
    {
        return comparer.Compare(l, r);
    }

    public int Count
    {
        get { return list.Count; }
    }

    public IEnumerator<TValue> GetEnumerator()
    {
        return list.GetEnumerator();
    }

    System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }

    public TValue Peek()
    {
        return list[0];
    }

    public void Enqueue(TValue value)
    {
        list.Add(value);
        var i = list.Count - 1;
        while (i > 0)
        {
            // Index of the parent.
            var p = (i - 1) >> 1;

            if (compare(list[p], value) <= 0) break;
            list[i] = list[p];
            i = p;
        }
        list[i] = value;
    }

    public TValue Dequeue()
    {
        var min = list[0];
        var x = list[list.Count - 1];
        var i = 0;
        while (true)
        {
            // Index of children.
            var l = (i << 1) + 1;
            var r = (i << 1) + 2;
            if (l >= list.Count) break;

            // Index of the smaller child.
            var c = r < list.Count && compare(list[r], list[l]) < 0 ? r : l;

            if (compare(list[c], x) >= 0) break;
            list[i] = list[c];
            i = c;
        }
        list[i] = x;
        list.RemoveAt(list.Count - 1);
        return min;
    }

    public BinaryHeap(List<TValue> list, TComparer comparer)
    {
        this.list = list;
        this.comparer = comparer;
    }
}


public interface IMonoid<T>
{
    T Empty { get; }
    T Append(T left, T right);
}

[System.Diagnostics.DebuggerDisplay("Count = {Count}")]
public sealed class SegmentTree<T, TMonoid>
    : IReadOnlyList<T>
    , IList<T>
    where TMonoid : struct, IMonoid<T>
{
    readonly T[] nodes;
    readonly int cacheCount;
    readonly int itemCount;
    readonly TMonoid monoid;

    T empty => monoid.Empty;
    T append(T l, T r) => monoid.Append(l, r);

    public int Count
    {
        get { return itemCount; }
    }

    void SetItem(int index, T item)
    {
        var i = cacheCount + index;

        nodes[i] = item;

        while (i != 0)
        {
            var p = (i - 1) >> 1;
            nodes[p] = append(nodes[(p << 1) + 1], nodes[(p << 1) + 2]);
            i = p;
        }
    }

    public T this[int index]
    {
        get
        {
            return nodes[cacheCount + index];
        }
        set
        {
            Debug.Assert(0 <= index && index < Count);
            SetItem(index, value);
        }
    }

    /// <summary>
    /// Recalculates caches.
    /// </summary>
    public void Rebuild(T[] list, int parity)
    {
        Debug.Assert(list.Length == itemCount);

        for (var i = parity; i < list.Length; i += 2)
        {
            nodes[cacheCount + i] = list[i];
        }

        for (var i = 1 - parity; i < list.Length; i += 2)
        {
            nodes[cacheCount + i] = empty;
        }

        for (var i = cacheCount + itemCount; i < nodes.Length; i++)
        {
            nodes[i] = empty;
        }

        for (var i = cacheCount - 1; i >= 0; i--)
        {
            var l = (i << 1) + 1;
            var r = (i << 1) + 2;
            nodes[i] = append(nodes[l], nodes[r]);
        }
    }

    T QueryCore(int i, int nl, int nr, int ql, int qr)
    {
        if (qr <= nl || nr <= ql)
        {
            return empty;
        }
        else if (ql <= nl && nr <= qr)
        {
            return nodes[i];
        }
        else
        {
            var m = (nl + nr) >> 1;
            var l = QueryCore((i << 1) + 1, nl, m, ql, qr);
            var r = QueryCore((i << 1) + 2, m, nr, ql, qr);
            return append(l, r);
        }
    }

    public T Query(int index, int count)
    {
        Debug.Assert(0 <= index && index <= itemCount);
        Debug.Assert(0 <= count && index + count <= itemCount);

        if (count == 0) return empty;
        return QueryCore(0, 0, nodes.Length - cacheCount, index, index + count);
    }

    public T Query()
    {
        return nodes[0];
    }

    #region IReadOnlyList<_>, IList<_>
    IEnumerator<T> GetEnumerator()
    {
        for (var i = 0; i < Count; i++)
        {
            yield return this[i];
        }
    }

    void CopyTo(T[] array, int index)
    {
        for (var i = 0; i < Count; i++)
        {
            array[index + i] = this[i];
        }
    }

    int IndexOf(T item)
    {
        for (var i = 0; i < Count; i++)
        {
            if (EqualityComparer<T>.Default.Equals(this[i], item))
            {
                return i;
            }
        }
        return -1;
    }

    bool Contains(T item)
    {
        return IndexOf(item) >= 0;
    }

    IEnumerator<T> IEnumerable<T>.GetEnumerator()
    {
        return GetEnumerator();
    }

    System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
    {
        return ((IEnumerable<T>)this).GetEnumerator();
    }

    int IReadOnlyCollection<T>.Count
    {
        get
        {
            return Count;
        }
    }

    T IReadOnlyList<T>.this[int index]
    {
        get
        {
            return this[index];
        }
    }

    bool ICollection<T>.IsReadOnly
    {
        get
        {
            return false;
        }
    }

    int ICollection<T>.Count
    {
        get
        {
            return Count;
        }
    }

    bool ICollection<T>.Contains(T item)
    {
        return Contains(item);
    }

    void ICollection<T>.CopyTo(T[] array, int arrayIndex)
    {
        CopyTo(array, arrayIndex);
    }

    void ICollection<T>.Add(T item)
    {
        throw new NotSupportedException();
    }

    bool ICollection<T>.Remove(T item)
    {
        throw new NotSupportedException();
    }

    void ICollection<T>.Clear()
    {
        throw new NotSupportedException();
    }

    T IList<T>.this[int index]
    {
        get
        {
            return this[index];
        }
        set
        {
            this[index] = value;
        }
    }

    void IList<T>.Insert(int index, T item)
    {
        throw new NotSupportedException();
    }

    void IList<T>.RemoveAt(int index)
    {
        throw new NotSupportedException();
    }

    int IList<T>.IndexOf(T item)
    {
        return IndexOf(item);
    }
    #endregion

    public SegmentTree(T[] nodes, int cacheCount, int itemCount, TMonoid monoid)
    {
        this.nodes = nodes;
        this.cacheCount = cacheCount;
        this.itemCount = itemCount;
        this.monoid = monoid;
    }
}

public static class SegmentTree
{
    static int CalculateHeight(int count)
    {
        var h = 0;
        while ((1 << h) < count) h++;
        return h;
    }

    public static SegmentTree<X, MX> Create<X, MX>(X[] items, int parity, MX monoid)
        where MX : struct, IMonoid<X>
    {
        var itemCount = items.Length;
        if (itemCount == 0)
        {
            throw new NotSupportedException("Empty segment tree is not supported.");
        }

        var height = CalculateHeight(itemCount);
        var nodes = new X[((1 << height) << 1) - 1];
        var cacheCount = (1 << height) - 1;

        var tree = new SegmentTree<X, MX>(nodes, cacheCount, itemCount, monoid);
        tree.Rebuild(items, parity);

        return tree;
    }
}


public struct Int32MinMonoid
    : IMonoid<int>
{
    public int Empty => int.MaxValue;

    public int Append(int l, int r)
    {
        return Math.Min(l, r);
    }
}

public struct Range
{
    public int Index { get; }
    public int Count { get; }

    public int Parity => Index & 1;

    public int EndIndex => Index + Count;

    public Range(int index, int count)
    {
        Index = index;
        Count = count;
    }
}

public struct Int32Comparer
    : IComparer<int>
{
    public int Compare(int x, int y)
    {
        return x == y ? 0 : x > y ? 1 : -1;
    }
}

public class Program
{
    #region Standard I/O
    readonly TextReader input;
    readonly TextWriter output;

    int[] ReadLineInt32(int n)
    {
        var line = input.ReadLine();
        var xs = new int[n];
        var acc = 0;
        var j = 0;

        for (var i = 0; i < line.Length; i++)
        {
            if (line[i] == ' ')
            {
                xs[j] = acc;
                j++;
                acc = 0;
            }
            else
            {
                acc = acc * 10 + (line[i] - '0');
            }
        }

        xs[j] = acc;
        j++;

        Debug.Assert(j == n);
        return xs;
    }

    X[] ReadLine<X>(Func<string, X> func)
    {
        return input.ReadLine().Split(' ').Select(func).ToArray();
    }

    void WriteLineOne(object obj)
    {
        output.WriteLine("{0}", obj);
    }

    void WriteLineMany(params object[] objects)
    {
        output.WriteLine(string.Join(" ", objects.Select(obj => obj.ToString())));
    }
    #endregion

    int n;

    int[] ps;

    // ????????? p ????????????
    int[] indexFromValue;

    // ???? x ????????????? y ?????????????
    // Range ? class ??????????????????????????????????
    // ???????????????????????
    Range[] rangeFromValue;

    SegmentTree<int, Int32MinMonoid>[] trees;
    BinaryHeap<int, Int32Comparer> heap;

    void AddRange(int index, int endIndex)
    {
        var count = endIndex - index;
        if (count <= 0) return;

        var ec = default(int);

#if MEASURE
        using (mt2.Measure())
#endif
        {
            ec = trees[index & 1].Query(index, count);
        }
        if (ec == int.MaxValue) return;

#if MEASURE
        using (mh.Measure())
#endif
        {
            rangeFromValue[ec] = new Range(index, count);
            heap.Enqueue(ec);
        }
    }

#if MEASURE
    sealed class Measurement
    {
        long total = 0;

        public long Total => total;

        public struct MeasureScope
            : IDisposable
        {
            readonly Measurement parent;
            readonly long timestamp;

            public void Dispose()
            {
                var endTimestamp = Stopwatch.GetTimestamp();
                parent.total += endTimestamp - timestamp;
            }

            public MeasureScope(Measurement parent, long timestamp)
            {
                this.parent = parent;
                this.timestamp = timestamp;
            }
        }

        public MeasureScope Measure()
        {
            return new MeasureScope(this, Stopwatch.GetTimestamp());
        }
    }

    Measurement mr = new Measurement();
    Measurement mt = new Measurement();
    Measurement mt1 = new Measurement();
    Measurement mt2 = new Measurement();
    Measurement mt3 = new Measurement();
    Measurement mh = new Measurement();
    Measurement mo = new Measurement();
#endif

    static Y[] SelectToArray<X, Y>(X[] source, Func<X, int, Y> func)
    {
        var ys = new Y[source.Length];
        for (var i = 0; i < source.Length; i++)
        {
            ys[i] = func(source[i], i);
        }
        return ys;
    }

    public void Run()
    {
#if MEASURE
        using (mr.Measure())
#endif
        {
            n = int.Parse(input.ReadLine());
            ps = ReadLineInt32(n);
        }

#if MEASURE
        using (mo.Measure())
#endif
        {
            indexFromValue = new int[ps.Length + 1];
            for (var i = 0; i < ps.Length; i++)
            {
                indexFromValue[ps[i]] = i;
            }

            rangeFromValue = new Range[ps.Length + 1];
        }

#if MEASURE
        using (mt1.Measure())
#endif
        {
            trees = new SegmentTree<int, Int32MinMonoid>[2];
            for (var parity = 0; parity < 2; parity++)
            {
                trees[parity] = SegmentTree.Create(ps, parity, new Int32MinMonoid());
            }
        }

#if MEASURE
        using (mh.Measure())
#endif
        {
            heap = new BinaryHeap<int, Int32Comparer>(new List<int>(n/2), new Int32Comparer());
        }

        AddRange(0, ps.Length);

        var outputCount = 0;
        while (heap.Count > 0)
        {
            var ec = default(int);

#if MEASURE
            using (mh.Measure())
#endif
            {
                ec = heap.Dequeue();
            }

            var ei = indexFromValue[ec];
            var range = rangeFromValue[ec];

            var oc = default(int);

#if MEASURE
            using (mt2.Measure())
#endif
            {
                oc = trees[1 - range.Parity].Query(ei, range.EndIndex - ei);
            }

            var oi = indexFromValue[oc];

#if MEASURE
            using (mr.Measure())
#endif
            {
                if (outputCount != 0)
                {
                    output.Write(' ');
                }

                output.Write(ec);
                output.Write(' ');
                output.Write(oc);

                outputCount += 2;
                if (outputCount >= n)
                {
                    output.WriteLine();
                    break;
                }
            }

#if MEASURE
            using (mt3.Measure())
#endif
            {
                trees[ei & 1][ei] = int.MaxValue;
                trees[oi & 1][oi] = int.MaxValue;
            }

            AddRange(range.Index, ei);
            AddRange(ei + 1, oi);
            AddRange(oi + 1, range.EndIndex);
        }

#if MEASURE
        var measures =
            new Dictionary<string, Measurement>()
            {
                { "Misc", mo },
                { "I/O", mr },
                { "Heap", mh },
                { "Tree Init", mt1 },
                { "Tree Query", mt2 },
                { "Tree Set", mt3 },
            };

        var total = measures.Sum(m => m.Value.Total);
        var log = Console.Error;
        log.WriteLine($"Total = {total}");
        foreach (var m in measures.OrderBy(m => m.Value.Total))
        {
            log.WriteLine($"{m.Key}: {(double)m.Value.Total / total * 100}%");
        }
#endif
    }

    public Program(TextReader input, TextWriter output)
    {
        this.input = input;
        this.output = output;
    }

    public static void Main(string[] args)
    {
        using (var output = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
        {
            new Program(Console.In, output).Run();
        }
    }
}