using System;
using System.IO;
using System.Collections.Generic;

namespace ABC099D
{
    public class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var N = ss.Next(int.Parse);
            var C = ss.Next(int.Parse);
            var D = ss.Next(int.Parse, C, C);

            var cs = new int [3, C + 1];
            for (var i = 0; i < N; i++)
            for (var j = 0; j < N; j++)
            {
                cs[(i + j) % 3, ss.Next(int.Parse)]++;
            }

            var ans = int.MaxValue;
            for (var i = 1; i <= C; i++)
            for (var j = 1; j <= C; j++)
            for (var k = 1; k <= C; k++)
            {
                if (i == j || j == k || k == i) continue;
                var total = 0;
                for (var c = 1; c <= C; c++)
                {
                    total += cs[0, c] * D[c - 1][i - 1];
                    total += cs[1, c] * D[c - 1][j - 1];
                    total += cs[2, c] * D[c - 1][k - 1];
                }
                ans = Math.Min(ans, total);
            }

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