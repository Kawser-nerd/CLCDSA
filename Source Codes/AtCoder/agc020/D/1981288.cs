using System;
using System.Linq;
using System.Collections.Generic;
using System.Numerics;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using Number = System.Int64;
using static System.Math;
namespace Program {
    public class Solver {
        Random rnd = new Random();
        public void Solve() {
            var Q = ri;
            for (int _ = 0; _ < Q; _++) {
                long a = ri; long b = ri;
                var c = ri - 1; var d = ri;
                var k = (Max(a, b) + Min(a, b)) / (Min(a, b) + 1);
                //s = ([A,k][B])*m + [A*x] + [B*y]+ ([A][B,k])*m'
                var l = 0L; var r = a + 1;
                while (r - l > 1) {
                    var m = (l + r) / 2;
                    if (f(a, b, k, m)) l = m;
                    else r = m;
                }
                var len = l + Max(0, (l - 1) / k);
                for (int i = c; i < d; i++) {
                    if (i < len) {
                        if (i % (k + 1) != k) Console.Write("A");
                        else Console.Write("B");
                    }
                    else {
                        var bi = a + b - 1 - i;
                        if (bi % (k + 1) != k) Console.Write("B");
                        else Console.Write("A");
                    }

                }
                Console.WriteLine();
            }

        }
        bool f(long a, long b, long k, long m) {
            b -= Max(0, (m - 1) / k);
            a -= m;
            return b <= (a + 1) * k;
        }

