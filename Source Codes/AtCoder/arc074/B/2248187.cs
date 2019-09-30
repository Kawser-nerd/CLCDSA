using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class PriorityQueue<T>
    {
        private readonly List<T> m_list;
        private readonly Func<T, T, int> m_compare;
        private int m_count;
        public PriorityQueue(Func<T, T, int> compare)
        {
            m_list = new List<T>();
            m_compare = compare;
            m_count = 0;
        }
        private int Add(T value)
        {
            if (m_count == m_list.Count)
            {
                m_list.Add(value);
            }
            else
            {
                m_list[m_count] = value;
            }
            return m_count++;
        }
        private void Swap(int a, int b)
        {
            T tmp = m_list[a];
            m_list[a] = m_list[b];
            m_list[b] = tmp;
        }
        public void Enqueue(T value)
        {
            int c = Add(value);
            while (c > 0)
            {
                int p = (c - 1) / 2;
                if (m_compare(m_list[c], m_list[p]) < 0) { Swap(p, c); } else { break; }
                c = p;
            }
        }
        public T Dequeue()
        {
            T value = m_list[0];
            m_list[0] = m_list[--m_count];
            int p = 0;
            while (true)
            {
                int c1 = p * 2 + 1;
                int c2 = p * 2 + 2;
                if (c1 >= m_count) { break; }
                int c = (c2 >= m_count || m_compare(m_list[c1], m_list[c2]) < 0) ? c1 : c2;
                if (m_compare(m_list[c], m_list[p]) < 0) { Swap(p, c); } else { break; }
                p = c;
            }
            return value;
        }
    }

    class Program
    {
        private const int MODULO = 1000000007;
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        static long Solve(int N, int[] A)
        {
            PriorityQueue<int> queue1 = new PriorityQueue<int>((a, b) => a - b);
            PriorityQueue<int> queue2 = new PriorityQueue<int>((a, b) => b - a);
            long[] sums1 = new long[N + 1];
            long[] sums2 = new long[N + 1];
            for (int i = 0; i < N; ++i)
            {
                int L = A[i];
                int R = A[3 * N - 1 - i];
                queue1.Enqueue(L);
                queue2.Enqueue(R);
                sums1[0] += L;
                sums2[N] += R;
            }
            for (int i = 1; i <= N; ++i)
            {
                int L = A[N + i - 1];
                int R = A[2 * N - i];
                int j = N - i;
                queue1.Enqueue(L);
                queue2.Enqueue(R);
                sums1[i] = sums1[i - 1];
                sums1[i] += L;
                sums1[i] -= queue1.Dequeue();
                sums2[j] = sums2[j + 1];
                sums2[j] += R;
                sums2[j] -= queue2.Dequeue();
            }
            long max = long.MinValue;
            for (int i = 0; i <= N; ++i)
            {
                max = Math.Max(sums1[i] - sums2[i], max);
            }
            return max;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            int[] A = ReadInts();
            Console.WriteLine(Solve(N, A));
        }
    }
}