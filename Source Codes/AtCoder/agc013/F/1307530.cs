using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using Number = System.Int64;
//using System.Numerics;
using static System.Math;
//using static MathEx;
using P = System.Collections.Generic.KeyValuePair<int, int>;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var xs = new List<int>();
            var n = ri;
            var a = new int[n];
            var b = new int[n];
            var c = new int[n + 1];
            for (int i = 0; i < n; i++)
            {
                a[i] = ri;
                b[i] = ri;
                if (a[i] < b[i]) b[i] = a[i];
                xs.Add(a[i]); xs.Add(b[i]);
            }
            for (int i = 0; i < n + 1; i++)
            {
                c[i] = ri;
                xs.Add(c[i]);
            }
            Array.Sort(c);

            var q = ri;
            var u = new int[q];
            var v = new int[q];
            for (int i = 0; i < q; i++)
            {
                u[i] = ri;
                v[i] = ri;
                if (u[i] < v[i]) v[i] = u[i];
                xs.Add(u[i]);
                xs.Add(v[i]);
            }
            xs = xs.Distinct().ToList(); xs.Sort();
            for (int i = 0; i < n; i++)
            {
                a[i] = xs.BinarySearch(a[i]);
                b[i] = xs.BinarySearch(b[i]);
            }
            for (int i = 0; i < n + 1; i++)
                c[i] = xs.BinarySearch(c[i]);
            for (int i = 0; i < q; i++)
            {
                u[i] = xs.BinarySearch(u[i]);
                v[i] = xs.BinarySearch(v[i]);
            }
            Array.Sort(b, a);



            var max = 0;
            var k = xs.Count;
            var G = Enumerate(k + 1, x => new List<P>());
            var D = Enumerate(k + 1, x => 100000000);
            var deq = new Deque<int>();

            //greedy matching
            {
                var s = new Set<int>();
                s.IsMultiSet = true;
                for (int i = 0; i < n + 1; i++)
                    s.Add(c[i]);
                for (int i = 0; i < k - 1; i++)
                    G[i + 1].Add(new KeyValuePair<int, int>(i, 0));
                for (int i = n - 1; i >= 0; i--)
                {
                    var p = s.LowerBound(a[i]);
                    if (p < s.Count)
                    {
                        max++;
                        //Debug.WriteLine("+1 {0} {1}", xs[a[i]], xs[s[p]]);
                        G[b[i]].Add(new P(s[p], 1));
                        s.RemoveAt(p);
                    }
                    else
                    {
                        p = s.LowerBound(b[i]);
                        if (p == s.Count)
                        {
                            for (int j = 0; j < q; j++)
                                IO.Printer.Out.WriteLine(-1);
                            return;
                        }
                        //Debug.WriteLine("+-0 {0} {1}", xs[a[i]], xs[s[p]]);
                        s.RemoveAt(p);
                    }
                }
                //Debug.WriteLine(max);

                D[s[0]] = 0;
                deq.PushBack(s[0]);
            }
            //for (int i = 0; i <= k; i++) foreach (var e in G[i]) IO.Printer.Out.WriteLine("{0} {1} {2}", i, e.Key, e.Value);
            //augment
            {
                while (deq.Count > 0)
                {
                    var p = deq.PopFront();
                    Debug.WriteLine(p);
                    foreach (var e in G[p])
                    {
                        if (D[e.Key] > D[p] + e.Value)
                        {
                            D[e.Key] = D[p] + e.Value;
                            if (e.Value == 0) deq.PushFront(e.Key);
                            else deq.PushBack(e.Key);
                        }
                    }
                }
            }
            Debug.WriteLine(D.AsJoinedString());
            for (int i = 0; i < q; i++)
            {
                var x = max - D[v[i]];
                var y = max - D[u[i]] + 1;
                var z = Max(x, y);
                if (z < 0) IO.Printer.Out.WriteLine(-1);
                else IO.Printer.Out.WriteLine(z);
            }

        }
        //*
        int ri => sc.Integer();
        long rl => sc.Long();
        double rd => sc.Double();
        string rs => sc.Scan();
        char rc => sc.Char();

        [System.Diagnostics.Conditional("DEBUG")]
        void put(params object[] a) => Debug.WriteLine(string.Join(" ", a));
        //*/
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());
        static T[] Enumerate<T>(int n, Func<int, T> f) { var a = new T[n]; for (int i = 0; i < n; ++i) a[i] = f(i); return a; }
        static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
    }
}

