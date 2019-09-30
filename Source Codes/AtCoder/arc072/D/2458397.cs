using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
//using System.Numerics;
using static System.Math;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var n = ri;
            var L = rl;
            var deq = new Deque<X>();
            double sum = 0;
            for (int _ = 0; _ < n; _++)
            {
                var x = new X(ri, ri);
                sum += x.temp * x.vol;
                if (deq.Count == 0) { deq.PushBack(x); }
                else
                {
                    //???????
                    {
                        var v = x.vol;
                        while (v > 0)
                        {
                            var p = deq.PopFront(); sum -= p.temp * p.vol;
                            var mi = Math.Min(v, p.vol);
                            p.vol -= mi; v -= mi;
                            if (p.vol > 0)
                            {
                                deq.PushFront(p); sum += p.temp * p.vol;
                            }
                        }
                    }
                    while (deq.Count > 0 && deq[deq.Count - 1].temp >= x.temp)
                    {
                        var p = deq.PopBack();
                        var nv = x.vol + p.vol;
                        x = new X((x.temp * x.vol + p.temp * p.vol) / nv, nv);
                    }
                    deq.PushBack(x);

                }
                Console.WriteLine("{0:0.000000000000}", 1.0 * sum / L);
            }
        }

        class X {
            public double temp, vol;
            public X(double T, double V) {
                this.temp = T; vol = V;
            }
        }
        const long INF = 5L << 60;
        static int[] dx = { -1, 0, 1, 0 };
        static int[] dy = { 0, 1, 0, -1 };
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


#region Deque<T>

public class Deque<T> {
    T[] buf;
    int offset, cnt;
    public int Count { get { return cnt; } }
    public Deque(int capacity) { buf = new T[capacity]; }
    public Deque() : this(8) { }
    public T this[int index] {
        get { return buf[getIndex(index)]; }
        set { buf[getIndex(index)] = value; }
    }
    int getIndex(int index) {
        if (index >= cnt) throw new ArgumentOutOfRangeException("out of range");
        var ret = index + offset;
        if (ret >= buf.Length)
            ret -= buf.Length;
        return ret;
    }
    public void PushFront(T item) {
        if (cnt == buf.Length) extend();
        if (--offset < 0) offset += buf.Length;
        buf[offset] = item;
        ++cnt;
    }
    public T PopFront() {
        if (cnt == 0) throw new ArgumentOutOfRangeException("collection is empty");
        --cnt;
        var ret = buf[offset++];
        if (offset >= buf.Length) offset -= buf.Length;
        return ret;
    }
    public void PushBack(T item) {
        if (cnt == buf.Length) extend();
        var id = cnt++ + offset;
        if (id >= buf.Length) id -= buf.Length;
        buf[id] = item;
    }
    public T PopBack() {
        if (cnt == 0)
            throw new ArgumentOutOfRangeException("collection is empty");
        var ret = buf[getIndex(cnt - 1)]; cnt--;
        return ret;
    }
    public void Insert(T item, int index) {
        if (index > cnt) throw new ArgumentOutOfRangeException();
        PushFront(item);
        for (int i = 0; i < index; i++)
            this[i] = this[i + 1];
        this[index] = item;
    }
    public T RemoveAt(int index) {
        if (index < 0 || index >= cnt) throw new ArgumentOutOfRangeException();
        var ret = this[index];
        for (int i = index; i > 0; i--)
            this[i] = this[i - 1];
        PopFront();
        return ret;
    }
    public bool Any() { return cnt > 0; }
    void extend() {
        T[] next = new T[buf.Length * 2];
        if (offset > buf.Length - cnt)
        {
            var len = buf.Length - offset;
            Array.Copy(buf, offset, next, 0, len);
            Array.Copy(buf, 0, next, len, cnt - len);
        }
        else Array.Copy(buf, offset, next, 0, cnt);
        buf = next;
        offset = 0;
    }
    public T[] Items {
        get {
            var a = new T[cnt];
            for (int i = 0; i < cnt; i++)
                a[i] = this[i];
            return a;
        }
    }
}

#endregion