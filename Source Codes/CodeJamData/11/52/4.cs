using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace R3ProblemB
{
    class Program
    {
        static int[] cnt;
        static int n;

        static bool check(int x)
        {
            List<int> cur = new List<int>();
            int top=0;
            for (int i = 1; i <= 10000; ++i)
            {
                while (cur.Count - top > cnt[i])
                {
                    if (cur[top] >= x) top++;
                    else return false;
                }
                while (cur.Count - top < cnt[i])
                {
                    cur.Add(0);
                }
                for (int j = top; j < cur.Count; ++j)
                {
                    cur[j]++;
                }
            }
            while (cur.Count - top > 0)
            {
                if (cur[top] >= x) top++;
                else return false;
            }
            return true;
        }

        static int solve()
        {
            if (n == 0) return 0;
            int lower = 1;
            int upper = n;
            int ans = 1;
            while (lower < upper)
            {
                int mid = (lower + upper) / 2;
                if (check(mid))
                {
                    ans = mid;
                    lower = mid + 1;
                }
                else upper = mid - 1;
            }
            while (check(ans + 1)) ++ans;
            return ans;
        }

        static void Main(string[] args)
        {
            int totalCase = Convert.ToInt32(Console.ReadLine());
            for (int curCase = 0; curCase < totalCase; ++curCase)
            {
                string[] str = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                n = Convert.ToInt32(str[0]);
                cnt = new int[10010];
                for (int i = 0; i < n; ++i)
                {
                    cnt[Convert.ToInt32(str[i + 1])]++;
                }
                //for (int i = n; i >= 0; --i)
                //{
                //    if (check(i))
                //    {
                //        Console.WriteLine("Case #{0}: {1}", curCase + 1, i);
                //        break;
                //    }
                //}
                Console.WriteLine("Case #{0}: {1}", curCase + 1, solve());
            }
        }
    }
}
