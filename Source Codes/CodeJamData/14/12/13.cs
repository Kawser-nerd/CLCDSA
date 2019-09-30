using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    public class Program
    {
        int N;
        int[] X;
        int[] Y;
        List<int>[] G;

        public void ReadData()
        {
            N = ReadInt();
            X = new int[N - 1];
            Y = new int[N - 1];

            G = new List<int>[N];
            for (int i = 0; i < N; i++)
            {
                G[i] = new List<int>();
            }

            for (int i = 0; i < N - 1; i++)
            {
                var ar = ReadArray<int>();
                X[i] = ar[0];
                Y[i] = ar[1];
                G[X[i] - 1].Add(Y[i] - 1);
                G[Y[i] - 1].Add(X[i] - 1);
            }

            //N = 1000;
            //G = new List<int>[N];
            //for (int i = 0; i < N; i++)
            //{
            //    G[i] = new List<int>();
            //}
            //var r = new Random();
            //for (int i = 1; i < N; i++)
            //{
            //    int x = r.Next(i);
            //    G[x].Add(i);
            //    G[i].Add(x);
            //}
        }

        public string Solve()
        {
            int min = N - 1;

            _cache.Clear();
            _cache2.Clear();

            for (int i = 0; i < N; i++)
            {
                if (G[i].Count > 1)
                {
                    min = Math.Min(min, SolveForRoot(i, -1));
                }
            }

            return min.ToString();
        }

        Dictionary<Tuple<int, int>, int> _cache = new Dictionary<Tuple<int, int>, int>();
        public int SolveForRoot(int i, int parent)
        {
            var cacheKey = new Tuple<int,int>(i,parent);
            if (_cache.ContainsKey(cacheKey))
                return _cache[cacheKey];

            int result;

            var edges = G[i].Where(e => e != parent).ToList();
            int edgeCount = edges.Count();
            if (edgeCount == 0)
                result = 0;
            else if (edgeCount == 1)
                result = CountNodes(edges[0], i);
            else if (edgeCount == 2)
            {
                result = SolveForRoot(edges[0], i) + SolveForRoot(edges[1], i);
            }
            else
            {
                int[] solns = new int[edgeCount];
                int[] nodeCount = new int[edgeCount];
                for (int k = 0; k < edgeCount; k++)
                {
                    solns[k] = SolveForRoot(edges[k], i);
                    nodeCount[k] = CountNodes(edges[k], i);
                }

                int min = int.MaxValue;
                for (int edge1 = 0; edge1 < edgeCount; edge1++)
                {
                    for (int edge2 = edge1+1; edge2 < edgeCount; edge2++)
                    {
                        int del = 0;
                        for (int l = 0; l < edgeCount; l++)
                        {
                            if (l != edge1 && l != edge2)
                                del += nodeCount[l];
                        }
                        min = Math.Min(min, solns[edge1] + solns[edge2] + del);
                    }
                }                
                result = min;
            }

            _cache[cacheKey] = result;
            return result;
        }

        Dictionary<Tuple<int, int>, int> _cache2 = new Dictionary<Tuple<int, int>, int>();
        private int CountNodes(int root, int parent)
        {
            var cacheKey = new Tuple<int, int>(root, parent);
            if (_cache2.ContainsKey(cacheKey))
                return _cache2[cacheKey];

            int count = 1;
            foreach (int edge in G[root])
            {
                if (edge != parent)
                    count += CountNodes(edge, root);
            }

            _cache2[cacheKey] = count;
            return count;
        }

        static StreamReader reader;

        static void Main(string[] args)
        {
            string filename = args.Length > 0 ? args[0] : "test.in";
            string outFileName = filename.Replace(".in", ".out");
            string expectedFileName = filename.Replace(".in", ".expected");

            using (reader = File.OpenText(filename))
            using (var outFile = File.CreateText(outFileName))
            {
                int T = ReadInt();
                Console.WriteLine("{0} test cases", T);

                for (int tc = 1; tc <= T; tc++)
                {
                    Console.WriteLine("Starting test case {0}", tc);
                    var problem = new Program();
                    problem.ReadData();
                    string solution = problem.Solve();

                    outFile.WriteLine("Case #{0}: {1}", tc, solution);
                    Console.WriteLine("Case #{0}: {1}", tc, solution);
                }
            }

            if (File.Exists(expectedFileName))
            {
                CompareOutputToExpected(outFileName, expectedFileName);
            }
        }

        private static void CompareOutputToExpected(string outFileName, string expectedFileName)
        {
            string[] expected = File.ReadAllLines(expectedFileName);
            string[] actual = File.ReadAllLines(outFileName);
            for (int i = 0; i < Math.Max(expected.Length, actual.Length); i++)
            {
                string lineActual = i < actual.Length ? actual[i] : "** missing **";
                string lineExpected = i < expected.Length ? expected[i] : "** missing **";
                if (lineActual != lineExpected)
                {
                    Console.WriteLine("{0}: Expected: {1} Actual: {2}", (i + 1), lineExpected, lineActual);
                }
            }
        }

        #region Readers

        private static string ReadWord()
        {
            StringBuilder word = new StringBuilder();
            while (reader.Peek() >= 0)
            {
                char c = (char)reader.Read();
                if (Char.IsControl(c) || Char.IsWhiteSpace(c))
                    break;
                word.Append(c);
            }
            return word.ToString();
        }

        private static string ReadLine()
        {
            return reader.ReadLine();
        }

        private static int ReadInt()
        {
            return int.Parse(ReadLine());
        }

        private static T Read<T>()
        {
            return (T)Convert.ChangeType(ReadLine(), typeof(T));
        }

        private static T[] ReadArray<T>()
        {
            return ReadLine().Split(' ').Select(v => (T)Convert.ChangeType(v, typeof(T))).ToArray();
        }

        #endregion
    }
}
