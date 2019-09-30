using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public long N, K;
        public long MOD = 1000000007;

        public void Run()
        {
            {
                var line = Input.ReadLongArray();
                N = line[0];
                K = line[1];
                var divisors = Divisors(N);
                var D = divisors.Count;
                var C = new long[D];
                var CC = new long[D];

                for (int i = 0; i < D; i++)
                {
                    long d = divisors[i];
                    C[i] = RotationCount(d);
                }

                for (int i = 0; i < D; i++)
                {
                    CC[i] = C[i];
                    for (int j = 0; j < i; j++)
                    {
                        if (divisors[i] % divisors[j] == 0)
                        {
                            CC[i] += (MOD - CC[j]);
                            CC[i] %= MOD;
                        }
                    }
                }

                long ret = 0;
                for (int i = 0; i < D; i++)
                {
                    long v = divisors[i];
                    if (v % 2 == 0) v /= 2;
                    ret += CC[i] * v;
                    ret %= MOD;
                }

                Console.WriteLine(ret);
            }
        }

        public long RotationCount(long d)
        {
            // ??D??????(??D??????
            long x = (d + 1) / 2;
            return Power(K, x, MOD);
        }

        // repeat square - (X ** n) % _M
        public static long Power(long x, long n, long M)
        {
            long tmp = 1;

            if (n > 0)
            {
                tmp = Power(x, n / 2, M);
                if (n % 2 == 0) tmp = (tmp * tmp) % M;
                else tmp = (((tmp * tmp) % M) * x) % M;
            }

            return tmp;
        }

        public List<long> Divisors(long x)
        {
            var dict = new Dictionary<long, int>();

            for (int d = 2; d * d <= x; d++)
            {
                while (x % d == 0)
                {
                    if(!dict.ContainsKey(d)) dict.Add(d, 0);
                    dict[d]++;
                    x /= d;
                }
            }

            if(x > 1) dict.Add(x, 1);

            long[] primes = dict.Keys.ToArray();
            int[] ary = dict.Keys.Select(k => dict[k]).ToArray();
            // Console.Error.WriteLine(string.Join(", ", primes));
            // Console.Error.WriteLine(string.Join(", ", ary));

            var bf = new BruteForceArray(primes, ary);
            var divisors = bf.DFSRun();
            return divisors;
        }

    }

    // libs ----------
    // 0/1??????????
    class BruteForceArray
    {
        public int[] Counts;
        public long[] Primes;
        public int N;
        public int[] F;
        public List<long> ret;
        public BruteForceArray(long[] primes, int[] counts)
        {
            this.Primes = primes;
            this.Counts = counts;
            N = counts.Length;
            F = new int[N];
            ret = new List<long>();
        }

        public List<long> DFSRun()
        {
            DFS(0);
            ret.Sort();
            return ret;
        }

        private void DFS(int i)
        {
            if (i == N)
            {
                var divisor = CalcDivisor(F);
                ret.Add(divisor);
            }
            else
            {
                for (int j = 0; j <= Counts[i]; j++)
                {
                    F[i] = j;
                    DFS(i + 1);
                }
            }
        }

        public long CalcDivisor(int[] counts)
        {
            var ret = 1L;
            for (int i = 0; i < Primes.Length; i++)
            {
                for (int j = 0; j < counts[i]; j++)
                {
                    ret *= Primes[i];
                }
            }

            return ret;
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