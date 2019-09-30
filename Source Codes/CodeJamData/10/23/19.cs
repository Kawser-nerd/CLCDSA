using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam.CodeJam_2010
{
    class PureRank
    {
        Dictionary<int, int> solves = new Dictionary<int, int>();
        int solve(int n)
        {
            if (solves.ContainsKey(n)) return solves[n];

            int ans = 0;
            for (int i = 0; i < (1 << (n - 2)); i++)
            {
                List<int> set = new List<int>();
                for (int j = 0; j <= 26; j++)
                {
                    if (((1 << j) & i) != 0) set.Add(j + 2);
                }
                set.Add(n);
                int cur = n;
                bool ok = true;
                while (cur != 1)
                {
                    int ind = set.IndexOf(cur) + 1;
                    if (ind == 1) break;
                    if (set.Contains(ind)) cur = ind;
                    else
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok) ans++;
            }
            ans %= 100003;
            solves[n] = ans;
            return ans;
        }

        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(args[0]);
            StreamWriter sw = new StreamWriter("CodeJam.out");

            var obj = new PureRank();

            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                var t = int.Parse(sr.ReadLine());

                int res = obj.solve(t);
                sw.WriteLine("Case #{0}: {1}", i, res);
                Console.WriteLine("Case #{0}: {1}", i, res);
            }

            sr.Close();
            sw.Close();
        }
    }
}
