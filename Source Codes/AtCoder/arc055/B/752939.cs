using System;
using System.Linq;
using System.Collections;
using System.Threading.Tasks;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

namespace AtCoder
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new Program().Solve();
        }

        public void Solve()
        {
            var cin = new MyInputStream();
            var N = cin.ReadInt();
            var K = cin.ReadInt();

            // dp[????????][???????][??????????(true:0, false:1)]
            var dp = new double[N + 1, K + 2, 2];

            for (int i = 0; i < K + 1; ++i)
            {
                dp[N, i, 0] = 0;
                dp[N, i, 1] = 1;
            }

            for (int i = N - 1; i >= 0; --i)
            {
                // ?????????????
                var p = 1.0 / (i + 1.0);
                for (int j = 0; j <= K; j++)
                {
                    dp[i, j, 0] = (1 - p) * dp[i + 1, j, 0] + p * Max(dp[i + 1, j + 1, 1], dp[i + 1, j, 0]);
                    dp[i, j, 1] = (1 - p) * dp[i + 1, j, 1] + p * Max(dp[i + 1, j + 1, 1], dp[i + 1, j, 0]);
                }
            }
            WriteLine(dp[0, 0, 0]);
        }
    }

    public class MyInputStream
    {
        private char separator = ' ';
        private Queue<string> inputStream;
        public MyInputStream(char separator = ' ')
        {
            this.separator = separator;
            inputStream = new Queue<string>();
        }

        public string Read()
        {
            if (inputStream.Count != 0) return inputStream.Dequeue();
            string[] tmp = Console.ReadLine().Split(separator);
            for (int i = 0; i < tmp.Length; i++)
            {
                inputStream.Enqueue(tmp[i]);
            }
            return inputStream.Dequeue();
        }
        public string ReadLine() => Console.ReadLine();
        public int ReadInt() => int.Parse(Read());
        public long ReadLong() => long.Parse(Read());
        public double ReadDouble() => double.Parse(Read());
    }
}