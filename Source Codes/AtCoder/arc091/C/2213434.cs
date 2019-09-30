using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace ARC091E
{
    public class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var N = ss.Next(Int);
            var A = ss.Next(Long);
            var B = ss.Next(Long);

            if (N < A + B - 1 || A * B < N)
            {
                sw.WriteLine(-1);
                return;
            }

            var seq = MakeSeq(N, A, B);
            var comp = Compress(seq);
            sw.WriteLine(string.Join(" ", comp));
            //---------------------------------
        }

        IEnumerable<long> MakeSeq(int N, long A, long B)
        {
            var count = A * B - N;
            var i = 0L;

            while (i < A * B)
            {
                yield return A * (B - i / A - 1) + i % A + 1;
                var step = Math.Min(count, A - 1);
                count -= step;
                i += step + 1;
            }
        }

        IEnumerable<int> Compress(IEnumerable<long> source)
        {
            var comp = source
                .OrderBy(x => x)
                .Select((k, v) => new {k, v})
                .ToDictionary(kvp => kvp.k, kvp => kvp.v);

            return source.Select(x => comp[x] + 1);
        }

        static void Main()
        {
            var ss = new StreamScanner(new StreamReader(Console.OpenStandardInput()));
            var sw = new StreamWriter(Console.OpenStandardOutput()) {AutoFlush = false};
            new Program().Solve(ss, sw);
            sw.Flush();
        }

        static readonly Func<string, string> String = s => s;
        static readonly Func<string, int> Int = int.Parse;
        static readonly Func<string, long> Long = long.Parse;
        static readonly Func<string, double> Double = double.Parse;
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