using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _008
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[][] xytrs = new int[n][];
            for (int i = 0; i < n; i++) xytrs[i] = ReadInts();
            double[] length = new double[n];
            for (int i = 0; i < n; i++) length[i] = double.MaxValue;
            PriorityQueue<int> queue = new PriorityQueue<int>();
            queue.Enqueue(0, 0);
            while (queue.Exist())
            {
                KeyValuePair<double, int> pair = queue.Dequeue();
                double dist = pair.Key;
                int index = pair.Value;
                if (length[index] <= dist) continue;

                length[index] = dist;
                for(int i = 0; i < n; i++)
                {
                    if (i == pair.Value) continue;
                    double distance = Sqrt(
                        Pow(xytrs[i][0] - xytrs[index][0], 2)
                        + Pow(xytrs[i][1] - xytrs[index][1], 2));
                    double len = distance / Min(xytrs[index][2], xytrs[i][3]);
                    queue.Enqueue(dist + len, i);
                }
            }
            Array.Sort(length);
            double res = 0;
            for(int i = 1; i < n; i++)
            {
                res = Max(res, length[i] + n - i - 1);
            }
            WriteLine(res);
        }

        class PriorityQueue<T>
        {
            private readonly List<KeyValuePair<double, T>> list;
            private int count;

            public PriorityQueue()
            {
                list = new List<KeyValuePair<double, T>>();
                count = 0;
            }

            private void Add(KeyValuePair<double, T> pair)
            {
                if (count == list.Count)
                {
                    list.Add(pair);
                }
                else
                {
                    list[count] = pair;
                }
                count++;
            }

            private void Swap(int a, int b)
            {
                KeyValuePair<double, T> tmp = list[a];
                list[a] = list[b];
                list[b] = tmp;
            }

            public void Enqueue(double key, T value)
            {
                Add(new KeyValuePair<double, T>(key, value));
                int c = count - 1;
                while (c > 0)
                {
                    int p = (c - 1) / 2;
                    if (list[c].Key >= list[p].Key) break;

                    Swap(p, c);
                    c = p;
                }
            }

            public KeyValuePair<double, T> Dequeue()
            {
                KeyValuePair<double, T> pair = list[0];
                count--;
                if (count == 0) return pair;

                list[0] = list[count];
                int p = 0;
                while (true)
                {
                    int c1 = p * 2 + 1;
                    int c2 = p * 2 + 2;
                    if (c1 >= count) break;

                    int c = (c2 >= count || list[c1].Key < list[c2].Key)
                        ? c1 : c2;
                    if (list[c].Key >= list[p].Key) break;

                    Swap(p, c);
                    p = c;
                }
                return pair;
            }

            public bool Exist() { return count > 0; }
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}