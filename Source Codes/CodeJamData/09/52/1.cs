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
            int testCount = ReadInt();
            for (int i = 1; i < testCount + 1; i++)
            {
                string p = ReadToken();
                int K = ReadInt();
                int n = ReadInt();
                List<string> dic = new List<string>();
                for (int j = 0; j < n; j++)
                {
                    dic.Add(reader.ReadLine());
                }
                var res = Calc(p, dic, K);
                writer.Write("Case #{0}:", i);
                for (int j = 1; j < res.Length; j++)
                {
                    writer.Write(" " + res[j]);
                }
                writer.WriteLine();
            }
        }

        const int mod = 10009;

        long[] Calc(string p, List<string> dic, int K)
        {
            var wcount = dic.Count;
            int[][] wordsMasks = new int[wcount][];
            for (int i = 0; i < wcount; i++)
            {
                wordsMasks[i] = new int[26];
                foreach (char c in dic[i])
                {
                    wordsMasks[i][c - 'a']++;
                }
            }
            long[] res = new long[K + 1];
            string[] terms = p.Split('+');
            long[][] resByTerm = new long[terms.Length][];
            for (int termIndex = 0; termIndex < terms.Length; termIndex++)
            {
                string term = terms[termIndex];
                long[] termRes = resByTerm[termIndex] = new long[K + 1];
                long[][] resByInterm = new long[K + 1][];
                var tlen = term.Length;
                resByInterm[0] = new long[1 << tlen];
                resByInterm[0][0] = 1;
                long[,] wordRes = new long[wcount, 1 << tlen];
                for (int wi = 0; wi < wcount; wi++)
                {
                    for (int mask = 0; mask < 1 << tlen; mask++)
                    {
                        wordRes[wi, mask] = 1;
                        for (int i = 0; i < term.Length; i++)
                        {
                            if (Bit(mask, i))
                            {
                                wordRes[wi, mask] *= wordsMasks[wi][term[i] - 'a'];
                                wordRes[wi, mask] %= mod;
                            }
                        }
                    }
                }
                for (int d = 1; d < K + 1; d++)
                {
                    resByInterm[d] = new long[1 << tlen];
                    for (int mask = 0; mask < 1 << tlen; mask++)
                    {
                        for (int wi = 0; wi < wcount; wi++)
                        {
                            for (int mask1 = 0; mask1 < 1 << tlen; mask1++)
                            {
                                if (!Sub(mask1, mask, tlen)) continue;
                                resByInterm[d][mask] += resByInterm[d - 1][mask1] * wordRes[wi, mask ^ mask1];
                                resByInterm[d][mask] %= mod;
                            }
                        }
                    }
                    termRes[d] = resByInterm[d][(1 << tlen) - 1];
                    res[d] += termRes[d];
                    res[d] %= mod;
                }
            }
            return res;
        }

        bool Sub(int mask1, int mask2, int tlen)
        {
            for (int i = 0; i < tlen; i++)
            {
                if (Bit(mask1, i) && !Bit(mask2, i))
                    return false;
            }
            return true;
        }

        static bool Bit(int value, int bit)
        {
            return (value & (1 << bit)) != 0;
        }
    }
}