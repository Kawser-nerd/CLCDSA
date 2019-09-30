using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace ARC073D
{
    public class WeightValuePair
    {
        public long Weight { get; }
        public long Value { get; }

        public WeightValuePair(long weight, long value)
        {
            Weight = weight;
            Value = value;
        }
    }

    public class Program
    {
        WeightValuePair[][] G;
        int N;
        long W;

        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            N = ss.Next(int.Parse);
            W = ss.Next(long.Parse);
            G = ss.Next(long.Parse, 2, N)
                .Select(a => new WeightValuePair(a[0], a[1]))
                .GroupBy(wv => wv.Weight)
                .OrderBy(g => g.Key)
                .Select(g => g.OrderByDescending(wv => wv.Value).ToArray())
                .ToArray();

            sw.WriteLine(GetAns(0, 0, 0));
            //---------------------------------
        }

        long GetAns(int num, long totalWeight, long totalValue)
        {
            if (num >= G.Length)
            {
                return totalWeight > W ? long.MinValue : totalValue;
            }

            var ret = long.MinValue;

            for (var i = 0; i <= G[num].Length; i++)
            {
                if (i != 0)
                {
                    totalWeight += G[num][i - 1].Weight;
                    totalValue += G[num][i - 1].Value;
                }
                ret = Math.Max(ret, GetAns(num + 1, totalWeight, totalValue));
            }

            return ret;
        }

        static void Main()
        {
            var ss = new StreamScanner(new StreamReader(Console.OpenStandardInput()));
            var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
            new Program().Solve(ss, sw);
            sw.Flush();
        }

        static readonly Func<string, string> String = s => s;
    }

    public class StreamScanner
    {
        static readonly char[] Sep = { ' ' };
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