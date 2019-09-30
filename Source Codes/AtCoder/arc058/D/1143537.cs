#define A
using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Point = System.Numerics.Complex;
using Number = System.Int32;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {

            var n = sc.Integer();
            var k = sc.Integer();
            var back = new int[k + 1];
            for (int i = 0; i < k; i++)
                back[i] = -1;
            back[k] = n;
            var s = sc.Scan(n);
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = 0; j <= k; j++)
                    if (back[j] != -1 && j - s[i].Length >= 0) back[j - s[i].Length] = Math.Max(back[j - s[i].Length], i);
            }
            SuffixArray sa;
            {
                var sb = new StringBuilder();
                for (int i = 0; i < n; i++)
                {
                    sb.Append(s[i]);
                    sb.Append((char)('z' + 1));
                }
                sa = new SuffixArray(sb.ToString());
                sa.Init();
                sa.BuildLCP();
            }
            var dp = new bool[k + 1];
            dp[0] = true;
            var best = Enumerate(k, x => '|');

            var sum = 0;
            for (int i = 0; i < n; i++)
            {
                var len = s[i].Length;
                var zs = StringEx.ZAlgorithm(string.Concat(s[i], "$", new string(best)));
                var npos = -1;
                var npos2 = -1;
                var next = Enumerate(k + 1, x => -100);
                for (int j = k - 1; j >= 0; j--)
                {
                    if (j + len > k) continue;
                    if (!dp[j]) continue;
                    if (back[j + len] <= i) continue;
                    var lcp = zs[len + 1 + j];
                    if (j + lcp != k && lcp != s[i].Length && best[j + lcp] > s[i][lcp])
                    {
                        npos = j;
                        npos2 = j + lcp;
                        next[j + len] = npos;
                        continue;
                    }
                    if (j + lcp != k && lcp != s[i].Length && best[j + lcp] < s[i][lcp]) continue;
                    if (j + lcp == k || lcp == s[i].Length) continue;
                    if (npos != -1)
                    {
                        if (j + len <= npos)
                        {
                            npos = j;
                            npos2 = j + 1;
                            next[j + len] = npos;
                        }
                        else
                        {
                            var lcp2 = sa.GetLCP(sum, sum + npos - j);
                            if (npos - j + lcp2 == len)
                            {
                                next[j + len] = npos;
                            }
                            else if (s[i][lcp2] > s[i][npos - j + lcp2])
                            {
                                npos = j;
                                npos2 = j + lcp2;
                                next[j + len] = npos;
                            }
                        }
                    }
                }
                if (npos != -1)
                {
                    for (int j = 0; j < len; j++)
                        best[npos + j] = s[i][j];
                    for (int j = npos + len; j < k; j++)
                        best[j] = '|';
                    for (int j = npos2 + 1; j <= k; j++) dp[j] = false;
                    dp[npos] = true;
                    dp[npos + len] = true;
                    for (int j = 0; j <= k; j++)
                        if (next[j] == npos) dp[j] |= true;
                }
                sum += len + 1;
            }
            IO.Printer.Out.WriteLine(best);
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

