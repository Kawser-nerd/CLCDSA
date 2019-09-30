using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace C
{
    class Program
    {
        static bool[,] intersect;
        static int n, k;
        static int[,] price;
        static List<int> allpossible;
        static int[] DP;
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("C-small-attempt0.in"))
            {
                using (StreamWriter sw = new StreamWriter("C-small-attempt0.out"))
                {
                    int count = int.Parse(sr.ReadLine());
                    for (int tc = 1; tc <= count; tc++)
                    {
                        string[] elem = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                        n = int.Parse(elem[0]);
                        k = int.Parse(elem[1]);
                        price = new int[n, k];
                        for (int i = 0; i < n; i++)
                        {
                            elem = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                            for (int j = 0; j < k; j++)
                                price[i, j] = int.Parse(elem[j]);
                        }

                        intersect = new bool[n, n];
                        for (int i = 0; i < n; i++)
                            for (int j = 0; j < n; j++)
                                if ( i != j ) intersect[i,j] = CheckIntersect(i, j);

                        allpossible = new List<int>();
                        for (int i = 1, lim = (1 << n); i < lim; i++)
                        {
                            bool valid = true;
                            for (int j = 0; j < n && valid; j++)
                                for (int l = j + 1; l < n && valid; l++)
                                    if ((i & (1 << j)) != 0 && (i & (1 << l)) != 0)
                                        if (intersect[j, l])
                                            valid = false;
                            if ( valid )
                                allpossible.Add(i);
                        }
                        DP = new int[1 << n];
                        for (int i = 0, lim = DP.Length; i < lim; i++)
                            DP[i] = int.MaxValue;

                        DP[0] = 0;
                        sw.WriteLine("Case #{0}: {1}", tc, GetMinGroup((1 << n) - 1));
                        Console.WriteLine("Case #{0}: {1}", tc, GetMinGroup((1 << n) - 1));
                    }
                }
            }
        }

        private static int GetMinGroup(int x)
        {
            if (DP[x] < int.MaxValue) return DP[x];

            int res = int.MaxValue;
            for (int i = 0; i < allpossible.Count; i++)
            {
                int y = allpossible[i];
                if ((x & y) == y)
                {
                    res = Math.Min(res, GetMinGroup(x ^ y) + 1);
                }
            }
            DP[x] = res;
            return res;
        }

        static bool CheckIntersect(int a, int b)
        {
            for (int i = 0; i < k; i++)
            {
                if ( price[a, i] == price[b, i]) return true;
                if (i > 0)
                {
                    if (price[a, i - 1] == price[b, i - 1]) return true;
                    if (price[a, i - 1] < price[b, i - 1] && price[a, i] > price[b, i]) return true;
                    if (price[a, i - 1] > price[b, i - 1] && price[a, i] < price[b, i]) return true;
                }
            }

            return false;
        }
    }
}
