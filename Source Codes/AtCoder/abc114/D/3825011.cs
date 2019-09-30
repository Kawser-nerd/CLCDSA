using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Runtime.InteropServices;

namespace Contest
{
    class Scanner
    {
        private string[] line = new string[0];
        private int index = 0;

        public string Next()
        {
            if (line.Length <= index)
            {
                line = Console.ReadLine().Split(' ');
                index = 0;
            }

            var res = line[index];
            index++;
            return res;
        }

        public int NextInt()
        {
            return int.Parse(Next());
        }

        public long NextLong()
        {
            return long.Parse(Next());
        }

        public ulong NextUlong()
        {
            return ulong.Parse(Next());
        }

        public string[] Array()
        {
            line = Console.ReadLine().Split(' ');
            index = line.Length;
            return line;
        }

        public int[] IntArray()
        {
            var array = Array();
            var result = new int[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = int.Parse(array[i]);
            }

            return result;
        }

        public long[] LongArray()
        {
            var array = Array();
            var result = new long[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = long.Parse(array[i]);
            }

            return result;
        }
    }

    class Program
    {
        private int N;

        void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
        }

        public void Solve()
        {
            Scan();
            var map = new Dictionary<int, int>();
            var prime = new int[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
            int pp = prime.Length;
            foreach (var i in prime)
            {
                map[i] = 0;
            }
            for (int i = 2; i <= N; i++)
            {
                int cp = i;
                foreach (var p in prime)
                {
                    if (cp == 1) break;
                    if (cp % p == 0)
                    {
                        while (cp % p == 0)
                        {
                            map[p]++;
                            cp /= p;
                        }
                    }
                }
            }

            var cnt = map.Select(p => p.Value).ToArray();
            int ans = 0;
            for (int i = 0; i < pp; i++)
            {
                for (int j = 0; j < pp; j++)
                {
                    if (i == j) continue;
                    if ((cnt[i] >= 14) && (cnt[j] >= 4))
                    {
                        ans++;
                    }

                    if ((cnt[i] >= 24) && (cnt[j] >= 2))
                    {
                        ans++;
                    }
                }
            }

            for (int i = 0; i < pp - 1; i++)
            {
                for (int j = i + 1; j < pp; j++)
                {
                    for (int k = 0; k < pp; k++)
                    {
                        if (i == k || j == k) continue;
                        if (cnt[i] >= 4 && cnt[j] >= 4 && cnt[k] >= 2)
                            ans++;
                    }
                }
            }

            foreach (var i in cnt)
            {
                if (i >= 74)
                {
                    ans++;
                }
            }
            Console.WriteLine(ans);
        }

        static void Main() => new Program().Solve();
    }


}