using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC029E
{
    class Program
    {
        const int maxN = 200003;
        static int[] ans = new int[maxN];
        static List<int>[] vec = new List<int>[maxN];

        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            {
                for (int i = 0; i < maxN; i++)
                {
                    vec[i] = new List<int>();
                    dp[i] = new Dictionary<int, int>();
                }
                for (int i = 0; i < N - 1; i++)
                {
                    var input = Console.ReadLine().Split().Select(int.Parse).ToArray();
                    vec[input[0]].Add(input[1]);
                    vec[input[1]].Add(input[0]);
                }
            }
            foreach (int i in vec[1])
            {
                dfs(i, 1, 1, 0);
            }
            for (int i = 2; i <= N; i++) Console.Write("{0} ", ans[i]);

            Console.ReadKey();
        }

        static void dfs(int x, int ba, int pr, int cc)
        {
            cc += dfs2(x, ba, Math.Max(ba, pr));
            if (pr > x) cc -= dfs2(x, ba, pr);
            ans[x] = cc;
            foreach (int y in vec[x])
            {
                if (y == ba) continue;  //????????
                dfs(y, x, Math.Max(pr, ba), cc);
            }
        }

        static Dictionary<int, int>[] dp = new Dictionary<int, int>[maxN];
        static int dfs2(int x, int ba, int v)
        {
            if (dp[x].ContainsKey(v)) return dp[x][v];
            int sm = 1;
            foreach (int y in vec[x])
            {
                if (y == ba) continue;
                if (y < v) sm += dfs2(y, x, v);
            }
            return dp[x][v] = sm;
        }
    }
}