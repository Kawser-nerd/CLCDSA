using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
using P = System.Numerics.Complex;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var q = ri;
            var s = new Set<int>();
            for (int i = 0; i < q; i++)
            {
                if (ri == 1) s.Add(ri);
                else
                {
                    var k = ri - 1;
                    Console.WriteLine(s[k]);
                    s.RemoveAt(k);
                }
            }

        }
        const long INF = 1L << 60;
        int ri { get { return sc.Integer(); } }
        long rl { get { return sc.Long(); } }
        double rd { get { return sc.Double(); } }
        string rs { get { return sc.Scan(); } }
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());

        static T[] Enumerate<T>(int n, Func<int, T> f) {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f(i);
            return a;
        }
        static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
    }
}

#region main
static class Ex {
    static public string AsString(this IEnumerable<char> ie) { return new string(ie.ToArray()); }
    static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") {
        return string.Join(st, ie);
    }
    static public void Main() {
        Console.SetOut(new Program.IO.Printer(Console.OpenStandardOutput()) { AutoFlush = false });
        var solver = new Program.Solver();
        solver.Solve();
        Console.Out.Flush();
    }
}
#endregion
#region Ex
namespace Program.IO {
    using System.IO;
    using System.Text;
    using System.Globalization;

    public class Printer: StreamWriter {
        public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
        public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
    }

    public class StreamScanner {
        public StreamScanner(Stream stream) { str = stream; }

        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof = false;
        public bool IsEndOfStream { get { return isEof; } }

        private byte read() {
            if (isEof) return 0;
            if (ptr >= len)
            {
                ptr = 0;
                if ((len = str.Read(buf, 0, 1024)) <= 0)
                {
                    isEof = true;
                    return 0;
                }
            }
            return buf[ptr++];
        }

        public char Char() {
            byte b = 0;
            do b = read(); while ((b < 33 || 126 < b) && !isEof);
            return (char)b;
        }
        public string Scan() {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read()) sb.Append(b);
            return sb.ToString();
        }
        public string ScanLine() {
            var sb = new StringBuilder();
            for (var b = Char(); b != '\n' && b != 0; b = (char)read()) if (b != '\r') sb.Append(b);
            return sb.ToString();
        }
        public long Long() { return isEof ? long.MinValue : long.Parse(Scan()); }
        public int Integer() { return isEof ? int.MinValue : int.Parse(Scan()); }
        public double Double() { return isEof ? double.NaN : double.Parse(Scan(), CultureInfo.InvariantCulture); }
    }
}

#endregion

#region AVLTree
public abstract class AVLTreeNode<T>: BinaryTreeNode<T>
    where T : AVLTreeNode<T> {
    public int rank;
    public override void Update() {
        cnt = 1 + lst.cnt + rst.cnt;
        rank = 1 + Math.Max(lst.rank, rst.rank);
    }
}
public class AVLTree<T>: Tree<T>
    where T : AVLTreeNode<T>, new() {
    public override void Insert(T v, int k) { root = insert(root, v, k); }

    public override void RemoveAt(int k) { root = removeat(root, k); }

    T insert(T t, T v, int k) {
        if (t.cnt == 0)
        {
            v.lst = v.rst = NIL;
            v.Update();
            return v;
        }

        t = t.Push();
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
    T removeat(T t, int k) {
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
    where T : BinaryTreeNode<T> {

    public int cnt;
    public T lst, rst;
    public abstract T Push();
    /// <summary>
    /// ??????????? Update ???????
    /// </summary>
    public abstract void Update();
}

public abstract class Tree<TNode>
    where TNode : BinaryTreeNode<TNode>, new() {
    public Tree() { NIL = new TNode(); NIL.lst = NIL; NIL.rst = NIL; root = NIL; }
    public readonly TNode NIL;
    public TNode root;
    public int Count { get { return root.cnt; } }
    protected TNode rotR(TNode t) {
        t = t.Push();
        var l = t.lst.Push();
        t.lst = l.rst;
        l.rst = t;
        t.Update();
        l.Update();
        return l;
    }
    protected TNode rotL(TNode t) {
        t = t.Push();
        var r = t.rst.Push();
        t.rst = r.lst;
        r.lst = t;
        r.lst = t;
        t.Update();
        r.Update();
        return r;
    }
    public TNode Find(TNode t, int k) {
        t = t.Push();
        if (k < t.lst.cnt) return Find(t.lst, k);
        else if (k > t.lst.cnt) return Find(t.rst, k - t.lst.cnt - 1);
        else return t;
    }
    public abstract void Insert(TNode v, int k);
    public abstract void RemoveAt(int k);
}


#endregion


#region Set
public class Set<T>: ICollection<T> {
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
    public bool Add(T item) {
        var v = new Node() { Key = item };
        var lb = LowerBound(item);
        if (!IsMultiSet && UpperBound(item) != lb) return false;
        tree.Insert(v, lb);
        return true;
    }
    /// <summary>
    /// ????????????true????????false?O(logN)
    /// </summary>
    public bool Remove(T item) {
        var lb = LowerBound(item);
        var ub = UpperBound(item);
        if (ub == lb) return false;
        tree.RemoveAt(lb);
        return true;
    }
    /// <summary>
    /// 0-indexed ? k ??????????????????true????????false?O(logN)
    /// </summary>
    public bool RemoveAt(int k) {
        if (k < 0 || k >= Count) return false;
        tree.RemoveAt(k);
        return true;
    }
    /// <summary>
    /// 0-indexed ? k ????????????O(logN)
    /// </summary>
    public T this[int index] {
        get {
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
    public T[] Items {
        get {
            var ret = new T[Count];
            int ptr = 0;
            walk(tree.root, ret, ref ptr);
            return ret;
        }
    }

    public bool IsReadOnly { get { return false; } }

    void walk(Node root, T[] a, ref int ptr) {
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

    class Node: AVLTreeNode<Node>, IKey<T> {
        public T Key { get; set; }

        public override Node Push() {
            return this;
        }

    }
}
public static class TreeOperation {
    static public int LowerBound<T, K>
          (this T t, K k, IComparer<K> cmp)
          where T : BinaryTreeNode<T>, IKey<K> {
        if (t.cnt == 0) return 0;
        t = t.Push();
        if (cmp.Compare(k, t.Key) <= 0) return LowerBound(t.lst, k, cmp);
        else return 1 + t.lst.cnt + LowerBound(t.rst, k, cmp);
    }
    static public int UpperBound<T, K>
     (this T t, K k, IComparer<K> cmp)
       where T : BinaryTreeNode<T>, IKey<K> {
        if (t.cnt == 0) return 0;
        t = t.Push();
        if (cmp.Compare(t.Key, k) <= 0) return 1 + t.lst.cnt + UpperBound(t.rst, k, cmp);
        else return UpperBound(t.lst, k, cmp);
    }
}
#endregion