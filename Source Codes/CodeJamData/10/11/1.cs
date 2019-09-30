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
                int N = ReadInt(), K = ReadInt();
                string[] table = new string[N];
                for (int j = 0; j < N; j++)
                {
                    table[j] = reader.ReadLine();
                }
                stopwatch.Start();
                var res = Calc(N, K, table);
                stopwatch.Stop();
                Console.WriteLine("Done in {0}", stopwatch.Elapsed);
                writer.WriteLine("Case #{0}: {1}", i, res);
            }
        }

        string Calc(int N, int K, string[] table)
        {
            char[][] newTable = Rotate(table);
            bool b = Wins(newTable, 'B', K), r = Wins(newTable, 'R', K);
            if (b && r)
                return "Both";
            if (b)
                return "Blue";
            if (r)
                return "Red";
            return "Neither";
        }

        bool Wins(char[][] table, char who, int K)
        {
            int N = table.Length;
            int[] dx = new int[] {1, 1, 0, -1}, dy = new int[]{0, 1, 1, 1};
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    for (int dir = 0; dir < 4; dir++)
                    {
                        bool ok = true;
                        for (int k = 0; k < K; k++)
                        {
                            if (i + dx[dir] * k >= 0 && i + dx[dir] * k < N && j + dy[dir] * k >= 0 && j + dy[dir] * k < N && table[i + dx[dir] * k][j + dy[dir] * k] == who)
                            {
                                
                            } else
                            {
                                ok = false;
                                break;
                            }
                        }
                        if (ok)
                            return true;
                    }
                }
            }
            return false;
        }

        char[][] Rotate(string[] table)
        {
            int N = table.Length;
            char[][] res = new char[N][];
            for (int i = 0; i < N; i++)
            {
                res[i] = new char[N];
                for (int j = 0; j < N; j++)
                {
                    res[i][j] = '.';
                }
            }

            for (int i = 0; i < N; i++)
            {
                string line = table[N - 1 - i];
                int k = N - 1;
                for (int j = N - 1; j >= 0; j--)
                {
                    if (line[j] != '.')
                    {
                        res[k][i] = line[j];
                        k--;
                    }
                }
            }
            return res;
        }
    }
}