#region main
static class Ex
{
    static public string AsString(this IEnumerable<char> ie) { return new string(System.Linq.Enumerable.ToArray(ie)); }
    static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") { return string.Join(st, ie); }
    static public void Main()
    {
        var solver = new Program.Solver();
        solver.Solve();
        Program.IO.Printer.Out.Flush();
    }
}
#endregion
#region Ex
namespace Program.IO
{
    using System.IO;
    using System.Text;
    using System.Globalization;
    public class Printer: StreamWriter
    {
        static Printer() { Out = new Printer(Console.OpenStandardOutput()) { AutoFlush = false }; }
        public static Printer Out { get; set; }
        public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
        public Printer(System.IO.Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
        public Printer(System.IO.Stream stream, Encoding encoding) : base(stream, encoding) { }
        public void Write<T>(string format, T[] source) { base.Write(format, source.OfType<object>().ToArray()); }
        public void WriteLine<T>(string format, T[] source) { base.WriteLine(format, source.OfType<object>().ToArray()); }
    }
    public class StreamScanner
    {
        public StreamScanner(Stream stream) { str = stream; }
        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof = false;
        public bool IsEndOfStream { get { return isEof; } }
        private byte read()
        {
            if (isEof) return 0;
            if (ptr >= len) { ptr = 0; if ((len = str.Read(buf, 0, 1024)) <= 0) { isEof = true; return 0; } }
            return buf[ptr++];
        }
        public char Char() { byte b = 0; do b = read(); while ((b < 33 || 126 < b) && !isEof); return (char)b; }

        public string Scan()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read())
                sb.Append(b);
            return sb.ToString();
        }
        public string ScanLine()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b != '\n'; b = (char)read())
                if (b == 0) break;
                else if (b != '\r') sb.Append(b);
            return sb.ToString();
        }
        public long Long()
        {
            if (isEof) return long.MinValue;
            long ret = 0; byte b = 0; var ng = false;
            do b = read();
            while (b != 0 && b != '-' && (b < '0' || '9' < b));
            if (b == 0) return long.MinValue;
            if (b == '-') { ng = true; b = read(); }
            for (; true; b = read())
            {
                if (b < '0' || '9' < b)
                    return ng ? -ret : ret;
                else ret = ret * 10 + b - '0';
            }
        }
        public int Integer() { return (isEof) ? int.MinValue : (int)Long(); }
        public double Double() { var s = Scan(); return s != "" ? double.Parse(s, CultureInfo.InvariantCulture) : double.NaN; }
        private T[] enumerate<T>(int n, Func<T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f();
            return a;
        }

        public char[] Char(int n) { return enumerate(n, Char); }
        public string[] Scan(int n) { return enumerate(n, Scan); }
        public double[] Double(int n) { return enumerate(n, Double); }
        public int[] Integer(int n) { return enumerate(n, Integer); }
        public long[] Long(int n) { return enumerate(n, Long); }
    }
}
#endregion

#region Set
public class Set<T>: ICollection<T>
{
    public Set() { cmp = Comparer<T>.Default; }
    public Set(IComparer<T> comparer) { cmp = comparer; }
    public Set(Comparison<T> compare) { cmp = Comparer<T>.Create(compare); }
    AVLTree<Node> tree = new AVLTree<Node>();
    IComparer<T> cmp;

    /// <summary>
    /// ??????????true????????false
    /// </summary>
    public bool IsMultiSet { get; set; }
    /// <summary>
    /// ??????????? O(1)
    /// </summary>
    public int Count { get { return tree.Count; } }

    /// <summary>
    /// ????????????true????????false?O(logN)
    /// </summary>
    public bool Add(T item)
    {
        var v = new Node() { Key = item };
        var lb = LowerBound(item);
        if (!IsMultiSet && UpperBound(item) != lb) return false;
        tree.Insert(v, lb);
        return true;
    }
    /// <summary>
    /// ????????????true????????false?O(logN)
    /// </summary>
    public bool Remove(T item)
    {
        var lb = LowerBound(item);
        var ub = UpperBound(item);
        if (ub == lb) return false;
        tree.RemoveAt(lb);
        return true;
    }
    /// <summary>
    /// 0-indexed ? k ??????????????????true????????false?O(logN)
    /// </summary>
    public bool RemoveAt(int k)
    {
        if (k < 0 || k >= Count) return false;
        tree.RemoveAt(k);
        return true;
    }
    /// <summary>
    /// 0-indexed ? k ????????????O(logN)
    /// </summary>
    public T this[int index]
    {
        get
        {
            if (index < 0 || index >= Count) throw new IndexOutOfRangeException();
            var t = tree.Find(tree.root, index);
            return t.Key;
        }
    }
    /// <summary>
    /// ??????? true????????false
    /// </summary>
    public bool Contains(T item) { return UpperBound(item) != LowerBound(item); }
    /// <summary>
    /// item?????????????????????O(logN)
    /// </summary>
    public int LowerBound(T item) { return tree.root.LowerBound(item, cmp); }
    /// <summary>
    /// item???????????????????????O(logN)
    /// </summary>
    public int UpperBound(T item) { return tree.root.UpperBound(item, cmp); }
    /// <summary>
    /// O(N)????
    /// </summary>
    public T[] Items
    {
        get
        {
            var ret = new T[Count];
            int ptr = 0;
            walk(tree.root, ret, ref ptr);
            return ret;
        }
    }

