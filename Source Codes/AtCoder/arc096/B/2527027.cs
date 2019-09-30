using System;
using System.Collections.Generic;
using System.Linq;

namespace Competitive
{

    internal class Solution
    {
        public long N, C;
        public long[] C1, C2, D1, D2;
        public long[] CSUM1, CSUM2;
        
        public void Run()
        {
            // Input
            {
                var line = Input.ReadLongArray();
                N = line[0];
                C = line[1];
            }

            C1 = new long[N];
            C2 = new long[N];
            D1 = new long[N];
            D2 = new long[N];
            CSUM1 = new long[N];
            CSUM2 = new long[N];

            {
                for (int i = 0; i < N; i++)
                {
                    var line = Input.ReadLongArray();
                    D1[i] = line[0];
                    C1[i] = line[1];
                }

                for (int i = 0; i < N; i++)
                {
                    D2[i] = C - D1[N - 1 - i];
                    C2[i] = C1[N - 1 - i];
                }

                for (int i = 0; i < N; i++)
                {
                    CSUM1[i] = C1[i] + (i == 0 ? 0 : CSUM1[i - 1]);
                    CSUM2[i] = C2[i] + (i == 0 ? 0 : CSUM2[i - 1]);
                }
            }

            long ret = 0;

            // Reverse Maximum
            List<long> RMAX1 = new List<long>();
            List<long> RMAX2 = new List<long>();

            {
                long mx = 0;
                for (int i = 0; i < N; i++)
                {
                    var val = i == 0 ? 0 : CSUM2[i - 1] - D2[i - 1];
                    mx = Math.Max(mx, val);
                    RMAX1.Add(mx);
                }
                RMAX1.Reverse();
            }

            {
                long mx = 0;
                for (int i = 0; i < N; i++)
                {
                    var val = i == 0 ? 0 : CSUM1[i - 1] - D1[i - 1];
                    mx = Math.Max(mx, val);
                    RMAX2.Add(mx);
                }
                RMAX2.Reverse();
            }

            // Solve
            for (int i = 0; i < N; i++)
            {
                ret = Math.Max(ret, CSUM1[i] - D1[i]);
                ret = Math.Max(ret, CSUM2[i] - D2[i]);
                ret = Math.Max(ret, CSUM1[i] - D1[i] * 2 + RMAX1[i]);
                ret = Math.Max(ret, CSUM2[i] - D2[i] * 2 + RMAX2[i]);
            }
            
            Console.WriteLine(ret);
        }
    }

    // libs ----------
    class UnionFind
    {
        public List<int> Par;
        public List<int> Sizes;

        public UnionFind(int n)
        {
            Par = new List<int>();
            Sizes = new List<int>();
            for (int i = 0; i < n; i++)
            {
                Par.Add(i);
                Sizes.Add(1);
            }
        }

        public int Find(int x)
        {
            if (x == Par[x]) return x;
            Par[x] = Find(Par[x]);
            return Par[x];
        }

        public void Unite(int x, int y)
        {
            x = Find(x);
            y = Find(y);
            if (x == y) return;

            if (Sizes[x] < Sizes[y])
            {
                // swap
                int temp = x;
                x = y;
                y = temp;
            }

            Par[y] = x;
            Sizes[x] += Sizes[y];
            Sizes[y] = 0;
        }

        public bool Same(int x, int y)
        {
            return Find(x) == Find(y);
        }

        public int Size(int x)
        {
            return Sizes[Find(x)];
        }
    }

    // common ----------

    internal static class Input
    {
        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static long ReadLong()
        {
            string line = Console.ReadLine();
            return long.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();            
        }

        public static long[] ReadLongArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(long.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(double.Parse).ToArray();
        }
    }
    
    internal class Program
    {
        public static void Main(string[] args)
        {
            var s = new Solution();
            s.Run();
        }
    }
}