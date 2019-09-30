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
            var N = ss.Next(int.Parse);
            var K = ss.Next(long.Parse);
            var A = ss.Next(long.Parse, N);

            var ans = new long[2];

            for (var i = 0; i < 40; i++)
            {
                var pc = A.Sum(a => (a >> i) & 1);
                var res0 = pc * (1L << i);
                var res1 = (N - pc) * (1L << i);

                if (((K >> i) & 1) == 1)
                {
                    ans[0] = Math.Max(ans[1] + res0, ans[0] + res1);
                }
                else
                {
                    ans[0] = ans[0] + res0;
                }

                ans[1] = Math.Max(ans[1] + res0, ans[1] + res1);
            }

            sw.WriteLine(ans[0]);
            //---------------------------------
        }

        static void Main()
        {
            var ss = new StreamScanner(new StreamReader(Console.OpenStandardInput()));
            var sw = new StreamWriter(Console.OpenStandardOutput()) {AutoFlush = false};
            new Program().Solve(ss, sw);
            sw.Flush();
        }
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