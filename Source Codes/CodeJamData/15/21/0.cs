using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ReadWriteTemplate
{
    public class Solver
    {
        private static void SolveCase(int caseNumber)
        {
            /*int maxn = 1000000;
            var p = new int[maxn + 1];
            var d = new int[maxn + 1];
            for (int i = 0; i <= maxn; i++)
            {
                d[i] = 2 * maxn;
            }
            p[1] = 0;
            d[1] = 1;
            for (int i = 1; i < maxn; i++)
            {
                if (d[i + 1] > d[i] + 1)
                {
                    d[i + 1] = d[i] + 1;
                    p[i + 1] = i;
                }
                var rev = Reverse(i);
                if (d[rev] > d[i] + 1)
                {
                    d[rev] = d[i] + 1;
                    p[rev] = i;
                }
            }

            for (int i = 1; i <= 1000000; i++)
            {
                var calcLen = TrueLen(i);
                if (d[i] != calcLen)
                {
                    Writer.WriteLine("{0} {1} {2}", i, d[i], calcLen);
                }
            }*/

            /*var t = 30;//ReadInt();
            while (t > 0)
            {
                Writer.WriteLine(t);
                t = p[t];
            }
            Writer.WriteLine("Case #{0}: {1}", caseNumber, d[t]);*/

            long n = ReadLong();
            Writer.WriteLine("Case #{0}: {1}", caseNumber, TrueLen(n));
        }

        private static long TrueLen(long n)
        {
            var calcLen = CalcLen(n);
            if (n > 1)
            {
                var calcLen2 = CalcLen(n - 1) + 1;
                calcLen = Math.Min(calcLen, calcLen2);
            }
            return calcLen;
        }

        public static long CalcLen(long n)
        {
            long ans = 1;

            long d = 1;
            int p = 0;
            while (d * 10 <= n)
            {
                d *= 10;
                p++;
                if (p == 1)
                {
                    ans += 9;
                }
                else
                {
                    ans += Power10(p / 2) - 1 + 1 + Power10((p + 1) / 2) - 1;
                }
            }

            long best = n - d;

            d = 1;
            while (d < n)
            {
                long X = (n / d) * d + 1;
                if (X > n)
                {
                    d *= 10;
                    continue;
                }
                long len = Reverse(n / d) + 1 + n - X;
                best = Math.Min(best, len);

                d *= 10;
            }
            ans += best;

            return ans;
        }

        public static long Power10(int p)
        {
            long res = 1;
            for (int i = 0; i < p; i++)
            {
                res *= 10;
            }
            return res;
        }

        public static long Reverse(long x)
        {
            long res = 0;
            while (x > 0)
            {
                res = 10 * res + x % 10;
                x /= 10;
            }
            return res;
        }

        public static void Solve()
        {
            var n = ReadInt();
            for (int i = 0; i < n; i++)
            {
                SolveCase(i + 1);
            }
        }

        public static void Main()
        {
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
