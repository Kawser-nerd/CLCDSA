using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

namespace NotFounds
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var sw = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
            Console.SetOut(sw);
            new Program().Solve(new MyInputStream(Console.In, ' '));
            Console.Out.Flush();
        }

        public void Solve(MyInputStream cin)
        {
            var R = cin.ReadInt();
            var C = cin.ReadInt();
            var K = cin.ReadInt();
            var N = cin.ReadInt();

            var r = new int[R];
            var c = new int[C];
            var candy = new List<Pair<int>>();
            for (int i = 0; i < N; i++)
            {
                var y = cin.ReadInt() - 1;
                var x = cin.ReadInt() - 1;
                r[y]++;
                c[x]++;
                candy.Add(new Pair<int>(x, y));
            }

            var  _r = new int[N + 1];
            var  _c = new int[N + 1];

            foreach (var i in r)
                _r[i]++;
            foreach (var i in c)
                _c[i]++;

            var ret = 0L;
            for (int i = 0; i <= K; i++)
                ret += (long)_r[i] * (long)_c[K - i];

            for (int i = 0; i < N; ++i)
            {
                var x = candy[i].First;
                var y = candy[i].Second;
                if (c[x] + r[y] == K) ret--;
                if (c[x] + r[y] == K + 1) ret++;
            }

            WriteLine(ret);
        }
    }

    public class Pair<T>
    {
        public T First { get; set; }
        public T Second { get; set; }
        public Pair(T f, T s) { First = f; Second = s; }
        public override string ToString() { return "(" + First + ", " + Second + ")"; }
        public override int GetHashCode() { return First.GetHashCode() << 16 ^ Second.GetHashCode(); }
        public override bool Equals(object obj)
        {
            if (ReferenceEquals(this, obj)) return true;
            else if (obj == null) return false;
            var tmp = obj as Pair<T>;
            return (object)tmp != null && First.Equals(tmp.First) && Second.Equals(tmp.Second);
        }
    }

    public class HashMap<K, V> : Dictionary<K, V>
    {
        public HashMap() : base() { }
        public HashMap(int cap) : base(cap) { }
        public HashMap(IDictionary<K, V> dictionary) : base(dictionary) { }
        new public V this[K i]
        {
            get
            {
                V v;
                return TryGetValue(i, out v) ? v : base[i] = default(V);
            }
            set { base[i] = value; }
        }
    }

    public class MyInputStream
    {
        private readonly System.IO.TextReader _stream;
        private char separator = ' ';
        private Queue<string> inputStream;
        public MyInputStream(System.IO.TextReader s, char separator = ' ')
        {
            this.separator = separator;
            this._stream = s;
            inputStream = new Queue<string>();
        }
        public string Read()
        {
            if (inputStream.Count != 0) return inputStream.Dequeue();
            string[] tmp = _stream.ReadLine().Split(separator);
            for (int i = 0; i < tmp.Length; ++i)
                inputStream.Enqueue(tmp[i]);
            return inputStream.Dequeue();
        }
        public string ReadLine() { return _stream.ReadLine(); }
        public int ReadInt() { return int.Parse(Read()); }
        public long ReadLong() { return long.Parse(Read()); }
        public double ReadDouble() { return double.Parse(Read()); }
        public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read(); return ret;}
        public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt(); return ret;}
        public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong(); return ret;}
    }
}