using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace ARC074C
{
    public class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var H = ss.Next(long.Parse);
            var W = ss.Next(long.Parse);

            var ans = Math.Min(GetAns(H, W), GetAns(W, H));
            sw.WriteLine(ans);
            //---------------------------------
        }

        long GetAns(long h, long w)
        {
            var min = long.MaxValue;

            for (var h1 = 0; h1 <= h; h1++)
            {
                var h2 = h - h1;
                var h21 = h2 / 2;
                var h22 = (h2 + 1) / 2;
                min = Math.Min(min, GetMinDiff(h1 * w, h21 * w, h22 * w));

                var w1 = w / 2;
                var w2 = (w + 1) / 2;
                min = Math.Min(min, GetMinDiff(h1 * w, h2 * w1, h2 * w2));
            }

            return min;
        }
        
        long GetMinDiff(params long[] areas)
        {
            return areas.Max() - areas.Min();
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