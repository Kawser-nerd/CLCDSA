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
            int M = 1000000007;

            int n = cin.ReadInt;
            int[] c = cin.ReadIntArray(n);

            int[] left = new int[200001];
            for (int i = 0; i <= 200000; i++) left[i] = -1;

            long[] dp = new long[n + 1];
            dp[0] = 1;

            for (int i = 0; i < n; i++)
            {
                dp[i + 1] = dp[i];

                if (i > 0
                    && c[i] != c[i - 1]
                    && left[c[i]] >= 0
                    && left[c[i]] < i - 1)
                {
                    dp[i + 1] += dp[left[c[i]] + 1];
                    dp[i + 1] %= M;
                }

                left[c[i]] = i;
            }

            Console.WriteLine(dp[n]);
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