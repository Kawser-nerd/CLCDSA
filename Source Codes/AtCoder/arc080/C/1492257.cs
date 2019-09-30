using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using static System.Console;
using static System.Convert;
using static System.Math;
using static Extentions;

class IO
{
    int idx;
    string[] input = In.ReadToEnd().Split(new[] { " ", "\n", "\r" },
        StringSplitOptions.RemoveEmptyEntries);

    T Get<T>(Func<string, T> parser) => parser(input[idx++]);

    public string S => Get(s => s);
    public char C => Get(char.Parse);
    public int I => Get(int.Parse);
    public long L => Get(long.Parse);
    public double F => Get(double.Parse);
    public decimal D => Get(decimal.Parse);
    public BigInteger B => Get(BigInteger.Parse);

    T[] Gets<T>(int n, Func<string, T> parser)
        => input.Skip((idx += n) - n).Take(n).Select(parser).ToArray();

    public string[] Ss(int n) => Gets(n, s => s);
    public char[] Cs(int n) => Gets(n, char.Parse);
    public int[] Is(int n) => Gets(n, int.Parse);
    public long[] Ls(int n) => Gets(n, long.Parse);
    public double[] Fs(int n) => Gets(n, double.Parse);
    public decimal[] Ds(int n) => Gets(n, decimal.Parse);
    public BigInteger[] Bs(int n) => Gets(n, BigInteger.Parse);

    public void Write<T>(params T[] xs) => WriteLine(string.Join(" ", xs));
    public void Write(params object[] xs) => WriteLine(string.Join(" ", xs));
}

class SegmentTree<T>
{
    int n;
    T[] tree;
    T id;
    Func<T, T, T> ope;

    public SegmentTree(int n, T id, Func<T, T, T> ope) : this(id, ope)
    {
        this.n = 1;
        while (this.n < n) this.n *= 2;
        tree = Enumerable.Repeat(id, this.n * 2).ToArray();
    }

    public SegmentTree(T[] xs, T id, Func<T, T, T> ope) : this(id, ope)
    {
        n = 1;
        while (n < xs.Length) n *= 2;
        tree = new T[n * 2];
        for (var i = 0; i < n; i++)
            tree[i + n] = i < xs.Length ? xs[i] : id;
        for (var i = n - 1; i > 0; i--)
            tree[i] = ope(tree[i * 2], tree[i * 2 + 1]);
    }

    SegmentTree(T id, Func<T, T, T> ope)
    {
        this.id = id;
        this.ope = ope;
    }

    public T this[int i]
    {
        get { return tree[i + n]; }
        set
        {
            tree[i += n] = value;
            for (i >>= 1; i > 0; i >>= 1)
                tree[i] = ope(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    public T this[int i, int j]
    {
        get
        {
            var r = id;
            i += n;
            j += n + 1;
            for (; i < j; i >>= 1, j >>= 1)
            {
                if ((j & 1) != 0) r = ope(r, tree[--j]);
                if ((i & 1) != 0) r = ope(r, tree[i++]);
            }
            return r;
        }
    }
}

#region http://qiita.com/Camypaper/items/de6d576fe5513743a50e

class PriorityQueue<T>
{
    private readonly List<T> heap;
    private readonly Comparison<T> compare;
    private int size;
    public PriorityQueue() : this(Comparer<T>.Default) { }
    public PriorityQueue(IComparer<T> comparer) : this(16, comparer.Compare) { }
    public PriorityQueue(Comparison<T> comparison) : this(16, comparison) { }
    public PriorityQueue(int capacity, Comparison<T> comparison)
    {
        this.heap = new List<T>(capacity);
        this.compare = comparison;
    }
    public void Enqueue(T item)
    {
        this.heap.Add(item);
        var i = size++;
        while (i > 0)
        {
            var p = (i - 1) >> 1;
            if (compare(this.heap[p], item) <= 0)
                break;
            this.heap[i] = heap[p];
            i = p;
        }
        this.heap[i] = item;

    }
    public T Dequeue()
    {
        var ret = this.heap[0];
        var x = this.heap[--size];
        var i = 0;
        while ((i << 1) + 1 < size)
        {
            var a = (i << 1) + 1;
            var b = (i << 1) + 2;
            if (b < size && compare(heap[b], heap[a]) < 0) a = b;
            if (compare(heap[a], x) >= 0)
                break;
            heap[i] = heap[a];
            i = a;
        }
        heap[i] = x;
        heap.RemoveAt(size);
        return ret;
    }
    public T Peek() { return heap[0]; }
    public int Count { get { return size; } }
    public bool Any() { return size > 0; }
}

#endregion

static class Extentions
{
}

struct Data
{
    public int X, Y, Min;
    public bool Even;

    public Data(int x, int y, int min, bool even)
    {
        X = x; Y = y; Min = min; Even = even;
    }
}

static class Program
{
    public static void Main()
    {
        var sw = new StreamWriter(OpenStandardOutput()) { NewLine = "\n" };
#if DEBUG
        sw.AutoFlush = true;
#else
        sw.AutoFlush = false;
#endif
        SetOut(sw);
        Solve(new IO());
        Out.Flush();
    }

    static int[] pidxes;
    static SegmentTree<int> evenst, oddst;
    static PriorityQueue<Data> pq
        = new PriorityQueue<Data>((x, y) => x.Min.CompareTo(y.Min));

    static void Solve(IO io)
    {
        var n = io.I;
        var p = io.Is(n);

        pidxes = new int[n + 1];
        for (var i = 0; i < n; i++) pidxes[p[i]] = i;

        var evenp = p.Select((x, i) => i % 2 == 0 ? x : int.MaxValue).ToArray();
        var oddp = p.Select((x, i) => i % 2 != 0 ? x : int.MaxValue).ToArray();

        evenst = new SegmentTree<int>(evenp, int.MaxValue, Min);
        oddst = new SegmentTree<int>(oddp, int.MaxValue, Min);

        var xmin = int.MaxValue;
        var xmini = 0;
        var ymin = int.MaxValue;
        var ymini = n - 1;

        pq.Enqueue(new Data(xmini, ymini, evenst[xmini, ymini], true));

        while (pq.Any())
        {
            var xy = pq.Dequeue();

            xmin = xy.Even ? evenst[xy.X, xy.Y] : oddst[xy.X, xy.Y];
            xmini = pidxes[xmin];
            ymin = xy.Even ? oddst[xmini + 1, xy.Y] : evenst[xmini + 1, xy.Y];
            ymini = pidxes[ymin];

            if (xmini > xy.X)
            {
                var tl = xy.X;
                var tr = xmini - 1;
                var min = xy.Even ? evenst[tl, tr] : oddst[tl, tr];

                pq.Enqueue(new Data(tl, tr, min, xy.Even));
            }

            if (ymini - xmini > 1)
            {
                var tl = xmini + 1;
                var tr = ymini - 1;
                var min = xy.Even ? oddst[tl, tr] : evenst[tl, tr];

                pq.Enqueue(new Data(tl, tr, min, !xy.Even));
            }

            if (ymini < xy.Y)
            {
                var tl = ymini + 1;
                var tr = xy.Y;
                var min = xy.Even ? evenst[tl, tr] : oddst[tl, tr];

                pq.Enqueue(new Data(tl, tr, min, xy.Even));
            }

            Write(xmin + " " + ymin + " ");
        }
    }
}