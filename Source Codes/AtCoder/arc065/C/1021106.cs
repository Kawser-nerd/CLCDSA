using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Number = System.Int64;
using P = Pair<long, long>;
namespace Program
{

    public class Solver
    {
        public void Solve()
        {
            var n = sc.Integer();
            var a = sc.Integer() - 1; var b = sc.Integer() - 1;
            var A = new P[n];
            for (int i = 0; i < n; i++)
                A[i] = new P(sc.Integer(), sc.Integer());
            var d = Math.Abs(A[a].x - A[b].x) + Math.Abs(A[a].y - A[b].y);
            var XY = new AVLTree();
            var YX = new AVLTree();
            var xy = new AVLTree();
            var yx = new AVLTree();
            for (int i = 0; i < n; i++)
            {
                var x = A[i].x; var y = A[i].y;
                A[i].x = x - y;
                A[i].y = x + y;
                XY.Add(new P(A[i].x, A[i].y));
                YX.Add(new P(A[i].y, A[i].x));
                xy.Add(new P(A[i].x, A[i].y));
                yx.Add(new P(A[i].y, A[i].x));
                //Debug.WriteLine(A[i]);
            }
            var ans = 0L;
            Action<P> dfs = null;
            var used = new SortedSet<int>();
            dfs = p =>
              {
                  if (!xy.Remove(p)) return;
                  yx.Remove(new P(p.y, p.x));
                  Debug.WriteLine(p);
                  for (int k = -1; k <= 1; k++)
                      for (int l = -1; l <= 1; l++)
                      {
                          if (Math.Abs(k) + Math.Abs(l) != 1) continue;
                          var px = p.x + k * d;
                          var py = p.y + l * d;
                          int ub, lb;
                          if (k == 0) { ub = YX.UpperBound(new P(py, px + d)); lb = YX.LowerBound(new P(py, px - d)); }
                          else { ub = XY.UpperBound(new P(px, py + d - 1)); lb = XY.LowerBound(new P(px, py - d + 1)); }
                          ans += ub - lb;
                          while (yx.Count > 0)
                          {
                              if (k == 0) { ub = yx.UpperBound(new P(py, px + d)); lb = yx.LowerBound(new P(py, px - d)); }
                              else { ub = xy.UpperBound(new P(px, py + d - 1)); lb = xy.LowerBound(new P(px, py - d + 1)); }
                              if (ub != lb)
                              {
                                  if (k == 0)
                                  {
                                      var q = yx[lb];
                                      Swap(ref q.x, ref q.y);
                                      dfs(q);
                                  }
                                  else dfs(xy[lb]);
                              }
                              else break;

                          }
                      }


              };
            dfs(A[a]);
            IO.Printer.Out.WriteLine(ans / 2);
        }

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
#region Compair
static public class Pair
{
    static public Pair<FT, ST> Create<FT, ST>(FT f, ST s) where FT : IComparable<FT> where ST : IComparable<ST>
    {
        return new Pair<FT, ST>(f, s);
    }
    static public Pair<FT, ST> Min<FT, ST>(Pair<FT, ST> p, Pair<FT, ST> q) where FT : IComparable<FT> where ST : IComparable<ST>
    {
        return (p.CompareTo(q) <= 0) ? p : q;
    }
    static public Pair<FT, ST> Max<FT, ST>(Pair<FT, ST> p, Pair<FT, ST> q) where FT : IComparable<FT> where ST : IComparable<ST>
    {
        return (p.CompareTo(q) >= 0) ? p : q;
    }
}
public struct Pair<FT, ST>: IComparable<Pair<FT, ST>> where FT : IComparable<FT> where ST : IComparable<ST>
{
    public FT x;
    public ST y;
    public Pair(FT f, ST s) : this() { x = f; y = s; }

    public int CompareTo(Pair<FT, ST> other)
    {
        var cmp = x.CompareTo(other.x);
        return cmp != 0 ? cmp : y.CompareTo(other.y);
    }
    public override string ToString() { return string.Format("{0} {1}", x, y); }
}
#endregion

#region AVLTree
public class AVLTree
{
    Node nil = new NilNode();
    Node root { get { return nil.lst; } }
    public AVLTree() { nil.lst = nil.rst = nil; }

