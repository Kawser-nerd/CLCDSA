using System;
using System.Collections.Generic;
using System.Linq;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public string S;
        public List<int> CT;
        public List<int> CH;
        public int L;
        public int[] X1, X2;
        public int NN;
        public PascalCombination COMB;

        public void Run()
        {
            N = Input.ReadInt();
            S = Console.ReadLine();

            CH = new List<int>();
            CT = new List<int>();

            int prev = -1;
            int count = 1;
            for (int i = 0; i < N * 2; i++)
            {
                int ch = S[i] - 'a';
                if (prev == ch)
                {
                    count++;
                }
                else
                {
                    if (prev != -1)
                    {
                        CH.Add(prev);
                        CT.Add(count);
                    }
                    prev = ch;
                    count = 1;
                }

                if (i == 2 * N - 1)
                {
                    CH.Add(prev);
                    CT.Add(count);
                }
            }

            L = CH.Count;
            COMB = new PascalCombination(40);
            COMB.Run();

            long ret = DFSInit();
            Console.WriteLine(ret);
        }

        long DFSInit()
        {
            X1 = new int[N];
            X2 = new int[N];

            return DFS(0, 0, 0, 1);
        }

        long DFS(int x1, int x2, int ii, long count)
        {
            // Console.Error.WriteLine($"{x1} {x2} {ii} {count}");
            
            // check
            if (x1 == N && x2 == N)
            {
                // Console.Error.WriteLine("{0}, {1}", string.Join("", X1), string.Join("", X2));
                bool flg = true;
                for (int i = 0; i < N; i++)
                {
                    if (X1[i] != X2[N - 1 - i]) return 0;
                }
                return count;
            }

            int ch = CH[ii];
            int ct = CT[ii];

            long ret = 0;

            for (int k = 0; k <= ct; k++)
            {
                int skip = ct - k;
                long comb = COMB.Combination(ct, k);
                if (x1 + k > N) continue;
                if (x2 + skip > N) continue;
                bool flg = true;

                for (int j = 0; j < k; j++)
                {
                    X1[x1 + j] = ch;
                    int jj = x1 + j;
                    int kk = N - 1 - jj;
                    if (kk < x2 && X1[jj] != X2[kk])
                        flg = false;
                }
                for (int j = 0; j < skip; j++)
                {
                    X2[x2 + j] = ch;
                    int jj = x2 + j;
                    int kk = N - 1 - jj;
                    if (kk < (x1 + k) && X1[kk] != X2[jj])
                        flg = false;
                }

                if (!flg) continue;
                ret += DFS(x1 + k, x2 + skip, ii + 1, count * comb);
            }

            return ret;
        }
    }

    // libs ----------

    class PascalCombination
    {
        public long N;
        public long[,] Comb;

        public PascalCombination(int N)
        {
            this.N = N;
            Comb = new long[N + 1, N + 1];
        }

        public void Run()
        {
            // i == 0????
            Comb[0, 0] = 1;

            // i => 1????
            for (int i = 1; i <= N; i++)
            {
                for (int j = 0; j <= N; j++)
                    if (j == 0)
                    {
                        Comb[i, j] = 1;
                    }
                    else
                    {
                        Comb[i, j] = Comb[i - 1, j - 1] + Comb[i - 1, j];
                    }
            }
        }

        public long Combination(int n, int k)
        {
            if (k < 0 || k > n) return 0;
            return Comb[n, k];
        }

    }


    // common ----------

    internal static class Input
    {
        public static string ReadString()
        {
            string line = Console.ReadLine();
            return line;
        }

        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();            
        }

        public static long ReadLong()
        {
            string line = Console.ReadLine();
            return long.Parse(line);
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