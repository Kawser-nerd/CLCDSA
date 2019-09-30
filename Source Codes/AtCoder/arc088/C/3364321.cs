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
            var s = rs;
            var cnt = new int[26];
            foreach (var c in s) cnt[c - 'a']++;
            if (cnt.Sum(x => x % 2) > 1)
            {
                Console.WriteLine(-1);
                return;
            }

            var A = new List<int>();
            var B = new List<int>();
            var C = new List<int>();
            var k = new int[26];
            for (int i = 0; i < s.Length; i++)
            {
                var v = s[i] - 'a';
                k[v]++;
                if (k[v] * 2 <= cnt[v]) A.Add(i);
                else
                {
                    if (cnt[v] % 2 == 1)
                    {
                        cnt[v]--;
                        B.Add(i);
                    }
                    else C.Add(i);
                }
            }
            var ans = 0L;
            var ord = Enumerate(26, x => new List<int>(cnt[x]));
            var D = new int[C.Count];
            for (int i = 0; i < A.Count; i++)
                ord[s[A[i]] - 'a'].Add(i);
            for (int i = 0; i < C.Count; i++)
            { D[i] = ord[s[C[i]] - 'a'].Last(); ord[s[C[i]] - 'a'].RemoveAt(ord[s[C[i]] - 'a'].Count - 1); }
            Array.Reverse(D);
            ans += f(ref D, 0, D.Length);
            D = new int[s.Length];
            var ptr = 0;
            foreach (var x in A) D[ptr++] = x;
            foreach (var x in B) D[ptr++] = x;
            foreach (var x in C) D[ptr++] = x;
            ans += f(ref D, 0, D.Length);

            Console.WriteLine(ans);
        }

        int[] tmp = new int[260050];
        //[l,r) ?????????????
        long f(ref int[] a, int l, int r) {
            if (r - l <= 1) return 0L;
            var m = (l + r) / 2;
            var ret = 0L;
            ret += f(ref a, l, m);
            ret += f(ref a, m, r);
            var p = l; var q = m;
            var ptr = l;
            while (p < m && q < r)
            {
                if (a[p] < a[q]) { ret += (q - m); tmp[ptr++] = a[p++]; }
                else { tmp[ptr++] = a[q++]; }
            }
            while (p < m) { ret += q - m; tmp[ptr++] = a[p++]; }
            while (q < r) { tmp[ptr++] = a[q++]; }
            for (int i = l; i < r; i++)
                a[i] = tmp[i];
            Debug.WriteLine($"[{l} {r}),{ret}");
            return ret;
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