    public bool IsReadOnly { get { return false; } }

    void walk(Node root, T[] a, ref int ptr)
    {
        if (root.cnt == 0) return;
        walk(root.lst, a, ref ptr);
        a[ptr++] = root.Key;
        walk(root.rst, a, ref ptr);
    }

    void ICollection<T>.Add(T item) { Add(item); }
    public void Clear() { tree.root = tree.NIL; }
    public void CopyTo(T[] array, int arrayIndex) { ((ICollection<T>)Items).CopyTo(array, arrayIndex); }
    public IEnumerator<T> GetEnumerator() { return ((ICollection<T>)Items).GetEnumerator(); }

    System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator() { return ((ICollection<T>)Items).GetEnumerator(); }

    class Node: AVLTreeNode<Node>, IKey<T>
    {
        public T Key { get; set; }

        public override Node Push()
        {
            return this;
        }

    }
}

#endregion

#region AVLTree
public abstract class AVLTreeNode<T>: BinaryTreeNode<T>
    where T : AVLTreeNode<T>
{
    public int rank;
    public override void Update()
    {
        cnt = 1 + lst.cnt + rst.cnt;
        rank = 1 + Math.Max(lst.rank, rst.rank);
    }
}
public class AVLTree<T>: Tree<T>
    where T : AVLTreeNode<T>, new()
{
    public override void Insert(T v, int k) { root = insert(root, v, k); NIL.cnt = 0; }

    public override void RemoveAt(int k) { root = removeat(root, k); NIL.cnt = 0; }

    T insert(T t, T v, int k)
    {
        t = t.Push();
        if (t.cnt == 0)
        {
            v.lst = v.rst = NIL;
            v.Update();
            return v;
        }
        if (t.lst.cnt >= k)
            t.lst = insert(t.lst, v, k);
        else
            t.rst = insert(t.rst, v, k - t.lst.cnt - 1);
        if (t.lst.rank - t.rst.rank == -2)
        {
            if (t.rst.lst.rank > t.rst.rst.rank) t.rst = rotR(t.rst);
            t = rotL(t);
        }
        else if (t.lst.rank - t.rst.rank == 2)
        {
            if (t.lst.lst.rank < t.lst.rst.rank) t.lst = rotL(t.lst);
            t = rotR(t);
        }
        else t.Update();

        return t;
    }
    T removeat(T t, int k)
    {
        t = t.Push();
        var cnt = t.lst.cnt;
        if (cnt < k) t.rst = removeat(t.rst, k - cnt - 1);
        else if (cnt > k) t.lst = removeat(t.lst, k);
        else
        {
            if (cnt == 0) return t.rst;
            if (t.rst.cnt == 0) return t.lst;

            var next = Find(t.lst, k - 1);
            next.lst = removeat(t.lst, k - 1);
            next.rst = t.rst;
            t = next;
        }
        if (t.lst.rank - t.rst.rank == -2)
        {
            if (t.rst.lst.rank > t.rst.rst.rank) t.rst = rotR(t.rst);
            t = rotL(t);
        }
        else if (t.lst.rank - t.rst.rank == 2)
        {
            if (t.lst.lst.rank < t.lst.rst.rank) t.lst = rotL(t.lst);
            t = rotR(t);
        }
        else t.Update();
        return t;
    }
}
#endregion
#region BinaryTree
public interface IKey<K> { K Key { get; set; } }
public abstract class BinaryTreeNode<T>
    where T : BinaryTreeNode<T>
{

    public int cnt;
    public T lst, rst;
    public abstract T Push();
    /// <summary>
    /// ??????????? Update ???????
    /// </summary>
    public abstract void Update();
}

