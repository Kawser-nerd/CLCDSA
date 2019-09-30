using System;
using System.Collections.Generic;

namespace etc
{
    class Program
    {
        static List<char> ans;
        static List<string> combine;
        static List<string> opposed;

        private static void update(char c)
        {
            if (ans.Count == 0)
            {
                ans.Add(c);
                return;
            }
            foreach (string com in combine)
            {
                if (com[0] == ans[ans.Count - 1] && com[1] == c || com[1] == ans[ans.Count - 1] && com[0] == c)
                {
                    ans.RemoveAt(ans.Count - 1);
                    ans.Add(com[2]);
                    return;
                }
            }
            foreach (char cc in ans)
            {
                foreach (string op in opposed)
                {
                    if (op[0] == cc && op[1] == c || op[1] == cc && op[0] == c)
                    {
                        ans.Clear();
                        return;
                    }
                }
            }
            ans.Add(c);
        }

        public static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                string[] vals = Console.ReadLine().Split(null);
                int cur = 0;
                int c = int.Parse(vals[cur++]);
                combine = new List<string>();
                for (int j = 0; j < c; ++j)
                {
                    combine.Add(vals[cur++]);
                }
                int d = int.Parse(vals[cur++]);
                opposed = new List<string>();
                for (int j = 0; j < d; ++j)
                {
                    opposed.Add(vals[cur++]);
                }
                int n = int.Parse(vals[cur++]);
                string invoke = vals[cur];
                ans = new List<char>();
                for (int j = 0; j < n; ++j)
                {
                    update(invoke[j]);
                }
                Console.Write("Case #{0}: [", i + 1);
                for (int j = 0; j < ans.Count - 1; ++j)
                {
                    Console.Write(ans[j] + ", ");
                }
                if (ans.Count > 0)
                {
                    Console.Write(ans[ans.Count - 1]);
                }
                Console.WriteLine("]");
            }
        }
    }
}
