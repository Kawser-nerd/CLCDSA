using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace TestPrj
{
    class Program
    {
        void runCase(int caseNum)
        {
            int N = nextInt();
            List<long> dist = new List<long>();
            List<long> length = new List<long>();

            for (int i = 0; i < N; ++i) {
                dist.Add(nextLong());
                length.Add(nextLong());
            }

            long endPoint = nextLong();

            long[] dp = new long[N];

            dp[0] = dist[0];

            bool OK = false;

            for (int i = 0; i < N; ++i) {
                if (dist[i] + dp[i] >= endPoint)
                {
                    OK = true;
                    break;
                }
                for (int j = i + 1; j < N; ++j)
                {
                    if (dist[j] - dist[i] > dp[i])
                        break;
                    dp[j] = Math.Max(dp[j], Math.Min(dist[j] - dist[i], length[j]));
                }
            }

            Console.WriteLine("Case #" + caseNum.ToString() + ": " + (OK ? "YES" : "NO"));
        }

        void run()
        {
            input = Console.In.ReadToEnd().Split(
                 new char[] { ' ', '\t', '\n', '\r' }, StringSplitOptions.RemoveEmptyEntries);
            curInputPos = 0;
            //int K = int.Parse(Console.ReadLine());
            int K = nextInt();
            for (int i = 0; i < K; i++)
                runCase(i + 1);
        }

        string[] input;
        int curInputPos;

        string next()
        {
            while (input[curInputPos] == null || input[curInputPos].Trim().Length == 0)
                ++curInputPos;
            return input[curInputPos++];
        }

        int nextInt()
        {
            return int.Parse(next());
        }


        double nextDouble()
        {
            return double.Parse(next());
        }

        long nextLong()
        {
            return long.Parse(next());
        }

        static void Main(string[] args)
        {
            if (args.Length > 0)
            {
                Console.SetIn(new StreamReader(@"input.txt"));
                StreamWriter writer = new StreamWriter(@"output.txt");
                writer.AutoFlush = true;
                Console.SetOut(writer);
            }
            Program p = new Program();
            p.run();
        }
    }
}
