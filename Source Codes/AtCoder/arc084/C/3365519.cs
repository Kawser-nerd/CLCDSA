using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
using Point = System.Numerics.Complex;
using Number = System.Int64;
using C = System.Int64;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var k = ri;
            var n = ri;
            if (k == 1)
            {
                Console.WriteLine(Enumerate((n + 1) / 2, x => k).AsJoinedString());
                return;
            }
            /*
            var otaku = new List<string>();
            Action<string> dfs = null;
            dfs = str =>
            {
                if (str.Length != 0) otaku.Add(str);
                if (str.Length == n) return;
                for (int i = 1; i <= k; i++)
                    dfs(str + $"{i}");

            };
            dfs("");
            otaku.Sort(StringComparer.Ordinal);
            //foreach (var x in otaku) Console.WriteLine(x);
            Console.WriteLine(otaku[(otaku.Count - 1) / 2]);
            //*/
            if (k % 2 == 0)
            {
                var ans = new int[n];
                for (int i = 0; i < n; i++)
                    ans[i] = k;
                ans[0] = k / 2;
                Console.WriteLine(ans.AsJoinedString());
                return;
            }
            else
            {

                var ans = Enumerate(n, x => (k + 1) / 2).ToList();
                var rev = n / 2;
                while (rev > 0)
                {
                    //Debug.WriteLine(rev);
                    //Debug.WriteLine(ans.AsJoinedString());
                    if (ans.Last() == 0)
                    {
                        while (ans.Last() == 0)
                            ans.RemoveAt(ans.Count - 1);
                        ans[ans.Count - 1]--;
                        rev--;
                        if (ans.Last() != 0)
                            while (ans.Count < n) ans.Add(k);
                        continue;
                    }
                    var mi = Math.Min(ans.Last(), rev);
                    rev -= mi;
                    ans[ans.Count - 1] -= mi;
                }
                if (ans.Last() == 0) ans.RemoveAt(ans.Count - 1);
                Console.WriteLine(ans.AsJoinedString());
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