using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
using Point = System.Numerics.Complex;
using Number = System.Int64;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var n = ri;
            var W = new int[n];
            var B = new int[n];
            for (int i = 0; i < 2 * n; i++)
            {
                var s = rs;
                var v = ri - 1;
                if (s == "W") W[v] = i;
                else B[v] = i;
            }
            var add = 0L;
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                {
                    if (W[i] > W[j]) add++;
                    if (B[i] > B[j]) add++;
                }


            //????? i ??????? j ??????????
            var f = new long[n + 1, n + 1];
            //????? i ??????? j ??????????
            var g = new long[n + 1, n + 1];

            var ws = new Set<int>();
            var bs = new Set<int>();
            for (int i = 0; i < n; i++)
            {
                ws.Add(W[i]); bs.Add(B[i]);
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    var lb1 = ws.LowerBound(B[j]);
                    var lb2 = bs.LowerBound(W[j]);
                    g[j, i] = lb1;
                    f[j, i] = lb2;
                }
                ws.Remove(W[i]); bs.Remove(B[i]);
            }

            var dp = new long[n + 2, n + 2];
            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= n; j++)
                    dp[i, j] = INF;
            dp[0, 0] = 0;
            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= n; j++)
                {
                    dp[i + 1, j] = Min(dp[i + 1, j], dp[i, j] + f[i, j]);
                    dp[i, j + 1] = Min(dp[i, j + 1], dp[i, j] + g[j, i]);
                }

            Console.WriteLine(dp[n, n] + add);
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

#region Set<T>
public class Set<T>
    where T : IComparable<T> {

    Node root = Node.NIL;

    public int Count { get { return root.cnt; } }
    public void Add(T v) { Insert(v, LowerBound(v)); }
    public bool Remove(T v) {
        if (EqualRange(v) == 0) return false;
        RemoveAt(LowerBound(v));
        return true;
    }
    #region Impl
    public void Insert(T v, int k) {
        root = insert(root, v, k);
    }
    public void RemoveAt(int k) {
        root = removeat(root, k);
    }
    public int EqualRange(T v) { return UpperBound(v) - LowerBound(v); }
    public int LowerBound(T v) { return lowerBound(root, v); }
    public int UpperBound(T v) { return upperBound(root, v); }
    public T this[int k] { get { return find(root, k); } }
    Node insert(Node t, T v, int k) {
        Debug.Assert(t.cnt >= k);
        if (t == Node.NIL) return new Node(v);
        if (t.lst.cnt >= k)
            t.lst = insert(t.lst, v, k);
        else
            t.rst = insert(t.rst, v, k - t.lst.cnt - 1);
        t.Update();

        if (t.lst.h - t.rst.h == -2)
        {
            if (t.rst.lst.h - t.rst.rst.h > 0) t.rst = rotR(t.rst);
            t = rotL(t);
        }
        else if (t.lst.h - t.rst.h == 2)
        {
            if (t.lst.lst.h - t.lst.rst.h < 0) t.lst = rotL(t.lst);
            t = rotR(t);
        }
        t.Update();
        return t;
    }
    Node removeat(Node t, int k) {
        Debug.Assert(t.cnt > k);
        var cnt = t.lst.cnt;
        if (cnt < k) t.rst = removeat(t.rst, k - cnt - 1);
        else if (cnt > k) t.lst = removeat(t.lst, k);
        else
        {
            if (cnt == 0) return t.rst;
            if (t.rst.cnt == 0) return t.lst;

            t.val = find(t, k - 1);
            t.lst = removeat(t.lst, k - 1);
        }
        t.Update();
        if (t.lst.h - t.rst.h == -2)
        {
            if (t.rst.lst.h - t.rst.rst.h > 0) t.rst = rotR(t.rst);
            t = rotL(t);
        }
        else if (t.lst.h - t.rst.h == 2)
        {
            if (t.lst.lst.h - t.lst.rst.h < 0) t.lst = rotL(t.lst);
            t = rotR(t);
        }
        else t.Update();
        return t;
    }

    int lowerBound(Node t, T v) {
        if (t.cnt == 0) return 0;
        if (v.CompareTo(t.val) <= 0) return lowerBound(t.lst, v);
        else return t.lst.cnt + 1 + lowerBound(t.rst, v);
    }
    int upperBound(Node t, T v) {
        if (t.cnt == 0) return 0;
        if (t.val.CompareTo(v) <= 0) return t.lst.cnt + 1 + upperBound(t.rst, v);
        else return upperBound(t.lst, v);
    }
    T find(Node t, int k) {
        Debug.Assert(k < t.cnt);
        if (k == t.lst.cnt) return t.val;
        else if (k < t.lst.cnt) return find(t.lst, k);
        else return find(t.rst, k - (t.lst.cnt + 1));
    }
    Node rotR(Node t) {
        var l = t.lst;
        var lr = l.rst;
        l.rst = t;
        t.lst = lr;
        t.Update();
        l.Update();
        return l;
    }
    Node rotL(Node t) {
        var r = t.rst;
        var rl = r.lst;
        t.rst = rl;
        r.lst = t;
        t.Update();
        r.Update();
        return r;
    }
    #endregion
    class Node {
        static public readonly Node NIL = new Node();
        public int h;
        public int cnt;
        internal T val;
        internal Node lst, rst;
        private Node() { }
        internal Node(T v) { h = 1; cnt = 1; val = v; lst = NIL; rst = NIL; }
        public void Update() {
            if (cnt == 0) return;
            h = 1 + Math.Max(lst.h, rst.h);
            cnt = 1 + lst.cnt + rst.cnt;
        }
        public override string ToString() {
            return string.Format("count:{0}, value:{1}", cnt, val);
        }
        public T[] Items { get { return items(this); } }
        static public T[] items(Node t) {
            var ret = new T[t.cnt];
            var ptr = 0;
            dfs(t, ref ptr, ret);
            return ret;
        }
        static void dfs(Node t, ref int ptr, T[] ret) {
            if (t == Node.NIL) return;
            dfs(t.lst, ref ptr, ret);
            ret[ptr++] = t.val;
            dfs(t.rst, ref ptr, ret);
        }
    }
    public T[] Items { get { return root.Items; } }
    public override string ToString() { return string.Format("Count = {0}", Count); }

}
#endregion