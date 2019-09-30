using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace AtTest.ABC116
{
    class D
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nk = ReadInts();
            int n = nk[0];
            int k = nk[1];
            long[][] tds = new long[n][];
            for(int i = 0; i < n; i++)
            {
                tds[i] = ReadLongs();
            }
            tds = tds.OrderBy(a => -a[1]).ToArray();
            var kindDict = new Dictionary<long, bool>();
            var surQueue = new PriorityQueue<long>();
            long f = 0;
            for (int i = 0; i < k; i++)
            {
                if (kindDict.ContainsKey(tds[i][0]))
                {
                    surQueue.Enqueue(tds[i][1], tds[i][0]);
                }
                else
                {
                    kindDict.Add(tds[i][0], true);
                }
                f += tds[i][1];
            }
            long kindCnt = kindDict.Count;
            var remainQueue = new PriorityQueue<long>();
            for (int i = k; i < n; i++)
            {
                if (kindDict.ContainsKey(tds[i][0])) continue;
                else
                {
                    kindDict.Add(tds[i][0], true);
                    remainQueue.Enqueue(-tds[i][1], tds[i][0]);
                }
            }
            long res = f + kindCnt * kindCnt;
            while (surQueue.Exist() && remainQueue.Exist())
            {
                long surplus = surQueue.Dequeue().Key;
                f -= surplus;
                long remain = remainQueue.Dequeue().Key;
                f -= remain;
                kindCnt++;
                res = Math.Max(res, f + kindCnt * kindCnt);
            }
            Console.WriteLine(res);
        }

        class PriorityQueue<T>
        {
            private readonly List<KeyValuePair<long, T>> list;
            private int count;

            public PriorityQueue()
            {
                list = new List<KeyValuePair<long, T>>();
                count = 0;
            }

            private void Add(KeyValuePair<long, T> pair)
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
                KeyValuePair<long, T> tmp = list[a];
                list[a] = list[b];
                list[b] = tmp;
            }

            public void Enqueue(long key, T value)
            {
                Add(new KeyValuePair<long, T>(key, value));
                int c = count - 1;
                while (c > 0)
                {
                    int p = (c - 1) / 2;
                    if (list[c].Key >= list[p].Key) break;

                    Swap(p, c);
                    c = p;
                }
            }

            public KeyValuePair<long, T> Dequeue()
            {
                KeyValuePair<long, T> pair = list[0];
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

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}