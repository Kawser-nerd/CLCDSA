using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace IncreasingSpeedLimits
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            for (int case_nr = 1; case_nr <= N; case_nr++)
            {
                string[] ss = Console.ReadLine().Split(' ');
                int n = int.Parse(ss[0]);
                int m = int.Parse(ss[1]);
                long X = int.Parse(ss[2]);
                long Y = int.Parse(ss[3]);
                int Z = int.Parse(ss[4]);
                int[] signs = new int[n];
                int[] A = new int[m];
                for (int i = 0; i < m; i++)
                    A[i] = int.Parse(Console.ReadLine());
                for (int i = 0; i<n; i++) {
                    signs[i] = A[i%m];
                    A[i % m] = (int)((X * A[i % m] + Y * (i + 1)) % Z);
                }
                Console.WriteLine("Case #{0}: {1}", case_nr, SpeedLimits(n, signs));
            }
        }

        private static long SpeedLimits(int n, int[] signs)
        {
            long result = 0;
            long[] cnt = new long[n];
            for (int i = 0; i < n; i++)
            {
                long val = 1;
                for (int j = 0; j < i; j++)
                    if (signs[j] < signs[i])
                        val = (val + cnt[j]) % 1000000007;
                cnt[i] = val;
                result = (result + val) % 1000000007;
            }
            return result;
        }
    }
}
