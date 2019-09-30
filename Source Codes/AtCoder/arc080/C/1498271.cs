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
            var parentIndex = (i - 1) / 2;
            var childIndex = parentIndex * 2 + 1;
            nodes[parentIndex] = append(nodes[childIndex], nodes[childIndex + 1]);
            i = parentIndex;
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
    public void Rebuild(IReadOnlyList<T> list)
    {
        Debug.Assert(list.Count == itemCount);

        for (var k = 0; k < itemCount; k++)
        {
            nodes[cacheCount + k] = list[k];
        }

        for (var i = cacheCount + itemCount; i < nodes.Length; i++)
        {
            nodes[i] = empty;
        }

        for (var i = cacheCount - 1; i >= 0; i--)
        {
            var l = i * 2 + 1;
            var r = i * 2 + 2;
            nodes[i] = append(nodes[l], nodes[r]);
        }
    }

    T QueryCore(int i, int nl, int nr, int ql, int qr)
    {
        // The query range is in the node range.
        Debug.Assert(nl <= ql && ql < qr && qr <= nr);

        // Middle index of the node range.
        var m = nl + (nr - nl + 1) / 2;

        if (nl == ql && nr == qr)
        {
            return nodes[i];
        }
        else if (qr <= m)
        {
            // Forward to the left subtree because it contains the query range.
            return QueryCore(i * 2 + 1, nl, m, ql, qr);
        }
        else if (m <= ql)
        {
            // Forward to the right subtree.
            return QueryCore(i * 2 + 2, m, nr, ql, qr);
        }
        else
        {
            // Divide the query range at the middle index,
            // evaluate subqueries and merge results.
            Debug.Assert(ql < m && m < qr);

            var l = QueryCore(i * 2 + 1, nl, m, ql, m);
            var r = QueryCore(i * 2 + 2, m, nr, m, qr);
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

    public static SegmentTree<X, MX> Create<X, MX>(IEnumerable<X> items, MX monoid)
        where MX : struct, IMonoid<X>
    {
        var buffer = items as IReadOnlyList<X> ?? items.ToList();
        var itemCount = buffer.Count;
        if (itemCount == 0)
        {
            throw new NotSupportedException("Empty segment tree is not supported.");
        }

        var height = CalculateHeight(itemCount);
        var nodes = new X[(1 << height) * 2 - 1];
        var cacheCount = (1 << height) - 1;

        var tree = new SegmentTree<X, MX>(nodes, cacheCount, itemCount, monoid);
        tree.Rebuild(buffer);

        return tree;
    }
}

public sealed class Cell
    : Tuple<int, int>
{
    public int Value => Item1;
    public int Index => Item2;

    public Cell(int value, int index)
        : base(value, index)
    {
    }

    public static readonly Cell Max = new Cell(int.MaxValue, int.MaxValue);
}

public struct CellMonoid
    : IMonoid<Cell>
{
    public Cell Empty => Cell.Max;

    public Cell Append(Cell l, Cell r)
    {
        return l.Value > r.Value ? r : l;
    }
}

public sealed class Range
{
    /// <summary>
    /// ?????????????????????????????
    /// </summary>
    public Cell EvenCell { get; }

    public int Index { get; }
    public int Count { get; }

    public int Parity => Index % 2;

    public int EndIndex => Index + Count;

    public bool IsEmpty => Count == 0 || EvenCell.Value == int.MaxValue;

    public Range(Cell evenCell, int index, int count)
    {
        EvenCell = evenCell;
        Index = index;
        Count = count;
    }
}

public struct RangeComparer
    : IComparer<Range>
{
    public int Compare(Range x, Range y)
    {
        return Comparer<int>.Default.Compare(x.EvenCell.Value, y.EvenCell.Value);
    }
}

public class Program
{
    #region Standard I/O
    readonly TextReader input;
    readonly TextWriter output;

    int[] ReadLineInt32()
    {
        var words = input.ReadLine().Split(' ');
        var xs = new int[words.Length];
        for (var i = 0; i < words.Length; i++)
        {
            xs[i] = int.Parse(words[i]);
        }
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

    Cell[] allCells;
    SegmentTree<Cell, CellMonoid>[] trees;
    BinaryHeap<Range, RangeComparer> heap;

    void AddRange(int index, int endIndex)
    {
        var count = endIndex - index;
        if (count <= 0) return;

        var ec = default(Cell);

#if MEASURE
        using (mt2.Measure())
#endif
        {
            ec = trees[index % 2].Query(index, count);
        }
        if (ec.Value == int.MaxValue) return;

#if MEASURE
        using (mh.Measure())
#endif
        {
            heap.Enqueue(new Range(ec, index, count));
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
            n = ReadLineInt32()[0];
            ps = ReadLineInt32();
        }

        allCells = new Cell[ps.Length];
        for (var i = 0; i < ps.Length; i++)
        {
            allCells[i] = new Cell(ps[i], i);
        }

#if MEASURE
        using (mt1.Measure())
#endif
        {
            trees = new SegmentTree<Cell, CellMonoid>[2];
            for (var parity = 0; parity < 2; parity++)
            {
                var cells = new Cell[n];
                for (var i = 0; i < cells.Length; i++)
                {
                    cells[i] = i % 2 == parity ? allCells[i] : Cell.Max;
                }

                trees[parity] = SegmentTree.Create(cells, new CellMonoid());
            }
        }

#if MEASURE
        using (mh.Measure())
#endif
        {
            heap = new BinaryHeap<Range, RangeComparer>(new List<Range>(n), new RangeComparer());
        }
        
        AddRange(0, allCells.Length);

        var outputCount = 0;
        while (heap.Count > 0)
        {
            var range = default(Range);

#if MEASURE
            using (mh.Measure())
#endif
            {
                range = heap.Dequeue();
            }

            var ec = range.EvenCell;
            var oc = default(Cell);

#if MEASURE
            using (mt2.Measure())
#endif
            {
                oc = trees[1 - range.Parity].Query(ec.Index, range.EndIndex - ec.Index);
            }

#if MEASURE
            using (mr.Measure())
#endif
            {
                if (outputCount != 0)
                {
                    output.Write(' ');
                }

                output.Write(ec.Value);
                output.Write(' ');
                output.Write(oc.Value);

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
                trees[ec.Index % 2][ec.Index] = Cell.Max;
                trees[oc.Index % 2][oc.Index] = Cell.Max;
            }

            AddRange(range.Index, ec.Index);
            AddRange(ec.Index + 1, oc.Index);
            AddRange(oc.Index + 1, range.EndIndex);
        }

#if MEASUSRE
        var measures =
            new Dictionary<string, Measurement>()
            {
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