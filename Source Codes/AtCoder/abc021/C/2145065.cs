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
            const int MOD = 1000000007;

            var N = cin.ReadInt();
            var a = cin.ReadInt() - 1;
            var b = cin.ReadInt() - 1;
            var M = cin.ReadInt();
            var g = new List<int>[N];
            for (int i = 0; i < N; i++)
                g[i] = new List<int>();
            for (int i = 0; i < M; i++)
            {
                var x = cin.ReadInt() - 1;
                var y = cin.ReadInt() - 1;
                g[x].Add(y);
                g[y].Add(x);
            }

            var dp = new int[N + 1, N + 1];
            dp[0, a] = 1;
            for (int i = 0;; i++)
            {
                if (dp[i, b] != 0)
                {
                    WriteLine(dp[i, b]);
                    break;
                }
                for (int j = 0; j < N; j++)
                {
                    for (int k = 0; k < g[j].Count; k++)
                    {
                        dp[i + 1, g[j][k]] = (dp[i + 1, g[j][k]] + dp[i, j]) % MOD;
                    }
                }
            }
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