using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using Number = System.Int64;
namespace Program
{
    public class Solver
    {

        public void Solve()
        {
            var n = sc.Integer();
            var k = sc.Integer();
            var deq = new Deque<int>();
            for (int i = 0; i < n; i++)
                deq.PushBack(sc.Char() - 'A');
            var flip = 0;
            k = Math.Min(k, 2 * n + (k % (4 * n)));
            for (int T = 0; T < k; T++)
            {
                var x = deq[0] ^ flip;
                if (x == 0)
                    deq[0] ^= 1;
                else
                {
                    deq.PopFront();
                    flip ^= 1;
                    deq.PushBack(flip);
                }
            }
            var c = new char[n];
            for (int i = 0; i < n; i++)
                c[i] = (char)((deq[i] ^ flip) + 'A');
            IO.Printer.Out.WriteLine(c.AsString());

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
#region Deque<T>

public class Deque<T>
{
    T[] buf;
    int offset;
    int count;
    int capacity;
    public int Count { get { return count; } }
    public Deque(int cap) { buf = new T[capacity = cap]; }
    public Deque() { buf = new T[capacity = 8]; }
    public T this[int index]
    {
        get { return buf[getIndex(index)]; }
        set { buf[getIndex(index)] = value; }
    }
    private int getIndex(int index)
    {
        if (index >= capacity)
            throw new IndexOutOfRangeException("out of range");
        var ret = index + offset;
        if (ret >= capacity)
            ret -= capacity;
        return ret;
    }
    public void PushFront(T item)
    {
        if (count == capacity) Extend();
        if (--offset < 0) offset += buf.Length;
        buf[offset] = item;
        ++count;
    }
    public T PopFront()
    {
        if (count == 0)
            throw new InvalidOperationException("collection is empty");
        --count;
        var ret = buf[offset++];
        if (offset >= capacity) offset -= capacity;
        return ret;
    }
    public void PushBack(T item)
    {
        if (count == capacity) Extend();
        var id = count++ + offset;
        if (id >= capacity) id -= capacity;
        buf[id] = item;
    }
    public T PopBack()
    {
        if (count == 0)
            throw new InvalidOperationException("collection is empty");
        return buf[getIndex(--count)];
    }
    public void Insert(T item, int index)
    {
        if (index > count) throw new IndexOutOfRangeException();
        this.PushFront(item);
        for (int i = 0; i < index; i++)
            this[i] = this[i + 1];
        this[index] = item;
    }
    public T RemoveAt(int index)
    {
        if (index < 0 || index >= count) throw new IndexOutOfRangeException();
        var ret = this[index];
        for (int i = index; i > 0; i--)
            this[i] = this[i - 1];
        this.PopFront();
        return ret;
    }
    private void Extend()
    {
        T[] newBuffer = new T[capacity << 1];
        if (offset > capacity - count)
        {
            var len = buf.Length - offset;
            Array.Copy(buf, offset, newBuffer, 0, len);
            Array.Copy(buf, 0, newBuffer, len, count - len);
        }
        else Array.Copy(buf, offset, newBuffer, 0, count);
        buf = newBuffer;
        offset = 0;
        capacity <<= 1;
    }
    public T[] Items
    {
        get
        {
            var a = new T[count];
            for (int i = 0; i < count; i++)
                a[i] = this[i];
            return a;
        }
    }
}

#endregion