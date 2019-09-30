using System;
using System.Collections.Generic;
using System.Linq;

namespace ARC097D
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int n = input[0];
            int m = input[1];

            int[] p = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

            int[] x = new int[m];
            int[] y = new int[m];
            for (int i = 0; i < m; i++)
            {
                int[] line = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
                x[i] = line[0];
                y[i] = line[1];
            }

            UnionFind union = new UnionFind(n);
            for (int i = 0; i < m; i++)
            {
                union.Unite(x[i], y[i]);
            }

            Point[] points = new Point[n + 1];
            for (int i = 0; i <= n; i++)
            {
                points[i] = new Point(i);
            }

            for (int i = 1; i <= n; i++)
            {
                points[union.Root(i)].Add(i);
            }

            int score = 0;
            foreach (Point point in points)
            {
                score += point.Score(p);
            }

            Console.WriteLine(score);
        }

        class Point
        {
            private List<int> X;
            public int M;
            private bool _on;

            public Point(int m)
            {
                M = m;
                X = new List<int>();
            }

            public void Add(int x)
            {
                X.Add(x);
                _on = true;
            }

            private List<int> all()
            {
                List<int> list = new List<int>();
                foreach (int i in X)
                {
                    list.Add(i);
                }

                list.Add(M);
                return list.Distinct().ToList();
            }

            public int Score(int[] p)
            {
                if (!_on)
                {
                    return 0;
                }

                if (M == 0)
                {
                    return 0;
                }

                int[] indexes = all().ToArray();
                var values = new Dictionary<int, bool>();
                for (int i = 0; i < indexes.Length; i++)
                {
                    values[p[indexes[i] - 1]] = true;
                }

                int score = 0;
                for (int i = 0; i < indexes.Length; i++)
                {
                    if (values.ContainsKey(indexes[i]))
                    {
                        score++;
                    }
                }

                return score;
            }
        }
    }

    public class UnionFind
    {
        private int[] par;

        public UnionFind(int maxN)
        {
            par = new int[maxN + 1];
            Init(maxN);
        }

        void Init(int n)
        {
            for (int i = 1; i <= n; i++)
            {
                par[i] = i;
            }
        }

        public int Root(int x)
        {
            if (par[x] == x)
            {
                return x;
            }

            return par[x] = Root(par[x]);
        }

        public bool Same(int x, int y)
        {
            return Root(x) == Root(y);
        }

        public void Unite(int x, int y)
        {
            x = Root(x);
            y = Root(y);
            if (x == y)
            {
                return;
            }

            par[x] = y;
        }
    }
}