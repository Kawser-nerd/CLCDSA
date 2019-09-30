using System;
using System.Linq;
using System.Linq.Expressions;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Point = System.Numerics.Complex;
using Number = System.Double;
using _ANSWER = System.String;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var T = sc.Integer();
            var ans = new _ANSWER[T];
            var f = new Func<_ANSWER>[T];
            for (int _ = 0; _ < T; _++)
            {
                var s = sc.Scan();
                f[_] = () => solve2(s);
                ans[_] = f[_]();
            }
            //System.Threading.Tasks.Parallel.For(0, T, i => ans[i] = f[i]());
            for (int i = 0; i < T; i++)
            {
                IO.Printer.Out.WriteLine($"Case #{i+1}: {ans[i]}");
            }
        }
        private _ANSWER solve(string s)
        {
            var val = new string[]
            {
                "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
            };
            var map = new HashMap<char, int>();
            foreach (var x in s) map[x]++;
            string ans = null;
            Action<int, string> dfs = null;
            dfs = (k, str) =>
              {
                  if (k == 10)
                  {
                      if (map.All(x => x.Value == 0)) ans = str;
                      return;
                  }
                  {
                      foreach (var c in val[k])
                      {
                          map[c]--;
                      }
                      var ok = true;
                      foreach (var kv in map)
                          if (kv.Value < 0) ok = false;
                      if (ok)
                          dfs(k, str + k.ToString());
                      foreach (var c in val[k])
                      {
                          map[c]++;
                      }
                  }
                  dfs(k + 1, str);
              };
            dfs(0, "");
            return ans;
        }
        private _ANSWER solve2(string s)
        {
            var map = new HashMap<char, int>();
            foreach (var x in s) map[x]++;
            var chk = "ZWXSGVFOTN";
            var val = new string[]
            {
                "ZERO","TWO","SIX","SEVEN","EIGHT","FIVE","FOUR","ONE","THREE","NINE"
            };
            var otaku = new int[] { 0, 2, 6, 7,  8, 5, 4, 1, 3 ,9};
            var ans = new List<int>();
            for (int i = 0; i < 10; i++)
            {
                var k = 1;
                if (val[i] == "NINE") k = 2;
                var a = map[chk[i]];
                for (int j = 0; j < a / k; j++)
                {
                    foreach (var x in val[i])
                        map[x]--;
                    ans.Add(otaku[i]);
                }
            }
            ans.Sort();
            return ans.AsJoinedString("");
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
    public class Printer : StreamWriter
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
#region HashMap
public class HashMap<K, V> : Dictionary<K, V>
//where V : new()
{
    public HashMap() : base() { }
    public HashMap(int cap) : base(cap) { }
    new public V this[K i]
    {
        get
        {
            V v;
            return TryGetValue(i, out v) ? v :
                base[i] = default(V);
            //base[i] = new V();
        }
        set { base[i] = value; }
    }
}
#endregion