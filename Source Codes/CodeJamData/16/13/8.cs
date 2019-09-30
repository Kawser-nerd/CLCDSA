using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static int line(List<int>[] R, int p, int e)
        {
            int res = 0;
            if (R[p] != null)
            {
                foreach (var i in R[p])
                {
                    if (i != e)
                        res = Math.Max(res, line(R, i, e) + 1);
                }
            }
            return res;
        }
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int C = 1; C <= T; C++)
            {
                int N = int.Parse(Console.ReadLine());
                string[] strF = Console.ReadLine().Split(null);
                int[] F = new int[N];
                List<int>[] R = new List<int>[N];
                for (int i = 0; i < N; i++)
                {
                    F[i] = int.Parse(strF[i]) - 1;
                    if (R[F[i]] == null)
                        R[F[i]] = new List<int>();
                    R[F[i]].Add(i);
                }
                int circle = 0;
                int sum = 0;
                bool[] visited = new bool[N];
                for (int i = 0; i < N; i++)
                {
                    int[] v = new int[N];
                    int p = i;
                    int d = 1;
                    while (v[p] == 0 && !visited[p])
                    {
                        visited[p] = true;
                        v[p] = d;
                        p = F[p];
                        d++;
                    }
                    if (v[p] != 0)
                    {
                        circle = Math.Max(circle, d - v[p]);
                        if (d - v[p] == 2)
                        {
                            sum += 2 + line(R, p, F[p]) + line(R, F[p], p);
                        }
                    }
                }
                Console.WriteLine("Case #" + C + ": " + Math.Max(circle, sum));
            }
        }
    }
}
