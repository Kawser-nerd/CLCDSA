using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace C
{
    [TestFixture]
    public class Program
    {
        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] tmp = inputStream.ReadLine().Split(' ');

            int N = Convert.ToInt32(tmp[0]);
            int Q = Convert.ToInt32(tmp[1]);

            int[] E = new int[N];
            int[] S = new int[N];

            for (int i = 0; i < N; i++)
            {
                tmp = inputStream.ReadLine().Split(' ');

                E[i] = Convert.ToInt32(tmp[0]);
                S[i] = Convert.ToInt32(tmp[1]);
            }

            long[,] D = new long[N, N];

            for (int i = 0; i < N; i++)
            {
                tmp = inputStream.ReadLine().Split(' ');

                for (int j = 0; j < N; j++)
                {
                    D[i, j] = Convert.ToInt32(tmp[j]);
                }
            }

            for (int k = 0; k < N; k++)
            {
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if (D[i, k] != -1 && D[k, j] != -1 && (D[i, j] == -1 || D[i, k] + D[k, j] < D[i, j]))
                            D[i, j] = D[i, k] + D[k, j];
                    }
                }
            }

            int[] U = new int[Q];
            int[] V = new int[Q];

            for (int i = 0; i < Q; i++)
            {
                tmp = inputStream.ReadLine().Split(' ');

                U[i] = Convert.ToInt32(tmp[0]) - 1;
                V[i] = Convert.ToInt32(tmp[1]) - 1;
            }

            outputStream.Write("Case #{0}:", testCase);

            for (int q = 0; q < Q; q++)
            {
                double[] dist = new double[N];

                for (int i = 0; i < N; i++)
                {
                    dist[i] = double.MaxValue;
                }

                dist[U[q]] = 0;

                SortedSet<Pair> set = new SortedSet<Pair>();
                set.Add(new Pair { First = 0, Second = U[q] });

                while (set.Count > 0)
                {
                    Pair c = set.Min;
                    double d = c.First;
                    int u = c.Second;
                    set.Remove(c);

                    if (dist[u] == d)
                    {
                        for (int v = 0; v < N; v++)
                        {
                            if (D[u, v] != -1 && E[u] >= D[u, v])
                            {
                                double time = 1.0 * D[u, v] / S[u];
                                double ndist = dist[u] + time;

                                if (ndist < dist[v])
                                {
                                    dist[v] = ndist;
                                    set.Add(new Pair { First = ndist, Second = v });
                                }
                            }
                        }
                    }
                }

                outputStream.Write(" {0:0.0000000}", dist[V[q]]);
                outputStream.WriteLine();
            }
        }

        public class Pair : IComparable<Pair>
        {
            public double First;
            public int Second;

            public int CompareTo(Pair other)
            {
                int c = First.CompareTo(other.First);

                if (c != 0)
                    return c;

                return Second.CompareTo(other.Second);
            }
        }

        #region Tests

        [TestCase]
        public void TestSmallInput()
        {
            TestInput("..\\..\\Input\\C-small.in", "..\\..\\Output\\C-small.out");
        }

        [TestCase]
        public void TestLargeInput()
        {
            TestInput("..\\..\\Input\\C-large.in", "..\\..\\Output\\C-large.out");
        }

        private void TestInput(string inputFile, string outputFile)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("");

            FileInfo input = new FileInfo(inputFile);
            TextReader inputStream = input.OpenText();

            FileInfo output = new FileInfo(outputFile);
            TextWriter outputStream = output.CreateText();

            int testCase = Convert.ToInt32(inputStream.ReadLine());

            for (int i = 1; i <= testCase; i++)
            {
                TestCase(i, inputStream, outputStream);
            }

            outputStream.Close();
            inputStream.Close();
        }

        #endregion
    }
}
