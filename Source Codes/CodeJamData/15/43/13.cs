using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Threading;

namespace ReadWriteTemplate
{
    public class Solver
    {
        //private static string[][] words;
        private static List<List<int>> wordsInt;
        private static bool[] isEng;
        private static int ans;

        private static void SolveCase(int caseNumber)
        {
            int n = ReadInt();

            var dic = new Dictionary<string, int>();
            int count = 0;

            wordsInt = new List<List<int>>();
            isEng = new bool[n];
            ans = int.MaxValue;
            for (int i = 0; i < n; i++)
            {
                var w = Reader.ReadLine().Split();
                wordsInt.Add(new List<int>());
                for (int j = 0; j < w.Length; j++)
                {
                    if (!dic.ContainsKey(w[j]))
                    {
                        count++;
                        dic[w[j]] = count;
                    }
                    wordsInt[i].Add(dic[w[j]]);
                }
            }

            int bonus = 0;

            int d = 0;
            while (d < wordsInt[0].Count)
            {
                if (wordsInt[1].Contains(wordsInt[0][d]))
                {
                    var xxx = wordsInt[0][d];
                    wordsInt[1].RemoveAll(x => x == xxx);
                    wordsInt[0].RemoveAll(x => x == xxx);
                    bonus++;
                }
                else
                {
                    d++;
                }
            }

            d = 0;
            while (d < wordsInt[0].Count)
            {
                bool ok = false;
                for (int i = 2; i < n; i++)
                {
                    if (wordsInt[i].Contains(wordsInt[0][d]))
                    {
                        ok = true;
                        break;
                    }
                }

                if (ok)
                {
                    d++;
                }
                else
                {
                    wordsInt[0].Remove(wordsInt[0][d]);
                }
            }

            d = 0;
            while (d < wordsInt[1].Count)
            {
                bool ok = false;
                for (int i = 2; i < n; i++)
                {
                    if (wordsInt[i].Contains(wordsInt[1][d]))
                    {
                        ok = true;
                        break;
                    }
                }

                if (ok)
                {
                    d++;
                }
                else
                {
                    wordsInt[1].Remove(wordsInt[1][d]);
                }
            }

            Go(2, n);

            Writer.Write(ans + bonus);
        }

        private static void Go(int t, int n)
        {
            if (t >= n)
            {
                var eng = new List<int>(wordsInt[0]);
                var fre = new List<int>(wordsInt[1]);

                for (int k = 2; k < n; k++)
                {

                    if (isEng[k])
                    {
                        eng.AddRange(wordsInt[k]);
                    }
                    else
                    {
                        fre.AddRange(wordsInt[k]);
                    }
                }

                eng = eng.OrderBy(x => x).ToList();
                fre = fre.OrderBy(x => x).ToList();

                int d = 0;

                int i = 0;
                int j = 0;
                while (i < eng.Count && j < fre.Count)
                {
                    if (i > 0 && eng[i] == eng[i - 1])
                    {
                        i++;
                        continue;
                    }

                    if (eng[i] < fre[j])
                    {
                        i++;
                    }
                    else if (eng[i] == fre[j])
                    {
                        d++;
                        i++;
                    }
                    else if (eng[i] > fre[j])
                    {
                        j++;
                    }
                }

                ans = Math.Min(ans, d);

                return;
            }

            isEng[t] = false;
            Go(t + 1, n);
            isEng[t] = true;
            Go(t + 1, n);
        }

        public static void Solve()
        {
            var t = ReadInt();
            for (int i = 0; i < t; i++)
            {
                Writer.Write("Case #{0}: ", i + 1);
                SolveCase(i + 1);
                Writer.WriteLine();
            }
        }

        public static void Main()
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            //Reader = Console.In; Writer = Console.Out;
            Reader = File.OpenText("input.txt"); Writer = File.CreateText("output.txt");

            Solve();

            Reader.Close();
            Writer.Close();
        }

        #region Read/Write

        private static TextReader Reader;

        private static TextWriter Writer;

        private static Queue<string> CurrentLineTokens = new Queue<string>();

        private static string[] ReadAndSplitLine()
        {
            return Reader.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        }

        public static string ReadToken()
        {
            while (CurrentLineTokens.Count == 0)
                CurrentLineTokens = new Queue<string>(ReadAndSplitLine());
            return CurrentLineTokens.Dequeue();
        }

        public static int ReadInt()
        {
            return int.Parse(ReadToken());
        }

        public static long ReadLong()
        {
            return long.Parse(ReadToken());
        }

        public static double ReadDouble()
        {
            return double.Parse(ReadToken(), CultureInfo.InvariantCulture);
        }

        public static int[] ReadIntArray()
        {
            return ReadAndSplitLine().Select(int.Parse).ToArray();
        }

        public static long[] ReadLongArray()
        {
            return ReadAndSplitLine().Select(long.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            return ReadAndSplitLine().Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray();
        }

        public static int[][] ReadIntMatrix(int numberOfRows)
        {
            int[][] matrix = new int[numberOfRows][];
            for (int i = 0; i < numberOfRows; i++)
                matrix[i] = ReadIntArray();
            return matrix;
        }

        public static string[] ReadLines(int quantity)
        {
            string[] lines = new string[quantity];
            for (int i = 0; i < quantity; i++)
                lines[i] = Reader.ReadLine().Trim();
            return lines;
        }

        public static void WriteArray<T>(IEnumerable<T> array)
        {
            Writer.WriteLine(string.Join(" ", array));
        }

        #endregion
    }
}
