using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.IO;
using System.Threading;

namespace ConsoleApplication1
{
    class Program
    {
        static int FindBiggestSubtree(int root, int parent, Dictionary<int, List<int>> incindence)
        {
            var inc = incindence[root].Where(j => j != parent).ToArray();
            if (inc.Length <= 1)
                return 1;
            int[] sr = new int[inc.Length];
            for (int i = 0; i < inc.Length; i++)
            {
                int subroot = inc[i];
                sr[i] = FindBiggestSubtree(subroot, root, incindence);
            }
            Array.Sort(sr);
            return 1 + sr[inc.Length-1] + sr[inc.Length-2];
        }

        static int Solve(int N, List<int[]> edges)
        {
            int res = 0;

            Dictionary<int, List<int>> incindence = new Dictionary<int, List<int>>();
            for (int i = 0; i < N; i++)
            {
                incindence[i] = new List<int>();
            }

            foreach (var e in edges)
            {
                incindence[e[0]].Add(e[1]);
                incindence[e[1]].Add(e[0]);
            }

            for (int root = 0; root < N; root++)
            {
                int cur = FindBiggestSubtree(root, -1, incindence);
                res = Math.Max(res, cur);
            }

            return N-res;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            using (StreamReader sr = new StreamReader(args[0]))
            {
                int T = int.Parse(sr.ReadLine());
                for (int i = 0; i < T; i++)
                {
                    int N = int.Parse(sr.ReadLine());
                    List<int[]> edges = new List<int[]>();
                    for (int j = 0; j < N - 1; j++)
                    {
                        int[] splitted = sr.ReadLine().Split(' ').Select(s => int.Parse(s, CultureInfo.InvariantCulture)).ToArray();
                        splitted[0] -= 1;
                        splitted[1] -= 1;
                        edges.Add(splitted);
                    }
                    int res = Solve(N, edges);
                    Console.WriteLine(string.Format("Case #{0}: {1}", i + 1, res));
                }
            }
        }
    }
}
