using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace ARC093C
{
    public class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var N = ss.Next(int.Parse);
            var A = ss.Next(long.Parse, N);

            var plan = new[] {0L}.Concat(A).Concat(new[] {0L}).ToArray();

            var cost = 0L;
            for (var i = 1; i < N + 2; i++)
            {
                cost += Math.Abs(plan[i - 1] - plan[i]);
            }

            for (var i = 1; i <= N; i++)
            {
                var via = Math.Abs(plan[i - 1] - plan[i]) + Math.Abs(plan[i] - plan[i + 1]);
                var through = Math.Abs(plan[i - 1] - plan[i + 1]);
                sw.WriteLine(cost - via + through);
            }
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