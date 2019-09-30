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

            var memo = new long[50, 2];
            for (var i = 0; i < 50; i++)
            {
                memo[i, 0] = long.MinValue;
                memo[i, 1] = long.MinValue;
            }
            
            Func<int, bool, long> DFS = null;
            DFS = (digit, fever) =>
            {
                if (digit == -1) return 0;
                if (memo[digit, fever ? 1 : 0] != long.MinValue) return memo[digit, fever ? 1 : 0];

                var place = 1L << digit;
                var popCount = A.Sum(a => (a >> digit) & 1);

                Func<bool, long> f0 = b => popCount * place + DFS(digit - 1, b);
                Func<bool, long> f1 = b => (N - popCount) * place + DFS(digit - 1, b);

                if (fever) return memo[digit, 1] = Math.Max(f0(true), f1(true));
                if (((K >> digit) & 1) == 1) return memo[digit, 0] = Math.Max(f0(true), f1(false));
                return memo[digit, 0] = f0(false);
            };

            sw.WriteLine(DFS(40, false));
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