#region SuffixArray
/// <summary>
/// O(N) ??
/// </summary>
/// 
public class SuffixArray
{
    int[] S;
    int N;
    int[] SA;
    int[] rank;
    sparseTableRMQ rmq;
    const char ZERO = 'a';
    const int K = 28;
    public SuffixArray(string str)
    {
        N = str.Length;
        S = new int[N + 3];
        for (int i = 0; i < N; i++) S[i] = str[i] - ZERO + 1;
        SA = new int[N];
        rank = new int[N + 1];
    }
    public void Init()
    {
        rec(S, SA, N, K);
        for (int i = 0; i < N; i++)
            rank[SA[i]] = i + 1;
        rank[N] = 0;
    }
    public void BuildLCP()
    {
        var k = 0;
        var h = new int[N + 1];
        for (int i = 0; i < N; i++)
        {
            var j = this[rank[i] - 1];
            if (k > 0) k--;
            for (; j + k < N && i + k < N; k++) if (S[j + k] != S[i + k]) break;
            h[rank[i] - 1] = k;
        }
        rmq = new sparseTableRMQ(h);
    }
    public int GetLCP(int i, int j)
    {
        i = rank[i]; j = rank[j];
        return rmq.Query(Math.Min(i, j), Math.Max(i, j));
    }
    void rec(int[] s, int[] sa, int n, int k)
    {
        //Debug.WriteLine("{0} {1}", n, k);
        if (n == 1) { sa[0] = 0; return; }
        int a = (n + 2) / 3, b = (n + 1) / 3, c = n / 3;
        int ac = a + c;

        int[] tbc = new int[ac + 3], tabc = new int[ac + 3];
        int[] ta = new int[a];
        int[] taa = new int[a];

        for (int i = 0, j = 0; i < n + (a - c); i++) if (i % 3 != 0) tbc[j++] = i;
        radixPass(tbc, tabc, s, 2, ac, k);
        radixPass(tabc, tbc, s, 1, ac, k);
        radixPass(tbc, tabc, s, 0, ac, k);

        int name = 0, c0 = -1, c1 = -1, c2 = -1;
        for (int i = 0; i < ac; i++)
        {
            if (s[tabc[i]] != c0 || s[tabc[i] + 1] != c1 || s[tabc[i] + 2] != c2)
            {
                name++; c0 = s[tabc[i]]; c1 = s[tabc[i] + 1]; c2 = s[tabc[i] + 2];
            }
            if (tabc[i] % 3 == 1) tbc[tabc[i] / 3] = name;
            else
            {

                tbc[tabc[i] / 3 + a] = name;
            }
        }
        if (name < ac)
        {
            tbc[ac] = 0;
            rec(tbc, tabc, ac, name);
            for (int i = 0; i < ac; i++) tbc[tabc[i]] = i + 1;
        }
        else
        {
            for (int i = 0; i < ac; i++) tabc[tbc[i] - 1] = i;
        }
        for (int i = 0, j = 0; i < ac; i++) if (tabc[i] < a) ta[j++] = 3 * tabc[i];
        radixPass(ta, taa, s, 0, a, k);
        for (int p = 0, t = a - b, ptr = 0; ptr < n; ptr++)
        {
            int i = (tabc[t] < a) ? (tabc[t] * 3 + 1) : ((tabc[t] - a) * 3 + 2);
            var j = taa[p];
            if ((tabc[t] < a) ?
                s[i] < s[j] || (s[i] == s[j] && tbc[tabc[t] + a] < tbc[j / 3]) :
                s[i] < s[j] ||
                (s[i] == s[j] && s[i + 1] < s[j + 1]) ||
                (s[i] == s[j] && s[i + 1] == s[j + 1] && tbc[tabc[t] - a + 1] < tbc[j / 3 + a]))
            {
                sa[ptr] = i; t++;
                if (t == ac) for (ptr++; p < a; p++, ptr++) sa[ptr] = taa[p];
            }
            else
            {
                sa[ptr] = j; p++;
                if (p == a)
                    for (ptr++; t < ac; t++, ptr++) sa[ptr] = (tabc[t] < a) ? (tabc[t] * 3 + 1) : ((tabc[t] - a) * 3 + 2);

            }
        }
    }
    void radixPass(int[] a, int[] b, int[] s, int offset, int n, int k)
    {
        var c = new int[k + 1];
        for (int i = 0; i < n; i++) c[s[a[i] + offset]]++;
        for (int i = 0, sum = 0; i <= k; i++)
        {
            var t = c[i]; c[i] = sum; sum += t;
        }
        var ret = new int[n];
        for (int i = 0; i < n; i++) b[c[s[a[i] + offset]]++] = a[i];
    }
    /// <summary>
    /// rank?i??????
    /// </summary>
    public int this[int index]
    {
        get { return index == 0 ? N : SA[index - 1]; }
    }
    /// <summary>
    /// s[i:]???????
    /// </summary>
    public int Rank(int index)
    {
        return rank[index];
    }
    #region SparseTableRMQ
    public class sparseTableRMQ
    {
        int n;
        int[] A;
        public sparseTableRMQ(int[] a)
        {
            var k = 1;
            n = a.Length;
            for (int i = 1; i < n; i <<= 1) k++;

            A = new int[n * k];
            for (int i = 0; i < n; i++)
                A[i] = a[i];
            var d = 0;
            for (int i = 1; i < n; i <<= 1)
            {
                for (int j = 0; j < n; j++)
                    A[d + n + j] = A[d + j];
                d += n;
                for (int j = 0; j < n - i; j++)
                    A[d + j] = Math.Min(A[d + j], A[d + j + i]);
            }
        }
        /// <summary>
        /// value of [l,r)
        /// </summary>
        public int Query(int l, int r)
        {
            r--;
            int z = r - l, k = 0, e = 1, s;
            s = ((z & 0xffff0000) != 0 ? 1 : 0) << 4; z >>= s; e <<= s; k |= s;
            s = ((z & 0x0000ff00) != 0 ? 1 : 0) << 3; z >>= s; e <<= s; k |= s;
            s = ((z & 0x000000f0) != 0 ? 1 : 0) << 2; z >>= s; e <<= s; k |= s;
            s = ((z & 0x0000000c) != 0 ? 1 : 0) << 1; z >>= s; e <<= s; k |= s;
            s = ((z & 0x00000002) != 0 ? 1 : 0) << 0; z >>= s; e <<= s; k |= s;
            //var vl = A[l + n * k];
            //var vr = A[r - e + 1 + (n * k)];
            return Math.Min(A[l + (n * k)], A[r + (n * k) - e + 1]);
        }
    }
    #endregion
}
#endregion


#region Z Algorithm
static public partial class StringEx
{
    /// <summary>???????????????????????????????O(|S|)</summary>
    static public int[] ZAlgorithm(string s)
    {
        var a = new int[s.Length + 1];
        a[0] = s.Length;
        int i = 1, j = 0;
        while (i < s.Length)
        {
            while (i + j < s.Length && s[j] == s[i + j]) ++j;
            a[i] = j;
            if (j == 0) { ++i; continue; }
            int k = 1;
            while (i + k < s.Length && k + a[k] < j) { a[i + k] = a[k]; ++k; }
            i += k; j -= k;
        }
        return a;
    }
    /// <summary>s??????????????t?????????????????????O(|S|)</summary>
    /// <returns>ret[i]=i??????????????t???????????????</returns>
    static public int[] ZAlgorithm(string s, string t)
    {
        var ns = t + s;
        /*
        var ns = new int[t.Length + s.Length];
        for (int i = 0; i < t.Length; i++)
            ns[i] = t[i];
        for (int i = 0; i < s.Length; i++)
            ns[i + t.Length] = s[i];
        //*/
        var res = ZAlgorithm(ns);
        var ret = new int[s.Length + 1];
        for (int i = t.Length; i < res.Length; i++)
            ret[i - t.Length] = res[i];
        return ret;


    }
}
#endregion