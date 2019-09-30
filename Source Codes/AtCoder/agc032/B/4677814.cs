using System;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
using System.Linq;
using System.IO;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
            Console.SetOut(sw);
            new Program().Solve(new ConsoleInput(Console.In, ' '));
            Console.Out.Flush();
#if DEBUG
            ReadLine();
#endif
        }


        void Solve(ConsoleInput cin)
        {
            int n = cin.ReadInt;
            List<Tuple<int, int>> ans = new List<Tuple<int, int>>();

            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (n - i + ((n + 1) % 2) != j)
                    {
                        ans.Add(new Tuple<int, int>(i, j));
                    }
                }
            }

            Console.WriteLine(ans.Count);
            for (int i = 0; i < ans.Count; i++)
                Console.WriteLine(ans[i].Item1 + " " + ans[i].Item2);
        }

        class ConsoleInput
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

            public string ReadLine { get { return _stream.ReadLine(); } }
            public int ReadInt { get { return int.Parse(Read); } }
            public long ReadLong { get { return long.Parse(Read); } }
            public double ReadDouble { get { return double.Parse(Read); } }
            public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read; return ret; }
            public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt; return ret; }
            public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong; return ret; }
        }
    }
}