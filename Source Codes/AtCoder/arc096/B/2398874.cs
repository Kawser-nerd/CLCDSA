using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace ARC096D
{
    public class Program
    {
        struct XVPair
        {
            public long X;
            public long V;

            public XVPair(long x, long v)
            {
                X = x;
                V = v;
            }
        }

        int N;
        long C;
        XVPair[] XV;

        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            N = ss.Next(int.Parse);
            C = ss.Next(long.Parse);
            XV = ss.Next(long.Parse, 2, N).Select(a => new XVPair(a[0], a[1])).ToArray();

            var tr1 = GetMaxValuesOfDist(true, 1);
            var tr2 = GetMaxValuesOfDist(true, 2);
            var tl1 = GetMaxValuesOfDist(false, 1);
            var tl2 = GetMaxValuesOfDist(false, 2);

            var max = 0L;
            for (var i = 0; i <= N; i++)
            {
                max = Math.Max(max, tr1[i] + tl2[N - i]);
                max = Math.Max(max, tr2[i] + tl1[N - i]);
            }

            sw.WriteLine(max);
            //---------------------------------
        }

        long[] GetMaxValuesOfDist(bool isRight, int walkCost)
        {
            var ret = new long[N + 1];
            var sum = 0L;
            for (var i = 1; i <= N; i++)
            {
                var cur = isRight ? i - 1 : N - i;
                var dist = isRight ? XV[cur].X : C - XV[cur].X;

                sum += XV[cur].V;
                ret[i] = Math.Max(ret[i - 1], sum - dist * walkCost);
            }
            return ret;
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