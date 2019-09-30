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
	        var N = cin.ReadInt;
	        var red = new List<Point>();
	        var blue = new List<Point>();
	        for (int i = 0; i < N; ++i)
		red.Add(new Point(cin.ReadInt, cin.ReadInt));        
		
	        for (int i = 0; i < N; ++i)
		blue.Add(new Point(cin.ReadInt, cin.ReadInt));
		
	        var r = red.OrderByDescending(p => p.y).ThenByDescending(p => p.x).ToArray();
	        var b = blue.OrderBy(p => p.x).ThenBy(p => p.y).ToArray();
	        
	        var used = new bool[N];
	        var cnt = 0;
	        for (int i = 0; i < N; ++i)
	        {
	        	for (int j = 0; j < N; ++j)
	        	{
	        	    if (r[i].x < b[j].x && r[i].y < b[j].y && !used[j])
		    {
		        cnt++;
		        used[j] = true;
		        break;
		    }
	        	}
	        }
	        
	        WriteLine(cnt);
                }
            }
        }
        
        public struct Point
        {
        	public int x;
        	public int y;
        	public Point(int _x, int _y) { x = _x; y = _y; }
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