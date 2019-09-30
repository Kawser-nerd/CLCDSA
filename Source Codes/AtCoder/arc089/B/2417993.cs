using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace ARC089D
{
    public class Program
    {
        int N;
        int K;
        int K2;
        int[,] imos;

        void Add(int lx, int ty, int rx, int by)
        {
            lx %= K2;
            ty %= K2;
            rx %= K2;
            by %= K2;

            if (lx > rx)
            {
                Add(lx, ty, K2 - 1, by);
                Add(0, ty, rx, by);
                return;
            }
            if (ty > by)
            {
                Add(lx, ty, rx, K2 - 1);
                Add(lx, 0, rx, by);
                return;
            }

            imos[ty, lx]++;
            imos[by + 1, lx]--;
            imos[ty, rx + 1]--;
            imos[by + 1, rx + 1]++;
        }

        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            N = ss.Next(int.Parse);
            K = ss.Next(int.Parse);
            K2 = K * 2;
            imos = new int[K2 + 1, K2 + 1];

            for (var i = 0; i < N; i++)
            {
                var X = ss.Next(int.Parse);
                var Y = ss.Next(int.Parse);
                var C = ss.Next(String);
                if (C == "B") X += K;

                Add(X, Y, X + K - 1, Y + K - 1);
                Add(X + K, Y + K, X + K2 - 1, Y + K2 - 1);
            }

            var max = 0;
            for (var i = 0; i < 2 * K; i++)
            for (var j = 0; j < 2 * K; j++)
            {
                if (i != 0) imos[i, j] += imos[i - 1, j];
                if (j != 0) imos[i, j] += imos[i, j - 1];
                if (i != 0 && j != 0) imos[i, j] -= imos[i - 1, j - 1];
                max = Math.Max(max, imos[i, j]);
            }
            sw.WriteLine(max);
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
    }
}