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
            return data.Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s));
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
            int T = ReadInt();
            for (int i = 1; i < T + 1; i++)
            {
                int N = ReadInt();
                int[] r = new int[N], x = new int[N], y = new int[N];
                for (int j = 0; j < N; j++)
                {
                    x[j] = ReadInt();
                    y[j] = ReadInt();
                    r[j] = ReadInt();
                }
                var res = Calc(x, y, r);
                writer.WriteLine("Case #{0}: {1}", i, res);
            }
        }

        double Calc(int[] x, int [] y, int [] r)
        {
            int n = x.Length;
            switch (n)
            {
                case 1:
                    return r[0];
                case 2:
                    return Math.Max(r[0], r[1]);
                case 3:
                    double[,] d = new double[n,n];
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            d[i, j] = Math.Sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                        }
                    }
                    return Math.Min(Math.Min(
                        Math.Max(r[0], (r[1] + r[2] + d[1, 2]) / 2),
                        Math.Max(r[1], (r[0] + r[2] + d[0, 2]) / 2)),
                        Math.Max(r[2], (r[0] + r[1] + d[0, 1]) / 2));
                default:
                    return 0;
            }
        }

        
    }
}