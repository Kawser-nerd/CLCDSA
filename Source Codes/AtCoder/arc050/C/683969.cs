using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Point = System.Numerics.Complex;
using Number = System.Int64;
namespace Program
{
    //otaku ha saiko~
    public class Solver
    {
        public void Solve()
        {
            var a = sc.Long();
            var b = sc.Long();
            ModInteger.Mod = sc.Integer();
            var mat = new ModMatrix(2, 2);
            mat[0, 0] = 10;
            mat[0, 1] = 1;
            mat[1, 1] = 1;
            var vec = new ModMatrix(2, 1);
            vec[0, 0] = 1;
            vec[0, 1] = 1;

            var gcd = MathEx.GCD(a, b);
            var A = (ModMatrix.Pow(mat, a - 1) * vec)[0, 0];
            mat[0, 0] = ModInteger.Pow(10, gcd);

            var B = (ModMatrix.Pow(mat, b / gcd - 1) * vec)[0, 0];
            IO.Printer.Out.WriteLine(A * B);
            //IO.Printer.Out.WriteLine(A * B * ModInteger.Inverse(GCD));
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
#region gcd,lcm
static public partial class MathEx
{

    static public Number GCD(Number x, Number y)
    {
        byte i = 0;
        while (x != 0 && y != 0)
        {
            if (i == 0)
                y %= x;
            else x %= y;
            i ^= 1;
        }
        return x == 0 ? y : x;
    }
    static public Number LCM(Number x, Number y)
    {
        return (x / GCD(x, y)) * y;
    }

}
#endregion
#region ModNumber
public partial struct ModInteger
{
    public static long Mod = (long)1e9 + 7;
    public long num;
    public ModInteger(long n) : this() { num = n % Mod; if (num < 0) num += Mod; }
    public override string ToString() { return num.ToString(); }
    public static ModInteger operator +(ModInteger l, ModInteger r) { var n = l.num + r.num; if (n >= Mod) n -= Mod; return new ModInteger() { num = n }; }
    public static ModInteger operator -(ModInteger l, ModInteger r) { var n = l.num + Mod - r.num; if (n >= Mod) n -= Mod; return new ModInteger() { num = n }; }
    public static ModInteger operator *(ModInteger l, ModInteger r) { return new ModInteger(l.num * r.num); }
    public static ModInteger operator ^(ModInteger l, long r) { return ModInteger.Pow(l, r); }
    public static implicit operator ModInteger(long n) { return new ModInteger(n); }
    public static ModInteger Pow(ModInteger v, long k)
    {
        ModInteger ret = 1;
        var n = k;
        for (; n > 0; n >>= 1, v *= v)
        {
            if ((n & 1) == 1)
                ret = ret * v;
        }
        return ret;
    }
}
#endregion
#region ModMatrix
public class ModMatrix
{
    int row, col;
    public ModInteger[] mat;
    public ModInteger this[int r, int c]
    {
        get { return mat[r * col + c]; }
        set { mat[r * col + c] = value.num; }
    }
    public ModMatrix(int r, int c)
    {
        row = r; col = c;
        mat = new ModInteger[row * col];
    }
    public static ModMatrix operator +(ModMatrix l, ModMatrix r)
    {
        check(l, r);
        var ret = new ModMatrix(l.row, l.col);
        for (int i = 0; i < l.row; i++)
            for (int j = 0; j < l.col; j++)
            {
                ret.mat[i * ret.col + j] = l.mat[i * l.col + j] + r.mat[i * r.col + j];
            }
        return ret;

    }
    public static ModMatrix operator *(ModMatrix l, ModMatrix r)
    {
        checkMul(l, r);
        var ret = new ModMatrix(l.row, r.col);
        for (int i = 0; i < l.row; i++)
            for (int k = 0; k < l.col; k++)
                for (int j = 0; j < r.col; j++)
                    ret.mat[i * r.col + j] = (ret.mat[i * r.col + j] + l.mat[i * l.col + k] * r.mat[k * r.col + j]);
        return ret;
    }
    public static ModMatrix Pow(ModMatrix m, long n)
    {
        var ret = new ModMatrix(m.row, m.col);
        for (int i = 0; i < m.row; i++)
            ret.mat[i * m.col + i] = 1;
        for (; n > 0; m *= m, n >>= 1)
            if ((n & 1) == 1)
                ret = ret * m;
        return ret;

    }
    public static ModMatrix[] PowTable(ModMatrix m, int k)
    {
        var ret = new ModMatrix[k];
        ret[0] = m;
        for (int i = 1; i < k; i++)
            ret[i] = ret[i - 1] * ret[i - 1];
        return ret;
    }
    public static ModMatrix PowWithTable(ModMatrix m, long n, ModMatrix[] table)
    {
        var ret = new ModMatrix(m.row, m.col);
        for (int i = 0; i < m.row; i++)
            ret.mat[i * m.col + i] = 1;
        for (int i = 0; i < table.Length; i++)
        {
            if ((n & 1) == 1) ret = ret * table[i];
        }
        return ret;
    }
    public static ModMatrix Trans(ModMatrix m)
    {
        var ret = new ModMatrix(m.col, m.row);
        for (int i = 0; i < m.row; i++)
            for (int j = 0; j < m.col; j++)
                ret.mat[j * m.col + i] = m.mat[i * m.col + j];
        return ret;
    }
    [System.Diagnostics.Conditional("DEBUG")]
    static private void check(ModMatrix a, ModMatrix b)
    {
        if (a.row != b.row || a.col != b.col)
            throw new Exception("row and col have to be same.");

    }
    [System.Diagnostics.Conditional("DEBUG")]
    static private void checkMul(ModMatrix a, ModMatrix b)
    {
        if (a.col != b.row)
            throw new Exception("row and col have to be same.");

    }
    public ModInteger[][] Items
    {
        get
        {
            var a = new ModInteger[row][];
            for (int i = 0; i < row; i++)
            {
                a[i] = new ModInteger[col];
                for (int j = 0; j < col; j++)
                    a[i][j] = mat[i * col + j];
            }
            return a;
        }
    }
    public override string ToString()
    {
        return string.Format("{0}*{1}", row, col);
    }
    public void Visualize()
    {
        var items = Items;
        foreach (var x in items)
            System.Diagnostics.Debug.WriteLine(x.AsJoinedString("\t"));
    }
}
#endregion
#region Inverse
public partial struct ModInteger
{
    static public ModInteger Inverse(ModInteger v)
    {
        long p, q;
        ExGCD(v.num, Mod, out p, out q);
        return new ModInteger(p % Mod + Mod);
    }
    static public long ExGCD(long a, long b, out long x, out long y)
    {
        var u = new long[] { a, 1, 0 };
        var v = new long[] { b, 0, 1 };
        while (v[0] != 0)
        {
            var t = u[0] / v[0];
            for (int i = 0; i < 3; i++)
            {
                var tmp = u[i] - t * v[i];
                u[i] = v[i];
                v[i] = tmp;
            }
        }
        x = u[1];
        y = u[2];
        if (u[0] > 0)
            return u[0];
        for (int i = 0; i < 3; i++)
            u[i] = -u[i];
        return u[0];

    }
}
#endregion