        const long INF = 1L << 60;
        //int[] dx = { -1, 0, 1, 0 };
        //int[] dy = { 0, 1, 0, -1 };

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
        return string.Join(st, ie.Select(x => x.ToString()).ToArray());
        //return string.Join(st, ie);
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
            if (ptr >= len) {
                ptr = 0;
                if ((len = str.Read(buf, 0, 1024)) <= 0) {
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

#region Bitset
public struct BitSet {
    const int B = 64;
    const ulong ALL = ulong.MaxValue;
    //public const int SIZE = 1000001;
    //const int size = SIZE / B + 2;
    static public readonly ulong[] mask = new ulong[65];
    static public readonly ulong[] revmask = new ulong[65];
    static BitSet() {
        mask[0] = 0;
        for (int i = 0; i < 64; i++)
            mask[i + 1] = (mask[i] << 1) | 1ul;
        for (int i = 0; i < 65; i++)
            revmask[i] = ~mask[i];
    }
    public ulong[] bits;
    int n;
    public BitSet(int N) : this() {
        n = N;
        bits = new ulong[n / B + 2];
    }
    public int[] Items {
        get {
            var ret = new int[n];
            for (int i = 0; i < n; i++) if (this[i]) ret[i] = 1;
            return ret;
        }
    }
    public bool this[int index] {
        get { return (bits[index / B] >> (index % B) & 1) == 1; }
        set {
            if (value)
                bits[index / B] |= 1ul << (index % B);
            else bits[index / B] &= ~(1ul << (index % B));
        }
    }

    void align(ref int p, ref int q, ref int len, int max, int max2) {
        if (p < 0) { q += Math.Abs(q); len -= Math.Abs(p); p = 0; }
        var xr = Math.Min(max, p + len);
        len = xr - p;

        if (q < 0) { p += Math.Abs(q); len -= Math.Abs(q); q = 0; }
        var yr = Math.Min(max2, q + len);
        len = yr - q;



    }

    /// <summary>
    /// a->b. a[p,p+len)->b[q,q+len)
    /// </summary>
    public void XorTo(BitSet b, int p, int q, int len)//xor b[l,l+len)^=a[r,r+len)
    {
        align(ref p, ref q, ref len, n, b.n);
        var lx = p / B;
        var ly = p % B;
        var rx = (p + len) / B;
        var ry = (p + len) % B;

        var d = p - q;
        var dx = d / B;
        var dy = d % B;
        if (dy < 0) { dy += B; dx--; }

        if (p > q) {
            if (lx == rx) {
                if (dy > 0 && lx - dx - 1 >= 0) b.bits[lx - dx - 1] ^= (bits[lx] & (mask[ry] & revmask[ly])) << (B - dy);
                b.bits[lx - dx] ^= (bits[lx] & (mask[ry] & revmask[ly])) >> dy;
            }
            else {
                if (dy > 0 && lx - dx - 1 >= 0) b.bits[lx - dx - 1] ^= (bits[lx] & revmask[ly]) << (B - dy);
                b.bits[lx - dx] ^= (bits[lx] & revmask[ly]) >> dy;
                for (var i = lx + 1; i < rx; i++) {
                    if (dy > 0) b.bits[i - dx - 1] ^= bits[i] << (B - dy);
                    b.bits[i - dx] ^= bits[i] >> dy;
                }
                if (dy > 0) b.bits[rx - dx - 1] ^= (bits[rx] & (mask[ry])) << (B - dy);
                b.bits[rx - dx] ^= (bits[rx] & (mask[ry])) >> dy;
            }
        }
        else {
            if (lx == rx) {
                b.bits[lx - dx] ^= (bits[lx] & (mask[ry] & revmask[ly])) >> dy;
                if (dy > 0) b.bits[lx - dx - 1] ^= (bits[lx] & (mask[ry] & revmask[ly])) << (B - dy);
            }
            else {
                b.bits[rx - dx] ^= (bits[rx] & (mask[ry])) >> dy;
                if (dy > 0) b.bits[rx - dx - 1] ^= (bits[rx] & (mask[ry])) << (B - dy);
                for (var i = rx - 1; i > lx; i--) {
                    b.bits[i - dx] ^= bits[i] >> dy;
                    if (dy > 0) b.bits[i - dx - 1] ^= bits[i] << (B - dy);
                }
                b.bits[lx - dx] ^= (bits[lx] & revmask[ly]) >> dy;
                if (dy > 0 && lx - dx - 1 >= 0) b.bits[lx - dx - 1] ^= (bits[lx] & revmask[ly]) << (B - dy);
            }
        }
    }
    /// <summary>
    /// a->b. a[p,p+len)->b[q,q+len)
    /// </summary>
    public void AndTo(BitSet b, int p, int q, int len)//and b[l,l+len)&=a[r,r+len)
    {
        align(ref p, ref q, ref len, n, b.n);
        var lx = p / B;
        var ly = p % B;
        var rx = (p + len) / B;
        var ry = (p + len) % B;

        var d = p - q;
        var dx = d / B;
        var dy = d % B;
        if (dy < 0) { dy += B; dx--; }

        if (p > q) {
            if (lx == rx) {
                if (dy > 0 && lx - dx - 1 >= 0) b.bits[lx - dx - 1] &= (bits[lx] & (mask[ry] & revmask[ly])) << (B - dy);
                b.bits[lx - dx] &= (bits[lx] & (mask[ry] & revmask[ly])) >> dy;
            }
            else {
                if (dy > 0 && lx - dx - 1 >= 0) b.bits[lx - dx - 1] &= (bits[lx] & revmask[ly]) << (B - dy);
                b.bits[lx - dx] &= (bits[lx] & revmask[ly]) >> dy;
                for (var i = lx + 1; i < rx; i++) {
                    if (dy > 0) b.bits[i - dx - 1] &= bits[i] << (B - dy);
                    b.bits[i - dx] &= bits[i] >> dy;
                }
                if (dy > 0) b.bits[rx - dx - 1] &= (bits[rx] & (mask[ry])) << (B - dy);
                b.bits[rx - dx] &= (bits[rx] & (mask[ry])) >> dy;
            }
        }
        else {
            if (lx == rx) {
                b.bits[lx - dx] &= (bits[lx] & (mask[ry] & revmask[ly])) >> dy;
                if (dy > 0) b.bits[lx - dx - 1] &= (bits[lx] & (mask[ry] & revmask[ly])) << (B - dy);
            }
            else {
                b.bits[rx - dx] &= (bits[rx] & (mask[ry])) >> dy;
                if (dy > 0) b.bits[rx - dx - 1] &= (bits[rx] & (mask[ry])) << (B - dy);
                for (var i = rx - 1; i > lx; i--) {
                    b.bits[i - dx] &= bits[i] >> dy;
                    if (dy > 0) b.bits[i - dx - 1] ^= bits[i] << (B - dy);
                }
                b.bits[lx - dx] &= (bits[lx] & revmask[ly]) >> dy;
                if (dy > 0 && lx - dx - 1 >= 0) b.bits[lx - dx - 1] &= (bits[lx] & revmask[ly]) << (B - dy);
            }
        }
    }
    /// <summary>
    /// a->b. a[p,p+len)->b[q,q+len)
    /// </summary>
    public void OrTo(BitSet b, int p, int q, int len)//and b[l,l+len)&=a[r,r+len)
    {
        align(ref p, ref q, ref len, n, b.n);
        var lx = p / B;
        var ly = p % B;
        var rx = (p + len) / B;
        var ry = (p + len) % B;

        var d = p - q;
        var dx = d / B;
        var dy = d % B;
        if (dy < 0) { dy += B; dx--; }

        if (p > q) {
            if (lx == rx) {
                if (dy > 0 && lx - dx - 1 >= 0) b.bits[lx - dx - 1] |= (bits[lx] & (mask[ry] & revmask[ly])) << (B - dy);
                b.bits[lx - dx] |= (bits[lx] & (mask[ry] & revmask[ly])) >> dy;
            }
            else {
                if (dy > 0 && lx - dx - 1 >= 0) b.bits[lx - dx - 1] |= (bits[lx] & revmask[ly]) << (B - dy);
                b.bits[lx - dx] |= (bits[lx] & revmask[ly]) >> dy;
                for (var i = lx + 1; i < rx; i++) {
                    if (dy > 0) b.bits[i - dx - 1] |= bits[i] << (B - dy);
                    b.bits[i - dx] |= bits[i] >> dy;
                }
                if (dy > 0) b.bits[rx - dx - 1] |= (bits[rx] & (mask[ry])) << (B - dy);
                b.bits[rx - dx] |= (bits[rx] & (mask[ry])) >> dy;
            }
        }
        else {
            if (lx == rx) {
                b.bits[lx - dx] |= (bits[lx] & (mask[ry] & revmask[ly])) >> dy;
                if (dy > 0) b.bits[lx - dx - 1] |= (bits[lx] & (mask[ry] & revmask[ly])) << (B - dy);
            }
            else {
                b.bits[rx - dx] |= (bits[rx] & (mask[ry])) >> dy;
                if (dy > 0) b.bits[rx - dx - 1] |= (bits[rx] & (mask[ry])) << (B - dy);
                for (var i = rx - 1; i > lx; i--) {
                    b.bits[i - dx] |= bits[i] >> dy;
                    if (dy > 0) b.bits[i - dx - 1] |= bits[i] << (B - dy);
                }
                b.bits[lx - dx] |= (bits[lx] & revmask[ly]) >> dy;
                if (dy > 0 && lx - dx - 1 >= 0) b.bits[lx - dx - 1] |= (bits[lx] & revmask[ly]) << (B - dy);
            }
        }
    }
    static public bool HasIntersect(BitSet a, BitSet b) {
        var min = Math.Min(a.bits.Length, b.bits.Length);
        for (int i = 0; i < min; i++)
            if ((a.bits[i] & b.bits[i]) != 0) return true;
        return false;
    }
}
#endregion