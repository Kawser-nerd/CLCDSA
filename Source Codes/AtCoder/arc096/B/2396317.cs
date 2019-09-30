using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
//using System.Numerics;
using static System.Math;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var n = ri;
            var L = rl;
            var a = new long[n];
            var b = new long[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = rl;
                b[i] = rl;
            }
            var ans = solve(n, L, a.ToArray(), b.ToArray());
            for (int i = 0; i < n; i++)
                a[i] = L - a[i];
            Array.Reverse(a); Array.Reverse(b);
            ans = Math.Max(ans, solve(n, L, a, b));
            Console.WriteLine(ans);

        }
        long solve(int n, long L, long[] a, long[] b) {
            var ret = 0L;
            var v = 0L;
            var cum = new long[n + 1];
            for (int i = 0; i < n; i++)
                cum[i + 1] = cum[i] + b[i];
            for (int i = 1; i <= n; i++)
                cum[i] -= a[i - 1];
            var rmq = new RMQ(n + 1);
            for (int i = 0; i <= n; i++)
            {
                rmq.Update(i, cum[i]);
            }
            for (int i = 0; i <= n; i++)
            {
                var u = 0L;
                if (i != 0) { v += b[n - i]; u -= 2 * (L - a[n - i]); }
                u += v;
                u += rmq.Query(0, n - i + 1);
                ret = Math.Max(ret, u);
                Debug.WriteLine(u);
            }
            return ret;
        }
        const long INF = 1L << 60;
        static int[] dx = { -1, 0, 1, 0 };
        static int[] dy = { 0, 1, 0, -1 };
        const string URDL = "URDL";
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
        try
        {
            solver.Solve();
            Console.Out.Flush();
        }
        catch { }
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


#region SegTree Operator
public interface IData<T> {
    T Merge(T l, T r);
    T Identity { get; }
    T InitValue { get; }
}
#endregion
#region Segment Tree

public class SegmentTree<T, U>
   where U : struct, IData<T> {
    int sz;
    int n;
    T[] data;
    U op;
    public SegmentTree(int size) {
        sz = size;
        n = 1;
        while (n < size) n *= 2;
        data = new T[n * 2];
        for (int i = 0; i < data.Length; i++)
            data[i] = op.InitValue;
    }
    public SegmentTree(T[] a) {
        sz = a.Length;
        n = 1;
        while (n < sz) n *= 2;
        data = new T[n * 2];
        for (int i = 0; i < n; i++)
            data[i + n] = (i < a.Length) ? a[i] : op.InitValue;
        for (int i = n - 1; i >= 0; i--)
            data[i] = op.Merge(data[i * 2], data[i * 2 + 1]);
    }
    public void Update(int k, T v) {
        k += n;
        data[k] = v;
        for (k = k / 2; k > 0; k /= 2)
            data[k] = op.Merge(data[k * 2], data[k * 2 + 1]);

    }
    public T Query(int a, int b) { return query(a, b, 1, 0, n); }
    private T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)
            return op.Identity;
        if (a <= l && r <= b)
            return data[k];
        else
        {
            var vl = query(a, b, k * 2, l, (l + r) / 2);
            var vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
            return op.Merge(vl, vr);
        }
    }
    public T[] Items {
        get {
            var ret = new T[sz];
            for (int i = 0; i < sz; i++)
                ret[i] = data[i + n];
            return ret;
        }
    }

}
#endregion
#region RmQ
public class RmQ: SegmentTree<long, MinData> {
    public RmQ(int size) : base(size) { }
}
public struct MinData: IData<long> {
    public long InitValue { get { return 0; } }
    public long Identity { get { return long.MaxValue; } }
    public long Merge(long l, long r) { return Math.Min(l, r); }


}
#endregion
#region RMQ
public class RMQ: SegmentTree<long, MaxData> {
    public RMQ(int size) : base(size) { }
}
public struct MaxData: IData<long> {
    public long Identity { get { return long.MinValue; } }

    public long InitValue { get { return 0; } }

    public long Merge(long l, long r) { return Math.Max(l, r); }
}
#endregion