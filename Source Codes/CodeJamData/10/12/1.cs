using System;
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
                Stopwatch stopwatch = new Stopwatch();
                int D = ReadInt(), I = ReadInt(), M = ReadInt(), N = ReadInt();
                int[] numbers = ReadInts(reader.ReadLine()).ToArray();
                stopwatch.Start();
                var res = Calc(D, I, M, N, numbers);
                stopwatch.Stop();
                Console.WriteLine("Done in {0}", stopwatch.Elapsed);
                writer.WriteLine("Case #{0}: {1}", i, res);
            }
        }

        int MinPath(int I, int M, int a, int b)
        {
            int c = Math.Abs(a - b);
            if (c == 0)
                return 0;
            return (c - 1) / M * I;
        }

        int Calc(int D, int I, int M, int N,  int[] numbers)
        {
            int[,] res = new int[N + 1,256];
            for (int i = 1; i < N + 1; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    if (i == 1)
                    {
                        res[i, j] = Math.Abs(numbers[i - 1] - j);
                    }
                    else
                    {
                        res[i, j] = res[i - 1, j] + D;
                        for (int k = 0; k < 256; k++)
                        {
                            if (M == 0 && j != k) continue;
                            res[i, j] = Math.Min(
                                res[i, j], Math.Abs(numbers[i - 1] - j) + res[i - 1, k] + MinPath(I, M, j, k));
                        }
                    }
                }
            }

            int min = N * D;
            for (int i = 0; i < 256; i++)
            {
                min = Math.Min(min, res[N, i]);
            }
            return min;
        }
    }
}