using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace ARC097E
{
    public class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var N = ss.Next(int.Parse);
            var Balls = ss.Next(String, 2, 2 * N).Select(a => new {Color = a[0], Number = int.Parse(a[1])}).ToArray();

            //??????????????????
            var bi = new int[N + 1];
            var wi = new int[N + 1];
            for (var i = 0; i < N * 2; i++)
            {
                var ball = Balls[i];
                if (ball.Color == "B") bi[ball.Number] = i;
                if (ball.Color == "W") wi[ball.Number] = i;
            }

            //Number???????Index??????????
            var bs = new int[N + 1, N * 2];//[Number, Index]
            var ws = new int[N + 1, N * 2];//[Number, Index]
            for (var i = 1; i <= N; i++)
            {
                for (var j = 0; j < N * 2; j++) bs[i, j] = bs[i - 1, j] + (j >= bi[i] ? 1 : 0);
                for (var j = 0; j < N * 2; j++) ws[i, j] = ws[i - 1, j] + (j >= wi[i] ? 1 : 0);
            }

            //B?i??W?j????????????????????????
            var bc = new int[N, N + 1];//[b, w]
            var wc = new int[N + 1, N];//[b, w]
            for (var i = 0; i <= N; i++)
            for (var j = 0; j <= N; j++)
            {
                if (i < N) bc[i, j] = bi[i + 1] - bs[i, bi[i + 1]] - ws[j, bi[i + 1]];
                if (j < N) wc[i, j] = wi[j + 1] - bs[i, wi[j + 1]] - ws[j, wi[j + 1]];
            }

            //B?i??W?j?????????????
            var dp = new long[N + 1, N + 1];//[b, w]
            for (var i = 0; i <= N; i++)
            for (var j = 0; j <= N; j++)
            {
                if (i == 0 && j == 0) continue;
                var b = i == 0 ? long.MaxValue : dp[i - 1, j] + bc[i - 1, j];
                var w = j == 0 ? long.MaxValue : dp[i, j - 1] + wc[i, j - 1];
                dp[i, j] = Math.Min(b, w);
            }

            sw.WriteLine(dp[N, N]);
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