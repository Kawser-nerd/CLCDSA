using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
//using System.Numerics;
using Number = ModInt;
using static System.Math;
//using static MathEx;
//using P = System.Collections.Generic.KeyValuePair<int, int>;


namespace Program
{
    public class Solver
    {

        public void Solve()
        {
            var mat = init();

            var h = ri - 1;
            var w = rl;
            var q = ri;
            var s = new int[q];
            var t = new long[q];
            var xs = new List<long>() { 0, w };
            //for (int i = 0; i <= w; i++) xs.Add(i);
            for (int i = 0; i < q; i++)
            {
                s[i] = ri - 1;
                t[i] = rl - 1;
                xs.Add(t[i]);
                xs.Add(t[i] + 1);
            }
            xs = xs.Distinct().ToList(); xs.Sort();
            var n = xs.Count;
            var seg = new SegmentTree<Matrix, Data>(n - 1);
            for (int i = 0; i < n - 1; i++)
            {

                var cnt = xs[i + 1] - xs[i];
                var m = Matrix.Pow(mat[h, 0], cnt);
                seg.Update(i, m);
            }
            var flag = new int[n];
            for (int i = 0; i < q; i++)
            {
                var pos = xs.BinarySearch(t[i]);
                flag[pos] ^= 1 << s[i];
                seg.Update(pos, mat[h, flag[pos]]);
              
                var m = seg.Query(0, n - 1);
                ModInt ans = 0;
                if (h == 1)
                    ans += m[0, 3] + m[1, 3] + m[2, 3] + m[3, 3];
                else ans += m[0, 1] + m[1, 1];
                IO.Printer.Out.WriteLine(ans);
            }

        }
        Matrix[,] init()
        {
            var ret = new Matrix[2, 4];
            {
                var a = ret[0, 0] = new Matrix(4, 4);
                a[0, 0] = a[0, 1] = a[1, 0] = 1;
            }
            {
                var a = ret[0, 1] = new Matrix(4, 4);
                a[1, 0] = a[1, 1] = 1;
            }
            {
                var a = ret[1, 0] = new Matrix(4, 4);
                a[0, 0] = a[0, 1] = a[0, 2] = a[0, 3] = 1;
                a[1, 0] = a[1, 2] = 1;
                a[2, 0] = a[2, 1] = 1;
                a[3, 0] = 2;
                a[3, 1] = a[3, 2] = a[3, 3] = 1;
            }
            {
                var a = ret[1, 1] = new Matrix(4, 4);
                a[1, 0] = a[1, 1] = a[1, 2] = a[1, 3] = 1;
                a[3, 0] = a[3, 1] = 1;
            }
            {
                var a = ret[1, 2] = new Matrix(4, 4);
                a[2, 0] = a[2, 1] = a[2, 2] = a[2, 3] = 1;
                a[3, 0] = a[3, 2] = 1;
            }
            {
                var a = ret[1, 3] = new Matrix(4, 4);
                a[3, 0] = a[3, 1] = a[3, 2] = a[3, 3] = 1;
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
#region Matrix
public class Matrix
{
    int row, col;
    public Number[] mat;
    public Number this[int r, int c]
    {
        get { return mat[r * col + c]; }
        set { mat[r * col + c] = value; }
    }
    public Matrix(int r, int c)
    {
        row = r; col = c;
        mat = new Number[row * col];
    }
    public static Matrix operator +(Matrix l, Matrix r)
    {
        check(l, r);
        var ret = new Matrix(l.row, l.col);
        for (int i = 0; i < l.row; i++)
            for (int j = 0; j < l.col; j++)
                ret.mat[i * ret.col + j] = l.mat[i * l.col + j] + r.mat[i * r.col + j];
        return ret;

    }
    public static Matrix operator *(Matrix l, Matrix r)
    {
        checkMul(l, r);
        var ret = new Matrix(l.row, r.col);
        for (int i = 0; i < l.row; i++)
            for (int k = 0; k < l.col; k++)
                for (int j = 0; j < r.col; j++)
                    ret.mat[i * r.col + j] = (ret.mat[i * r.col + j] + l.mat[i * l.col + k] * r.mat[k * r.col + j]);
        return ret;
    }
    public static Matrix Pow(Matrix m, long n)
    {
        var ret = new Matrix(m.row, m.col);
        for (int i = 0; i < m.row; i++)
            ret.mat[i * m.col + i] = 1;
        for (; n > 0; m *= m, n >>= 1)
            if ((n & 1) == 1)
                ret = ret * m;
        return ret;

    }
    public static Matrix[] PowTable(Matrix m, int k)
    {
        var ret = new Matrix[k];
        ret[0] = m;
        for (int i = 1; i < k; i++)
            ret[i] = ret[i - 1] * ret[i - 1];
        return ret;
    }
    public static Matrix PowWithTable(Matrix m, long n, Matrix[] table)
    {
        var ret = new Matrix(m.row, m.col);
        for (int i = 0; i < m.row; i++)
            ret.mat[i * m.col + i] = 1;
        for (int i = 0; i < table.Length; i++)
        {
            if ((n & 1) == 1) ret = ret * table[i];
        }
        return ret;
    }
    public static Matrix Trans(Matrix m)
    {
        var ret = new Matrix(m.col, m.row);
        for (int i = 0; i < m.row; i++)
            for (int j = 0; j < m.col; j++)
                ret.mat[j * m.col + i] = m.mat[i * m.col + j];
        return ret;
    }
    [System.Diagnostics.Conditional("DEBUG")]
    static private void check(Matrix a, Matrix b)
    {
        if (a.row != b.row || a.col != b.col)
            throw new Exception("row and col have to be same.");

    }
    [System.Diagnostics.Conditional("DEBUG")]
    static private void checkMul(Matrix a, Matrix b)
    {
        if (a.col != b.row)
            throw new Exception("row and col have to be same.");
    }
    public Number[][] Items
    {
        get
        {
            var a = new Number[row][];
            for (int i = 0; i < row; i++)
            {
                a[i] = new Number[col];
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
}
#endregion

#region ModInt
public struct ModInt
{
    public const long Mod = (long)1e9 + 7;
    public long num;
    public ModInt(long n) { num = n; }
    public override string ToString() { return num.ToString(); }
    public static ModInt operator +(ModInt l, ModInt r) { l.num += r.num; if (l.num >= Mod) l.num -= Mod; return l; }
    public static ModInt operator -(ModInt l, ModInt r) { l.num -= r.num; if (l.num < 0) l.num += Mod; return l; }
    public static ModInt operator *(ModInt l, ModInt r) { return new ModInt(l.num * r.num % Mod); }
    public static implicit operator ModInt(long n) { n %= Mod; if (n < 0) n += Mod; return new ModInt(n); }
    public static ModInt Pow(ModInt v, long k)
    {
        k %= Mod - 1;
        ModInt ret = 1;
        var n = k;
        for (; n > 0; n >>= 1, v *= v)
            if ((n & 1) == 1) ret = ret * v;
        return ret;
    }
    public static ModInt Inverse(ModInt v)
    {
        return Pow(v, Mod - 2);
    }
}
#endregion

public struct Data: IData<Matrix>
{
    static Matrix E;
    static Data()
    {
        E = new Matrix(4, 4);
        for (int i = 0; i < 4; i++)
            E[i, i] = 1;
    }
    public Matrix Identity
    {
        get
        {
            return E;
        }
    }

    public Matrix Merge(Matrix l, Matrix r)
    {
        return l * r;
    }
}




#region Segment Tree Node
public interface IData<T>
{
    T Merge(T l, T r);
    T Identity { get; }
}
#endregion
#region Segment Tree

public class SegmentTree<T, U>
   where U : struct, IData<T>
{
    int sz;
    int n;
    T[] data;
    U op;
    public SegmentTree(int size)
    {
        sz = size;
        n = 1;
        while (n < size) n *= 2;
        data = new T[n * 2];
        for (int i = 0; i < data.Length; i++)
            data[i] = op.Identity;
    }
    public SegmentTree(T[] a)
    {
        sz = a.Length;
        n = 1;
        while (n < sz) n *= 2;
        data = new T[n * 2];
        for (int i = 0; i < a.Length; i++)
            data[i + n] = a[i];
        for (int i = n - 1; i >= 0; i--)
            data[i] = op.Merge(data[i * 2], data[i * 2 + 1]);
    }
    public void Update(int k, T v)
    {
        k += n;
        data[k] = v;
        for (k = k / 2; k > 0; k /= 2)
        {
            data[k] = op.Merge(data[k * 2], data[k * 2 + 1]);
        }

    }
    public T Query(int a, int b) { return query(a, b, 1, 0, n); }
    private T query(int a, int b, int k, int l, int r)
    {
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
    public T[] Items
    {
        get
        {
            var ret = new T[sz];
            for (int i = 0; i < sz; i++)
                ret[i] = data[i + n];
            return ret;
        }
    }

}
#endregion