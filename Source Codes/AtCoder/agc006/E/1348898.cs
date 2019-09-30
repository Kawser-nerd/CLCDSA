using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
//using System.Numerics;
using Number = System.Int64;
using static System.Math;
//using static MathEx;
//using P = System.Collections.Generic.KeyValuePair<int, int>;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {

            var n = ri;
            var A = Enumerate(3, x => sc.Integer(n));
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < n; j++)
                    A[i][j]--;

            var ok = true;
            var P = Enumerate(2, x => new List<int>());
            var par = new int[2];
            for (int i = 0; i < n; i++)
            {
                var a = new int[] { A[0][i], A[1][i], A[2][i] };
                Array.Sort(a);
                if (A[1][i] != a[1]) ok = false;
                if (a[1] - a[0] != 1) ok = false;
                if (a[2] - a[1] != 1) ok = false;

                var x = a[0] / 3;
                if (Math.Abs(i - x) % 2 == 1) ok = false;
                if (a[0] == A[0][i])
                {
                    if (Math.Abs(i - x) % 4 == 2)
                    {
                        Debug.WriteLine(i);
                        par[i % 2] ^= 1;
                    }
                }
                else
                {
                    if (Math.Abs(i - x) % 4 == 0)
                    {
                        Debug.WriteLine(i);
                        par[i % 2] ^= 1;
                    }
                }
                P[i % 2].Add(a[0]);
            }
            var inv = new int[2];
            for (int k = 0; k < 2; k++)
                f(P[k], 0, P[k].Count, ref inv[k]);
            Debug.WriteLine(P[0].AsJoinedString());
            Debug.WriteLine(P[1].AsJoinedString());
            Debug.WriteLine(par.AsJoinedString());
            Debug.WriteLine(inv.AsJoinedString());
            Debug.WriteLine("");

            for (int k = 0; k < 2; k++)
                if (par[k] != inv[k ^ 1]) ok = false;
            if (ok) IO.Printer.Out.WriteLine("Yes");
            else IO.Printer.Out.WriteLine("No");
        }

        List<int> f(List<int> a, int l, int r, ref int inv)
        {
            if (r - l == 1) return new List<int>() { a[l] };
            var m = (l + r) / 2;
            var L = f(a, l, m, ref inv);
            var R = f(a, m, r, ref inv);
            var ret = new List<int>();
            l = 0;
            r = 0;
            while (l < L.Count || r < R.Count)
            {
                if (r < R.Count && (l == L.Count || L[l] > R[r]))
                    ret.Add(R[r++]);
                else
                {
                    inv ^= (~R.BinarySearch(L[l])) % 2;
                    ret.Add(L[l++]);
                }
            }
            return ret;
        }



        //*
        int ri => sc.Integer();
        long rl => sc.Long();
        double rd => sc.Double();
        string rs => sc.Scan();
        char rc => sc.Char();

        [System.Diagnostics.Conditional("DEBUG")]
        void put(params object[] a) => Debug.WriteLine(string.Join(" ", a));

        //*/
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());

        static T[] Enumerate<T>(int n, Func<int, T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f(i);
            return a;
        }
        static void Swap<T>(ref T a, ref T b)
        {
            var tmp = a;
            a = b;
            b = tmp;
        }
    }
}

#region main

static class Ex
{
    public static string AsString(this IEnumerable<char> ie)
    {
        return new string(ie.ToArray());
    }

    public static string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ")
    {
        return string.Join(st, ie);
    }

    public static void Main()
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
        static Printer()
        {
            Out = new Printer(Console.OpenStandardOutput()) { AutoFlush = false };
        }

        public static Printer Out { get; set; }

        public override IFormatProvider FormatProvider
        {
            get { return CultureInfo.InvariantCulture; }
        }

        public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true))
        {
        }

        public Printer(Stream stream, Encoding encoding) : base(stream, encoding)
        {
        }

        public void Write<T>(string format, T[] source)
        {
            base.Write(format, source.OfType<object>().ToArray());
        }

        public void WriteLine<T>(string format, T[] source)
        {
            base.WriteLine(format, source.OfType<object>().ToArray());
        }
    }

    public class StreamScanner
    {
        public StreamScanner(Stream stream)
        {
            str = stream;
        }

        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof;

        public bool IsEndOfStream
        {
            get { return isEof; }
        }

        private byte read()
        {
            if (isEof) return 0;
            if (ptr < len) return buf[ptr++];
            ptr = 0;
            if ((len = str.Read(buf, 0, 1024)) > 0) return buf[ptr++];
            isEof = true;
            return 0;
        }

        public char Char()
        {
            byte b;
            do b = read(); while ((b < 33 || 126 < b) && !isEof);
            return (char)b;
        }

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
            long ret = 0;
            byte b;
            var ng = false;
            do b = read(); while (b != 0 && b != '-' && (b < '0' || '9' < b));
            if (b == 0) return long.MinValue;
            if (b == '-')
            {
                ng = true;
                b = read();
            }
            for (; ; b = read())
            {
                if (b < '0' || '9' < b)
                    return ng ? -ret : ret;
                ret = ret * 10 + b - '0';
            }
        }

        public int Integer()
        {
            return (isEof) ? int.MinValue : (int)Long();
        }

        public double Double()
        {
            var s = Scan();
            return s != "" ? double.Parse(s, CultureInfo.InvariantCulture) : double.NaN;
        }

        static T[] enumerate<T>(int n, Func<T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f();
            return a;
        }

        public char[] Char(int n)
        {
            return enumerate(n, Char);
        }

        public string[] Scan(int n)
        {
            return enumerate(n, Scan);
        }

        public double[] Double(int n)
        {
            return enumerate(n, Double);
        }

        public int[] Integer(int n)
        {
            return enumerate(n, Integer);
        }

        public long[] Long(int n)
        {
            return enumerate(n, Long);
        }
    }
}

#endregion