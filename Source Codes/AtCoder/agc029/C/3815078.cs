using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class InfiniteString
    {
        private readonly int K;
        private int n = 0;
        private Dictionary<int, int> letters = new Dictionary<int, int>();
        public InfiniteString(int K)
        {
            this.K = K;
        }
        public bool Cut(int N)
        {
            n = N;
            for (int i = n - 1; i >= 0; --i)
            {
                if (letters.ContainsKey(i))
                {
                    int k = letters[i];
                    if (k < K - 1)
                    {
                        letters[i] = k + 1;
                        return true;
                    }
                    else
                    {
                        letters.Remove(i);
                    }
                }
                else
                {
                    if (K > 1)
                    {
                        letters[i] = 1;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return false;
        }
        public void Expand(int N)
        {
            foreach (int key in letters.Keys.Where(i => n <= i && i < N).ToArray())
            {
                letters.Remove(key);
            }
            n = N;
        }
    }

    class Program
    {
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }

        static bool CanMake(int[] A, int k)
        {
            int n = 0;
            var str = new InfiniteString(k);
            foreach (int a in A)
            {
                if (a <= n)
                {
                    if (!str.Cut(a)) { return false; }
                }
                else
                {
                    str.Expand(a);
                }
                n = a;
            }
            return true;
        }

        static int Solve(int N, int[] A)
        {
            if (CanMake(A, 1)) { return 1; }
            int l = 1;
            int r = N;
            while (r - l >= 2)
            {
                int i = (l + r) / 2;
                if (CanMake(A, i)) { r = i; } else { l = i; }
            }
            return r;
        }

        static void Main(string[] args)
        {
            int N = ReadInt();
            int[] A = ReadInts();
            Console.WriteLine(Solve(N, A));
        }
    }
}