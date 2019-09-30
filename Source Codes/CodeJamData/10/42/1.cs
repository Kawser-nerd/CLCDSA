using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;

namespace GoogleCodeJam
{
    class Program
    {
        readonly StreamReader reader = new StreamReader("../../Input.txt");
        readonly StreamWriter writer = new StreamWriter("../../Output.txt");
        string bufferedLine;
        int bufferedLineIndex;

        static IEnumerable<int> ReadInts(string data)
        {
            return data.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s));
        }

        string ReadToken()
        {
            if (bufferedLine == null)
                bufferedLine = reader.ReadLine();
            while (bufferedLineIndex < bufferedLine.Length && char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                bufferedLineIndex++;
            while (bufferedLineIndex >= bufferedLine.Length)
            {
                bufferedLine = reader.ReadLine();
                bufferedLineIndex = 0;
                while (bufferedLineIndex < bufferedLine.Length && char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                    bufferedLineIndex++;
            }
            int index = bufferedLineIndex;
            while (bufferedLineIndex < bufferedLine.Length && !char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                bufferedLineIndex++;
            return bufferedLine.Substring(index, bufferedLineIndex - index);
        }

        int ReadInt()
        {
            return int.Parse(ReadToken());
        }

        static void Main(string[] args)
        {
            Stopwatch stopwatch = new Stopwatch();
            var program = new Program();
            stopwatch.Start();
            program.Run();
            stopwatch.Stop();
            program.reader.Close();
            program.writer.Close();
            Console.WriteLine("Elapsed: " + stopwatch.Elapsed);
        }

        void Run()
        {
            int testCount = ReadInt();
            for (int i = 1; i < testCount + 1; i++)
            {
                var stopwatch = new Stopwatch();
                int p = ReadInt();
                int[] M = new int[1 << p];
                for (int j = 0; j < M.Length; j++)
                {
                    M[j] = ReadInt();
                }
                int[][] cost = new int[p][];
                for (int j = 0; j < p; j++)
                {
                    cost[j] = new int[1 << (p - 1 - j)];
                    for (int k = 0; k < cost[j].Length; k++)
                    {
                        cost[j][k] = ReadInt();
                    }
                }
                stopwatch.Start();
                var res = Calc(p, M, cost);
                stopwatch.Stop();
                Console.WriteLine("Done in {0}", stopwatch.Elapsed);
                writer.WriteLine("Case #{0}: {1}", i, res);
            }
        }

        int Plus(params int[] ar)
        {
            int res = 0;
            foreach (int i in ar)
            {
                if (i == -1)
                    return -1;
                res += i;
            }
            return res;
        }

        int Min(int a, int b)
        {
            if ( a== -1)
                return b;
            if (b == -1)
                return a;
            return Math.Min(a, b);
        }

        int Calc(int p, int[] M, int[][] cost)
        {
            int[] cc = new int[(1 << p) - 1];
            int k = 0;
            for (int i = cost.Length - 1; i >= 0; i--)
            {
                for (int j = 0; j < cost[i].Length; j++)
                {
                    cc[k] = cost[i][j];
                    k++;
                }
            }
            int count = (1 << (p + 1)) - 1;
            int[,] res = new int[count, p + 1];
            for (int i = count - 1; i >= 0; i--)
            {
                for (int pp = 0; pp < p + 1; pp++)
                {
                    if (i >= (1 << p) - 1)
                    {
                        int ii = i - ((1 << p) - 1);
                        res[i, pp] = pp <= M[ii] ? 0 : -1;
                    }
                    else
                    {
                        if (pp == p)
                            res[i, pp] = -1;
                        else
                        {
                            res[i, pp] = Min(Plus(cc[i], res[2 * i + 1, pp], res[2 * i + 2, pp]),
                                             Plus(res[2 * i + 1, pp + 1], res[2 * i + 2, pp + 1]));

                        }
                    }
                }
            }
            return res[0, 0];
        }
    }
}