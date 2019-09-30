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
                new Program().Solve(new ConsoleInput(Console.In, ' '));
                Console.Out.Flush();
            }
     
            public void Solve(ConsoleInput cin)
            {
                checked
                {
	        var H = cin.ReadInt;
	        var W = cin.ReadInt;
	        var D = cin.ReadInt;
	        var map = new Pair[H * W + 5];
	        for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
		    map[cin.ReadInt] = new Pair(i, j);
	        
	        var d = new int[H * W + 5];
	        for (int i = D + 1; i <= H * W; ++i)
		d[i] = d[i - D] + Math.Abs(map[i].X - map[i - D].X) + Math.Abs(map[i].Y - map[i - D].Y);
	      
	        var Q = cin.ReadInt;
	        for (int i = 0; i < Q; ++i)
	        {
	        	var l = cin.ReadInt;
	        	var r = cin.ReadInt;
	        	WriteLine(d[r] - d[l]);
	        }
                }
            }
        }
     
        public class Pair
        {
        	public int X { get; set; }
        	public int Y { get; set; }
        	public Pair(int x, int y) { X = x; Y = y; }
        	public override string ToString() { return $"({X}, {Y})"; }
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
     
        public class ConsoleInput
        {
            private readonly System.IO.TextReader _stream;
            private char _separator = ' ';
            private Queue<string> inputStream;
            public ConsoleInput(System.IO.TextReader stream, char separator = ' ')
            {
                this._separator = separator;
                this._stream = stream;
                inputStream = new Queue<string>();
            }
            public string Read
            {
                get
                {
                    if (inputStream.Count != 0) return inputStream.Dequeue();
                    string[] tmp = _stream.ReadLine().Split(_separator);
                    for (int i = 0; i < tmp.Length; ++i)
                        inputStream.Enqueue(tmp[i]);
                    return inputStream.Dequeue();
                }
            }
            public string ReadLine { get { return _stream.ReadLine(); }}
            public int ReadInt { get { return int.Parse(Read); }}
            public long ReadLong { get { return long.Parse(Read); }}
            public double ReadDouble { get { return double.Parse(Read); }}
            public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read; return ret;}
            public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt; return ret;}
            public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong; return ret;}
            public void ReadIntArrays(long N, out int[] A, out int[] B) { A = new int[N]; B = new int[N]; for (long i = 0; i < N; ++i) { A[i] = ReadInt; B[i] = ReadInt; }}
            public void ReadIntArrays(long N, out int[] A, out int[] B, out int[] C) { A = new int[N]; B = new int[N]; C = new int[N]; for (long i = 0; i < N; ++i) { A[i] = ReadInt; B[i] = ReadInt; C[i] = ReadInt; }}
            public void ReadLongArrays(long N, out long[] A, out long[] B) { A = new long[N]; B = new long[N]; for (long i = 0; i < N; ++i) { A[i] = ReadLong; B[i] = ReadLong; }}
        }
    }