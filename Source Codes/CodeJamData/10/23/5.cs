using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace snap
{
    class C
    {
        static int[,] cache = new int[505,505];
        static int[,] ccCache = new int[505, 505];
        static int mod = 100003;

        public static void Main()
        {
            for (int i = 0; i < 505; i++)
            {
                for (int j = 0; j < 505; j++)
                {
                    cache[i, j] = -1;
                    ccCache[i, j] = -1;
                }
                cache[i, 1] = 1;
            }

            Dictionary<char, int> dic = new Dictionary<char, int>();
            string temp = Console.ReadLine();
            //string[] t;
            int T = int.Parse(temp);
            for (int tc = 0; tc < T; tc++)
            {
                temp = Console.ReadLine();
                int n = int.Parse(temp);
                int res = 0;
                for (int i = 1; i < n; i++)
                {
                    res += GetResult(n, i);
                    res %= mod;
                }
                Console.WriteLine("Case #{0}: {1}", tc + 1, res);

            }
        }

        public static int CC(int m, int n)
        {
            if (m < n)
                return 0;

            if (n == 0)
                return 1;

            if (ccCache[m, n] != -1)
                return ccCache[m, n];
            ccCache[m, n] = (CC(m - 1, n - 1) + CC(m - 1, n)) % mod;
            return ccCache[m, n];
            
        }

        public static int GetResult(int n, int ith)
        {
            if (cache[n, ith] != -1)
                return cache[n, ith];

            long res = 0;
            for (int jth = 1; jth < ith; jth++)
            {
                res += (long)GetResult(ith, jth) * CC(n - ith - 1, ith - jth - 1);
                res %= mod;
            }
            cache[n, ith] = (int)res;
            return (int)res;
        }
    }

}
