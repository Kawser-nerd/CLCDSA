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
                int k = ReadInt();
                int[][] diamond = new int[2 * k - 1][];
                for (int j = 0; j < diamond.Length; j++)
                {
                    diamond[j] = new int[Math.Min(j + 1, 2 * k - 1 - j)];
                    for (int l = 0; l < diamond[j].Length; l++)
                    {
                        diamond[j][l] = ReadInt();
                    }
                }
                stopwatch.Start();
                var res = Calc(k, diamond);
                stopwatch.Stop();
                Console.WriteLine("Done in {0}", stopwatch.Elapsed);
                writer.WriteLine("Case #{0}: {1}", i, res);
            }
        }

        int Len(int l, int k)
        {
            return Math.Min(l + 1, 2 * k - 1 - l);
        }

        int Count(int k)
        {
            return k * k;
        }

        int Calc(int k, int[][] diamond)
        {
            int res = 0;
            {
                int best = 10 * k;
                for (int x = 1 - k; x <= k - 1; x++)
                {
                    bool ok = true;
                    for (int i = 0; i < diamond.Length; i++)
                    {
                        for (int j = 0; j < diamond[i].Length; j++)
                        {
                            int x1 = 2 * j - Len(i, k) + 1;
                            int j1 = j + (x - x1);
                            if (j1 >= 0 && j1 < diamond[i].Length && diamond[i][j] != diamond[i][j1])
                            {
                                ok = false;
                                break;
                            }
                        }
                        if (!ok)
                            break;
                    }
                    if (ok)
                    {
                        best = Math.Min(best, Math.Abs(x));
                    }
                }
                res += best;
            }
            {
                int best = 10 * k;
                for (int y = 1 - k; y <= k - 1; y++)
                {
                    bool ok = true;
                    for (int i = 0; i < diamond.Length; i++)
                    {
                        for (int j = 0; j < diamond[i].Length; j++)
                        {
                            int y1 = i - k + 1;
                            int i1 = i + 2 * (y - y1);
                            int j1 = j - (Len(i, k) - Len(i1, k)) / 2;
                            if (i1 >= 0 && i1 < diamond.Length &&
                                j1 >= 0 && j1 < diamond[i1].Length && diamond[i][j] != diamond[i1][j1])
                            {
                                ok = false;
                                break;
                            }
                        }
                        if (!ok)
                            break;
                    }
                    if (ok)
                    {
                        best = Math.Min(best, Math.Abs(y));
                    }
                }
                res += best;
            }
            return Count(k + res) - Count(k);
        }
    }
}