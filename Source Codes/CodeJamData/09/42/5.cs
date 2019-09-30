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
                int R = ReadInt(), C = ReadInt(), F = ReadInt();
                List<string> matrix = new List<string>();
                for (int j = 0; j < R; j++)
                {
                    matrix.Add(reader.ReadLine());
                }
                var res = Calc(matrix, F);
                writer.WriteLine("Case #{0}: {1}", i, res < NO ? "Yes " + res : "No");
            }
        }

        const int NO = 8888;

        int Calc(List<string> matrix, int F)
        {
            int H = matrix.Count;
            int W = matrix[0].Length;
            bool[][] map = new bool[H][];
            bool[][] death = new bool[H][];
            for (int i = 0; i < H; i++)
            {
                map[i] = new bool[W];
                death[i] = new bool[W];
                for (int j = 0; j < W; j++)
                {
                    map[i][j] = matrix[i][j] == '#';
                }
            }
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    bool ff = false;
                    for (int k = i + 1; k < i + F + 1; k++)
                    {
                        if (k >= H || map[k][j])
                        {
                            ff = true;
                            break;
                        }
                    }
                    if (!ff)
                    {
                        death[i][j] = true;
                    }
                }
            }
            int[,,] res = new int[H,1 << W,W];
            for (int i = H - 2; i >= 0; i--)
            {
                for (int j = 0; j < W; j++)
                {
                    for (int m = 0; m < 1 << W; m++)
                    {
                        res[i, m, j] = NO;
                        bool[] cur = new bool[W];
                        for (int k = 0; k < W; k++)
                        {
                            cur[k] = map[i][k] && !Bit(m, k);
                        }
                        if (death[i][j])
                        {
                            res[i, m, j] = NO;
                            continue;
                        }
                        if (!map[i + 1][j])
                        {
                            res[i, m, j] = res[i + 1, 0, j];
                            continue;
                        }
                        if (j > 0 && !cur[j - 1] && map[i + 1][j - 1])
                        {
                            res[i, m, j] = res[i, m, j - 1];
                            continue;
                        }
                        int left = j, right = j;
                        for (int k = j + 1; k < W; k++)
                        {
                            if (cur[k]) break;
                            if (!map[i + 1][k])
                            {
                                res[i, m, j] = Math.Min(res[i, m, j], res[i + 1, 0, k]);
                                break;
                            }
                            right = k;
                        }
                        for (int k = j - 1; k >= 0; k--)
                        {
                            if (cur[k]) break;
                            if (!map[i + 1][k])
                            {
                                res[i, m, j] = Math.Min(res[i, m, j], res[i + 1, 0, k]);
                                break;
                            }
                            left = k;
                        }
                        for (int k = left; k < right + 1; k++)
                        {
                            for (int l = k; l < right + 1; l++)
                            {
                                if (k == left && l == right)
                                    continue;
                                int m1 = 0;
                                for (int kl = k; kl < l + 1; kl++)
                                {
                                    m1 |= 1 << kl;
                                }
                                res[i, m, j] = Math.Min(res[i, m, j], res[i + 1, m1, k] + l - k + 1);
                                res[i, m, j] = Math.Min(res[i, m, j], res[i + 1, m1, l] + l - k + 1);
                            }
                        }
                    }
                }
            }
            return res[0, 0, 0];
        }

        bool Bit(int N, int bit)
        {
            return (N & (1 << bit)) != 0;
        }
    }
}