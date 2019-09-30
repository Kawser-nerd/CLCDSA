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
                var n = sc.Integer();
                var r = sc.Integer();
                var p = sc.Integer();
                var s = sc.Integer();
                f[_] = () => solve(n, r, p, s);
                ans[_] = f[_]();
                IO.Printer.Out.WriteLine($"Case #{_ + 1}: {ans[_]}");
            }
            //System.Threading.Tasks.Parallel.For(0, T, i => ans[i] = f[i]());
            for (int _ = 0; _ < T; _++)
            {
            }
        }
        _ANSWER solve(int n, int r, int p, int s)
        {
            var R = new int[3] { 1, 0, 0 };
            var X = "R";
            var P = new int[3] { 0, 1, 0 };
            var Y = "P";
            var S = new int[3] { 0, 0, 1 };
            var Z = "S";

            for (int i = 1; i <= n; i++)
            {
                var NR = new int[3];
                var NP = new int[3];
                var NS = new int[3];
                var str = new string[6];
                for (int j = 0; j < 3; j++)
                {
                    NR[j] += R[j] + S[j];
                    NP[j] += P[j] + R[j];
                    NS[j] += S[j] + P[j];
                }
                R = NR;
                P = NP;
                S = NS;

                str[0] = X + Z;
                str[3] = Z + X;
                str[1] = Y + X;
                str[4] = X + Z;
                str[2] = Z + Y;
                str[5] = Y + Z;

                X = string.CompareOrdinal(str[0], str[3]) <= 0 ? str[0] : str[3];
                Y = string.CompareOrdinal(str[1], str[4]) <= 0 ? str[1] : str[4];
                Z = string.CompareOrdinal(str[2], str[5]) <= 0 ? str[2] : str[5];
            }
            var A = new int[] { r, p, s };

            if (A[0] == R[0] && A[1] == R[1] && A[2] == R[2])
            {
                Debug.WriteLine(R.AsJoinedString());
                return X;
            }
            if (A[0] == P[0] && A[1] == P[1] && A[2] == P[2])
            {
                Debug.WriteLine(P.AsJoinedString());
                return Y;
            }
            if (A[0] == S[0] && A[1] == S[1] && A[2] == S[2])
            {
                Debug.WriteLine(S.AsJoinedString());
                return Z;
            }

            return "IMPOSSIBLE";
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
