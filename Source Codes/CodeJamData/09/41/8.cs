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
                List<string> matrix = new List<string>();
                for (int j = 0; j < N; j++)
                {
                    matrix.Add(reader.ReadLine());
                }
                int res = Calc(matrix);
                writer.WriteLine("Case #{0}: {1}", i, res);
            }
        }

        int Calc(List<string> matrix)
        {
            int n = matrix.Count;
            int[] indexes = new int[n];
            int[] last = new int[n];
            for (int i = 0; i < n; i++)
            {
                indexes[i] = i;
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] == '1')
                        last[i] = j;
                }
            }
            int res = 0;
            for (int i = 0; i < n; i++)
            {
                if (last[indexes[i]] > i)
                {
                    int k = i + 1;
                    while (last[indexes[k]] > i)
                        k++;
                    res += Move(indexes, k, i);
                }
            }
            return res;
        }

        int Move(IList<int> matrix, int from, int to)
        {
            int t = matrix[from];
            for (int i = from; i > to; i--)
            {
                matrix[i] = matrix[i - 1];
            }
            matrix[to] = t;
            return from - to;
        }
    }
}