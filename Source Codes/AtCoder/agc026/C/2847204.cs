using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
namespace Program {
    public class Solver {
        Random rnd = new Random();
        public void Solve() {
            var n = ri;
            var s = rs;
            Debug.WriteLine(s);
            var ss = s.Take(n).AsString();
            var tt = s.Skip(n).AsString();
            var A = make(ss, false);
            var B = make(tt, true);
            var ans = 0L;
            foreach (var x in A)
            {
                Debug.WriteLine($"{x.Key} {x.Value} {B[x.Key]}");
                ans += x.Value * B[x.Key];
            }
            Console.WriteLine(ans);
        }
        HashMap<string, long> make(string s, bool rev) {
            Debug.WriteLine(s);
            var map = new HashMap<string, long>();
            for (int i = 0; i < 1 << s.Length; i++)
            {
                var a = new SB();
                var b = new SB();
                for (int j = 0; j < s.Length; j++)
                {
                    if ((i >> j & 1) == 0) a.Append(s[j]);
                    else b.Append(s[j]);
                }
                var ss = a.ToString();
                var tt = b.ToString();
                if (!rev) map[ss + "$" + tt]++;
                else
                {
                    tt = tt.Reverse().AsString();
                    ss = ss.Reverse().AsString();
                    if (tt == "cba" && ss == "a")
                    {

                    }
                    map[tt + "$" + ss]++;

                }
            }
            return map;

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


#region HashMap<K,V>
public class HashMap<K, V>: Dictionary<K, V>
//where V : new()
{
    public HashMap() : base() { }
    public HashMap(int cap) : base(cap) { }
    new public V this[K i] {
        get {
            V v;
            return TryGetValue(i, out v) ? v :
                base[i] = default(V);
            //base[i] = new V();
        }
        set { base[i] = value; }
    }
}
#endregion