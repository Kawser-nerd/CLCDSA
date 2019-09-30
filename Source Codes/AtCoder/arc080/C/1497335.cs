using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public sealed class BinaryHeap<TValue>
    : IReadOnlyCollection<TValue>
{
    readonly List<TValue> list;
    readonly Func<TValue, TValue, int> compare;

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

    public BinaryHeap(List<TValue> list, Func<TValue, TValue, int> compare)
    {
        this.list = list;
        this.compare = compare;
    }
}

public static class BinaryHeap
{
    public static BinaryHeap<X> Create<X>(Func<X, X, int> compare)
    {
        return new BinaryHeap<X>(new List<X>(), compare);
    }

    public static BinaryHeap<X> Create<X>()
    {
        return new BinaryHeap<X>(new List<X>(), Comparer<X>.Default.Compare);
    }

    public static BinaryHeap<X> FromEnumerable<X>(IEnumerable<X> xs, Func<X, X, int> compare)
    {
        var list = new List<X>(xs);
        list.Sort(new Comparison<X>(compare));
        return new BinaryHeap<X>(list, compare);
    }

    public static BinaryHeap<X> FromEnumerable<X>(IEnumerable<X> xs)
    {
        return FromEnumerable(xs, Comparer<X>.Default.Compare);
    }
}


[System.Diagnostics.DebuggerDisplay("Count = {Count}")]
public sealed class SegmentTree<T>
    : IReadOnlyList<T>
    , IList<T>
{
    readonly T empty;
    readonly Func<T, T, T> append;

    readonly T[] nodes;
    readonly int height;
    readonly int itemCount;

    public int Count
    {
        get { return itemCount; }
    }

    static int NodeIndexFromItemIndex(int k, int height)
    {
        return (1 << height) - 1 + k;
    }

    int NodeIndexFromItemIndex(int k)
    {
        return NodeIndexFromItemIndex(k, height);
    }

    void SetItem(int index, T item)
    {
        var i = NodeIndexFromItemIndex(index);

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
            return nodes[NodeIndexFromItemIndex(index)];
        }
        set
        {
            if (index < 0 || index >= Count) throw new ArgumentOutOfRangeException("index");
            SetItem(index, value);
        }
    }

    /// <summary>
    /// Recalculates caches.
    /// </summary>
    public void Rebuild(IReadOnlyList<T> list)
    {
        if (list.Count != itemCount) throw new ArgumentException();

        var cacheCount = (1 << height) - 1;

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
        if (index < 0 || index > itemCount) throw new ArgumentOutOfRangeException("index");
        if (count < 0 || index + count > itemCount) throw new ArgumentOutOfRangeException("count");
        if (count == 0) return empty;
        return QueryCore(0, 0, 1 << height, index, index + count);
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

    public SegmentTree(T[] nodes, int height, int itemCount, T empty, Func<T, T, T> append)
    {
        this.nodes = nodes;
        this.height = height;
        this.itemCount = itemCount;
        this.empty = empty;
        this.append = append;
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

    public static SegmentTree<X> Create<X>(IEnumerable<X> items, X empty, Func<X, X, X> append)
    {
        var buffer = items as IReadOnlyList<X> ?? items.ToList();
        var itemCount = buffer.Count;
        if (itemCount == 0)
        {
            throw new NotSupportedException("Empty segment tree is not supported.");
        }

        var height = CalculateHeight(itemCount);
        var nodes = new X[(1 << height) * 2 - 1];

        var tree = new SegmentTree<X>(nodes, height, itemCount, empty, append);
        tree.Rebuild(buffer);

        return tree;
    }

    public struct Option<T>
    {
        public readonly T Value;
        public readonly bool HasValue;

        public static Option<T> None
        {
            get { return new Option<T>(); }
        }

        public Option(T value)
        {
            Value = value;
            HasValue = true;
        }
    }

    public static SegmentTree<Option<X>> FromSemigroup<X>(IEnumerable<X> items, Func<X, X, X> append)
    {
        return
            Create(
                items.Select(x => new Option<X>(x)),
                Option<X>.None,
                (xo, yo) =>
                    xo.HasValue && yo.HasValue
                        ? new Option<X>(append(xo.Value, yo.Value))
                        : Option<X>.None
            );
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

public class Program
{
    #region Standard I/O
    readonly TextReader input;
    readonly TextWriter output;

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

    List<int> qs;
    Cell[] allCells;
    SegmentTree<Cell>[] trees;
    BinaryHeap<Range> heap;

    void AddRange(int index, int endIndex)
    {
        var count = endIndex - index;
        if (count <= 0) return;

        var ec = trees[index % 2].Query(index, count);
        if (ec.Value == int.MaxValue) return;

        heap.Enqueue(new Range(ec, index, count));
    }

    public void Run()
    {
        {
            n = ReadLine(int.Parse)[0];
            ps = ReadLine(int.Parse);
        }

        qs = new List<int>(n);

        allCells = ps.Select((p, i) => new Cell(p, i)).ToArray();

        trees =
            Enumerable.Range(0, 2).Select(parity =>
                SegmentTree.Create(
                    allCells.Select((c, i) => i % 2 == parity ? c : Cell.Max),
                    Cell.Max,
                    (l, r) => Comparer<Cell>.Default.Compare(l, r) > 0 ? r : l
                ))
            .ToArray();

        heap =
            BinaryHeap.Create<Range>(
                (l, r) => Comparer<int>.Default.Compare(l.EvenCell.Value, r.EvenCell.Value)
            );

        AddRange(0, allCells.Length);

        while (heap.Count > 0 && qs.Count < n)
        {
            var range = heap.Dequeue();

            var ec = range.EvenCell;
            var oc = trees[1 - range.Parity].Query(ec.Index, range.EndIndex - ec.Index);

            qs.Add(ec.Value);
            qs.Add(oc.Value);
            trees[ec.Index % 2][ec.Index] = Cell.Max;
            trees[oc.Index % 2][oc.Index] = Cell.Max;

            AddRange(range.Index, ec.Index);
            AddRange(ec.Index + 1, oc.Index);
            AddRange(oc.Index + 1, range.EndIndex);
        }

        WriteLineOne(string.Join(" ", qs));
    }

    public Program(TextReader input, TextWriter output)
    {
        this.input = input;
        this.output = output;
    }

    public static void Main(string[] args)
    {
        new Program(Console.In, Console.Out).Run();
    }
}