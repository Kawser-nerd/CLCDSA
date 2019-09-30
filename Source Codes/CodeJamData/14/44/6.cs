using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemD
{
    class Program
    {
        static int M;
        static int N;
        static List<string> S;
        static List<string>[] Ti;

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            int T = Convert.ToInt32(Console.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                var MN = Console.ReadLine().Split(' ');
                M = Convert.ToInt32(MN[0]);
                N = Convert.ToInt32(MN[1]);
                S = new List<string>();
                for (int m = 0; m < M; ++m)
                    S.Add(Console.ReadLine());
                Ti = Enumerable.Range(0, N).Select(n => new List<string>()).ToArray();
                var result = Recurse(0);
                Console.WriteLine("Case #{0}: {1} {2}", t, result.Item1, result.Item2);
            }
        }

        static Tuple<int, int> Recurse(int s)
        {
            if (s < M)
            {
                int max = 0;
                int count = 0;
                for (int n = 0; n < N; ++n)
                {
                    Ti[n].Add(S[s]);
                    var tuple = Recurse(s + 1);
                    Ti[n].Remove(S[s]);
                    if (tuple.Item1 > max)
                    {
                        max = tuple.Item1;
                        count = tuple.Item2;
                    }
                    else if (tuple.Item1 == max)
                        count += tuple.Item2;
                }
                return Tuple.Create(max, count);
            }
            else
            {
                if (Ti.Any(t => t.Count == 0))
                    return Tuple.Create(0, 0);
                int count = 0;
                for (int n = 0; n < N; ++n)
                {
                    var dedup = new HashSet<string>();
                    foreach (var ti in Ti[n])
                        for (int l = 0; l <= ti.Length; ++l)
                            dedup.Add(ti.Substring(0, l));
                    count += dedup.Count;
                }
                return Tuple.Create(count, 1);
            }
        }
    }
}
