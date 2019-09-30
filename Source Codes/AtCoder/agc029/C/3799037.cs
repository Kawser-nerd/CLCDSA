using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace ReadWriteTemplate
{
    public static class Solver
    {
        private static void SolveCase()
        {
            int n = ReadInt();
            var a = ReadIntArray().ToArray();

            int l = 1;
            int r = n;
            while (l < r)
            {
                int m = (l + r) / 2;

                var root = new Node(1, 1);
                Node cur;
                if (a[0] > 1)
                {
                    cur = new Node(a[0], 1);
                    root.Right = cur;
                    cur.Left = root;
                }
                else
                {
                    cur = root;
                }

                bool ok = true;
                for (int i = 1; i < n; i++)
                {
                    if (a[i] > a[i - 1])
                    {
                        var node = new Node(a[i], 1);
                        cur.Right = node;
                        node.Left = cur;
                        cur = node;
                    }
                    else
                    {
                        while (cur.Index > a[i])
                        {
                            cur = cur.Left;
                            cur.Right = null;
                        }
                        if (cur.Index != a[i])
                        {
                            var node = new Node(a[i], 1);
                            cur.Right = node;
                            node.Left = cur;
                            cur = node;
                        }
                        var move = cur;
                        while (move.Value >= m)
                        {
                            if (move.Index == 1 || m == 1)
                            {
                                ok = false;
                                break;
                            }
                            move.Value = 1;
                            if (move.Left.Index != move.Index - 1)
                            {
                                var node = new Node(move.Index - 1, 1);
                                node.Right = move;
                                node.Left = move.Left;
                                move.Left.Right = node;
                                move.Left = node;
                            }
                            move = move.Left;
                        }
                        if (!ok)
                        {
                            break;
                        }
                        move.Value++;
                    }
                }

                if (ok)
                {
                    r = m;
                }
                else
                {
                    l = m + 1;
                }
            }

            Writer.WriteLine(l);
        }

        public class Node
        {
            public Node(int index, int value)
            {
                Index = index;
                Value = value;
            }

            public int Index;

            public int Value;

            public Node Left;

            public Node Right;
        }

        public static void Solve()
        {
            SolveCase();

            /*var sw = Stopwatch.StartNew();*/

            /*int T = ReadInt();
            for (int i = 0; i < T; i++)
            {
                // Writer.Write("Case #{0}: ", i + 1);
                SolveCase();
            }*/

            /*sw.Stop();
            Console.WriteLine(sw.ElapsedMilliseconds);*/
        }

        public static void Main()
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

#if DEBUG
            // Reader = Console.In; Writer = Console.Out;
            Reader = File.OpenText("input.txt"); Writer = File.CreateText("output.txt");
#else
            Reader = Console.In; Writer = Console.Out;
#endif

            // Solve();
            Thread thread = new Thread(Solve, 64 * 1024 * 1024);
            thread.CurrentCulture = CultureInfo.InvariantCulture;
            thread.Start();
            thread.Join();

            Reader.Close();
            Writer.Close();
        }

        public static IOrderedEnumerable<TSource> OrderByWithShuffle<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector)
        {
            return source.Shuffle().OrderBy(keySelector);
        }

        public static T[] Shuffle<T>(this IEnumerable<T> source)
        {
            T[] result = source.ToArray();
            Random rnd = new Random();
            for (int i = result.Length - 1; i >= 1; i--)
            {
                int k = rnd.Next(i + 1);
                T tmp = result[k];
                result[k] = result[i];
                result[i] = tmp;
            }
            return result;
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

        public static string ReadLine()
        {
            return Reader.ReadLine();
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