public abstract class Tree<TNode>
    where TNode : BinaryTreeNode<TNode>, new()
{
    public Tree() { NIL = new TNode(); NIL.lst = NIL; NIL.rst = NIL; root = NIL; }
    public readonly TNode NIL;
    public TNode root;
    public int Count { get { return root.cnt; } }
    protected TNode rotR(TNode t)
    {
        t = t.Push();
        var l = t.lst.Push();
        t.lst = l.rst;
        l.rst = t;
        t.Update();
        l.Update();
        return l;
    }
    protected TNode rotL(TNode t)
    {
        t = t.Push();
        var r = t.rst.Push();
        t.rst = r.lst;
        r.lst = t;
        r.lst = t;
        t.Update();
        r.Update();
        return r;
    }
    public TNode Find(TNode t, int k)
    {
        t = t.Push();
        if (k < t.lst.cnt) return Find(t.lst, k);
        else if (k > t.lst.cnt) return Find(t.rst, k - t.lst.cnt - 1);
        else return t;
    }
    public abstract void Insert(TNode v, int k);
    public abstract void RemoveAt(int k);
}
public static class TreeOperation
{
    static public int LowerBound<T, K>
          (this T t, K k, IComparer<K> cmp)
          where T : BinaryTreeNode<T>, IKey<K>
    {
        if (t.cnt == 0) return 0;
        if (cmp.Compare(k, t.Key) <= 0) return LowerBound(t.lst, k, cmp);
        else return 1 + t.lst.cnt + LowerBound(t.rst, k, cmp);
    }
    static public int UpperBound<T, K>
     (this T t, K k, IComparer<K> cmp)
       where T : BinaryTreeNode<T>, IKey<K>
    {
        if (t.cnt == 0) return 0;
        if (cmp.Compare(t.Key, k) <= 0) return 1 + t.lst.cnt + UpperBound(t.rst, k, cmp);
        else return UpperBound(t.lst, k, cmp);
    }
}

#endregion

#region Deque<T>

public class Deque<T>
{
    T[] buf;
    int offset;
    int count;
    int capacity;
    public int Count { get { return count; } }
    public Deque(int cap) { buf = new T[capacity = cap]; }
    public Deque() { buf = new T[capacity = 8]; }
    public T this[int index]
    {
        get { return buf[getIndex(index)]; }
        set { buf[getIndex(index)] = value; }
    }
    private int getIndex(int index)
    {
        if (index >= capacity)
            throw new IndexOutOfRangeException("out of range");
        var ret = index + offset;
        if (ret >= capacity)
            ret -= capacity;
        return ret;
    }
    public void PushFront(T item)
    {
        if (count == capacity) Extend();
        if (--offset < 0) offset += buf.Length;
        buf[offset] = item;
        ++count;
    }
    public T PopFront()
    {
        if (count == 0)
            throw new InvalidOperationException("collection is empty");
        --count;
        var ret = buf[offset++];
        if (offset >= capacity) offset -= capacity;
        return ret;
    }
    public void PushBack(T item)
    {
        if (count == capacity) Extend();
        var id = count++ + offset;
        if (id >= capacity) id -= capacity;
        buf[id] = item;
    }
    public T PopBack()
    {
        if (count == 0)
            throw new InvalidOperationException("collection is empty");
        return buf[getIndex(--count)];
    }
    public void Insert(T item, int index)
    {
        if (index > count) throw new IndexOutOfRangeException();
        this.PushFront(item);
        for (int i = 0; i < index; i++)
            this[i] = this[i + 1];
        this[index] = item;
    }
    public T RemoveAt(int index)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        var ret = this[index];
        for (int i = index; i > 0; i--)
            this[i] = this[i - 1];
        this.PopFront();
        return ret;
    }
    private void Extend()
    {
        T[] newBuffer = new T[capacity << 1];
        if (offset > capacity - count)
        {
            var len = buf.Length - offset;
            Array.Copy(buf, offset, newBuffer, 0, len);
            Array.Copy(buf, 0, newBuffer, len, count - len);
        }
        else Array.Copy(buf, offset, newBuffer, 0, count);
        buf = newBuffer;
        offset = 0;
        capacity <<= 1;
    }
    public T[] Items
    {
        get
        {
            var a = new T[count];
            for (int i = 0; i < count; i++)
                a[i] = this[i];
            return a;
        }
    }
}

#endregion