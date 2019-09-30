using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
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
            long[] a_n = cin.ReadLongArray(n);
            Array.Sort(a_n);
            Array.Reverse(a_n);

            Dictionary<long, long> dict = new Dictionary<long, long>();
            foreach(long a in a_n)
            {
                if (!dict.ContainsKey(a))
                {
                    dict.Add(a, 0);
                }
                dict[a]++;
            }

            long ans = 0;
            foreach(long a in a_n)
            {
                if(dict[a] == 0)
                {
                    continue;
                }

                dict[a]--;

                long powered = 1;
                while(powered <= a)
                {
                    powered <<= 1;
                }

                long b = powered - a;
                if (dict.ContainsKey(b) && dict[b] > 0)
                {
                    dict[b]--;
                    ans++;
                }
            }

            Console.WriteLine(ans);
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