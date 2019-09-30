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
            var n=ri;
            var m=ri;
            var dp=new Dictionary<long,int>();
            var G=Enumerate(n,x=>new HashMap<int,List<int>>());
            for(int i=0;i<m;i++)
            {
                var f=ri-1;
                var t=ri-1;
                var c=ri;
                G[f][c].Add(t);
                G[t][c].Add(f);
            }
            var q=new Deque<long>();
            dp[1500000]=0;
            dp[BigMul(n-1,2000000)+1500000]=1000000000;
            q.PushBack(1500000);
            while(q.Count>0)
            {
                var p=q.PopFront();
                var u=(int)(p/2000000);
                var c=(int)(p%2000000);
                var cost=dp[p];
                //Console.WriteLine($"{u} {c} {cost}");

                if(c==1500000)
                {
                    //Console.WriteLine("vertex {0} {1}",p,G[p].Count);
                    foreach(var g in G[u])
                        foreach(var t in g.Value)
                        {
                            var next=BigMul(t,2000000)+g.Key;
                            int ncost;
                            if(dp.TryGetValue(next,out ncost) && ncost<=cost+1){}
                            else
                            {
                                dp[next]=cost+1;
                                q.PushBack(next);
                            }
                        }                            
                }
                else
                {
                    //Console.WriteLine("edge {0}",p);
                    {
                        var next=BigMul(u,2000000)+1500000;
                        int ncost;
                        if(dp.TryGetValue(next,out ncost) && ncost<=cost){}
                        else
                        {
                            dp[next]=cost;
                            q.PushBack(next);
                        }
                    }
                    foreach(var t in G[u][c])
                    {
                        var next=BigMul(t,2000000)+c;
                        int ncost;
                        if(dp.TryGetValue(next,out ncost) && ncost<=cost){}
                        else
                        {
                            dp[next]=cost;
                            q.PushBack(next);
                        }
                    }
                }
            }
            //Console.WriteLine(dp.AsJoinedString());
            var ans=dp[BigMul(n-1,2000000)+1500000];
            if(ans>=1000000000)ans=-1;
            Console.WriteLine(ans);
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

#region HashMap<K,V>
    public class HashMap<K, V>: Dictionary<K, V>
    where V : new()
    {
        public HashMap() : base() { }
        public HashMap(int cap) : base(cap) { }
        new public V this[K i]
        {
            get
            {
                V v;
                return TryGetValue(i, out v) ? v :
                //    base[i] = default(V);
                base[i] = new V();
            }
            set { base[i] = value; }
        }
    }
#endregion

#region Deque<T>

public class Deque<T>
{
    T[] buf;
    int offset, cnt;
    public int Count { get { return cnt; } }
    public Deque(int capacity) { buf = new T[capacity]; }
    public Deque() : this(8) { }
    public T this[int index]
    {
        get { return buf[getIndex(index)]; }
        set { buf[getIndex(index)] = value; }
    }
    int getIndex(int index)
    {
        if (index >= cnt) throw new ArgumentOutOfRangeException("out of range");
        var ret = index + offset;
        if (ret >= buf.Length)
            ret -= buf.Length;
        return ret;
    }
    public void PushFront(T item)
    {
        if (cnt == buf.Length) extend();
        if (--offset < 0) offset += buf.Length;
        buf[offset] = item;
        ++cnt;
    }
    public T PopFront()
    {
        if (cnt == 0) throw new ArgumentOutOfRangeException("collection is empty");
        --cnt;
        var ret = buf[offset++];
        if (offset >= buf.Length) offset -= buf.Length;
        return ret;
    }
    public void PushBack(T item)
    {
        if (cnt == buf.Length) extend();
        var id = cnt++ + offset;
        if (id >= buf.Length) id -= buf.Length;
        buf[id] = item;
    }
    public T PopBack()
    {
        if (cnt == 0)
            throw new ArgumentOutOfRangeException("collection is empty");
        var ret = buf[getIndex(cnt - 1)]; cnt--;
        return ret;
    }
    public void Insert(T item, int index)
    {
        if (index > cnt) throw new ArgumentOutOfRangeException();
        PushFront(item);
        for (int i = 0; i < index; i++)
            this[i] = this[i + 1];
        this[index] = item;
    }
    public T RemoveAt(int index)
    {
        if (index < 0 || index >= cnt) throw new ArgumentOutOfRangeException();
        var ret = this[index];
        for (int i = index; i > 0; i--)
            this[i] = this[i - 1];
        PopFront();
        return ret;
    }
    public bool Any() { return cnt > 0; }
    void extend()
    {
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
    public T[] Items
    {
        get
        {
            var a = new T[cnt];
            for (int i = 0; i < cnt; i++)
                a[i] = this[i];
            return a;
        }
    }
}

#endregion