    public int Count { get { return nil.lst.cnt; } }
    public void Add(P v) { Insert(v, LowerBound(v)); }
    public bool Remove(P v)
    {
        if (EqualRange(v) == 0) return false;
        RemoveAt(LowerBound(v));
        return true;
    }
    #region Impl
    public void Insert(P v, int k)
    {
        Node p = nil, t = nil.lst;
        if (t.cnt < k)
            throw new IndexOutOfRangeException();
        var isL = true;
        while (t != nil)
        {
            if (t.lst.cnt >= k) { p = t; t = t.lst; isL = true; }
            else { k -= (t.lst.cnt + 1); p = t; t = t.rst; isL = false; }
        }
        if (isL) { p.lst = CreateNode(v, p); Balance(true, p.lst); }
        else { p.rst = CreateNode(v, p); Balance(true, p.rst); }
    }
    public void RemoveAt(int k)
    {
        var t = nil.lst;
        while (t != nil)
        {
            if (t.lst.cnt > k) { t = t.lst; }
            else if (t.lst.cnt < k) { k -= t.lst.cnt + 1; t = t.rst; }
            else
            {
                if (t.lst == nil) { Node.Replace(t, t.rst); Balance(false, t.rst); }
                else
                {
                    var m = GetMaxNode(t.lst);
                    t.val = m.val;
                    Node.Replace(m, m.lst);
                    Balance(false, m.lst);
                }
                return;
            }
        }
    }
    public int EqualRange(P v) { return UpperBound(v) - LowerBound(v); }
    public int LowerBound(P v) { return lowerBound(nil.lst, v); }
    public int UpperBound(P v) { return upperBound(nil.lst, v); }
    public P this[int k] { get { return find(nil.lst, k); } }

    int lowerBound(Node t, P v)
    {
        if (t.cnt == 0) return 0;
        if (v.CompareTo(t.val) <= 0) return lowerBound(t.lst, v);
        else return t.lst.cnt + 1 + lowerBound(t.rst, v);
    }
    int upperBound(Node t, P v)
    {
        if (t.cnt == 0) return 0;
        if (t.val.CompareTo(v) <= 0) return t.lst.cnt + 1 + upperBound(t.rst, v);
        else return upperBound(t.lst, v);
    }
    P find(Node t, int k)
    {
        if (t.cnt <= k) throw new IndexOutOfRangeException();
        if (k == t.lst.cnt) return t.val;
        else if (k < t.lst.cnt) return find(t.lst, k);
        else return find(t.rst, k - (t.lst.cnt + 1));
    }
    #endregion
    class Node
    {
        int h;
        public int cnt;
        //public int Count { get { return cnt; } }
        public int Height { get { return h; } }
        public int Bias { get { return lst.Height - rst.Height; } }
        internal P val;
        internal Node par, lst, rst;
        internal bool rev;
        internal Node() { }
        internal Node(P v, Node p) { h = 1; cnt = 1; val = v; ; par = p; }
        public void Update()
        {
            h = 1 + Math.Max(lst.h, rst.h);
            cnt = 1 + lst.cnt + rst.cnt;
        }
        public override string ToString()
        {
            return string.Format("count:{0}, value:{1}", cnt, val);
        }

        #region Impl
        static internal void Replace(Node u, Node v)
        {
            var p = u.par;
            if (p.lst == u) p.lst = v;
            else p.rst = v;
            v.par = p;
        }
        static internal Node RotateL(Node v)
        {
            Node u = v.rst; Replace(v, u);
            v.rst = u.lst; u.lst.par = v;
            u.lst = v; v.par = u;
            v.Update();
            u.Update();
            return u;
        }
        static internal Node RotateR(Node u)
        {
            var v = u.lst; Replace(u, v);
            u.lst = v.rst; v.rst.par = u;
            v.rst = u; u.par = v;
            u.Update();
            v.Update();
            return v;
        }
        static internal Node RotateLR(Node t)
        {
            RotateL(t.lst);
            return RotateR(t);
        }
        static internal Node RotateRL(Node t)
        {
            RotateR(t.rst);
            return RotateL(t);
        }
        #endregion


    }
    class NilNode: Node { public override string ToString() { return "nil"; } }

    Node CreateNode() { return new Node() { lst = nil, rst = nil }; }
    Node CreateNode(P v, Node p) { return new Node(v, p) { lst = nil, rst = nil }; }

    void Balance(bool onInsert, Node t)
    {
        while (t.par != nil)
        {
            var u = t.par;
            var h = u.Height;
            if ((u.lst == t) == onInsert)
            {
                if (u.Bias == 2)
                {
                    if (u.lst.Bias >= 0) u = Node.RotateR(u);
                    else u = Node.RotateLR(u);
                }
                else u.Update();
            }
            else
            {
                if (u.Bias == -2)
                {
                    if (u.rst.Bias <= 0) u = Node.RotateL(u);
                    else u = Node.RotateRL(u);
                }
                else u.Update();
            }
            if (h == u.Height) break;
            t = u;
        }
        while (t.par != nil) { t.par.Update(); t = t.par; }
    }

    Node GetMaxNode(Node t)
    {
        while (t.rst != nil) t = t.rst;
        return t;
    }
}
#endregion