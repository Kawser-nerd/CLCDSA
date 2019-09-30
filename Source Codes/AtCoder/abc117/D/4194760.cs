using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace ABC117D
{
    public class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            const int MAX = 50;

            var N = ss.Next(int.Parse);
            var K = ss.Next(long.Parse);
            var A = ss.Next(long.Parse, N);

            var pops = new long[MAX];
            foreach (var a in A)
            {
                for (long i = 0, t = a; t > 0; i++, t >>= 1)
                {
                    if ((t & 1) == 1) pops[i]++;
                }
            }

            var memo = new long[MAX];
            for (long i = 0, t = 1; i < MAX; i++, t <<= 1)
            {
                memo[i] += Math.Max(N - pops[i], pops[i]) * t;
                if (i > 0) memo[i] += memo[i - 1];
            }

            var ans = 0L;
            var calc = 0L;
            var kBase2 = Convert.ToString(K, 2);
            var kBase2Rev = (new string('0', MAX - kBase2.Length) + kBase2).Select(c => c - '0').Reverse().ToArray();

            for (long i = MAX - 1, t = 1L << (MAX - 1); i >= 0; i--, t >>= 1)
            {
                if (kBase2Rev[i] == 0)
                {
                    calc += pops[i] * t;
                }
                else
                {
                    if (i > 0) ans = Math.Max(ans, calc + pops[i] * t + memo[i - 1]);
                    calc += (N - pops[i]) * t;
                }
            }

            ans = Math.Max(ans, calc);
            sw.WriteLine(ans);
            //---------------------------------
        }

        static void Main()
        {
            var ss = new StreamScanner(new StreamReader(Console.OpenStandardInput()));
            var sw = new StreamWriter(Console.OpenStandardOutput()) {AutoFlush = false};
            new Program().Solve(ss, sw);
            sw.Flush();
        }

        static readonly Func<string, string> String = s => s;
    }

    public class StreamScanner
    {
        static readonly char[] Sep = {' '};
        readonly Queue<string> buffer = new Queue<string>();
        readonly TextReader textReader;

        public StreamScanner(TextReader textReader)
        {
            this.textReader = textReader;
        }

        public T Next<T>(Func<string, T> parser)
        {
            if (buffer.Count != 0) return parser(buffer.Dequeue());
            var nextStrings = textReader.ReadLine().Split(Sep, StringSplitOptions.RemoveEmptyEntries);
            foreach (var nextString in nextStrings) buffer.Enqueue(nextString);
            return Next(parser);
        }

        public T[] Next<T>(Func<string, T> parser, int x)
        {
            var ret = new T[x];
            for (var i = 0; i < x; ++i) ret[i] = Next(parser);
            return ret;
        }

        public T[][] Next<T>(Func<string, T> parser, int x, int y)
        {
            var ret = new T[y][];
            for (var i = 0; i < y; ++i) ret[i] = Next(parser, x);
            return ret;
        }
    }
}