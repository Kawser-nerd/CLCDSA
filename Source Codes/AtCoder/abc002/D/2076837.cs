using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC002D
{
    class Program
    {
        static int[,] pairs;
        static int N;
        static int M;
        static void Main(string[] args)
        {
            var line1 = Console.ReadLine().Split().Select(int.Parse).ToArray();
            N = line1[0];
            M = line1[1];

            pairs = new int[N, N];
            for (int i = 0; i < M; i++)
            {
                var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
                pairs[line[0] - 1, line[1] - 1] = 1;
            }

            Solve(new List<int>());

            Console.WriteLine(max);
            Console.ReadKey();
        }

        static int max;
        static void Solve(List<int> group, int k = 0)
        {
            if (k == N)
            {
                for(int i = 0; i < group.Count; i++)
                {
                    for(int j = i + 1; j < group.Count; j++)
                    {
                        if (pairs[group[i], group[j]] == 0) return;
                    }
                }
                max = new int[] { max, group.Count }.Max();
            }
            else
            {
                Solve(group, k + 1);
                group.Add(k);
                Solve(group, k + 1);
                group.RemoveAt(group.Count - 1);
            }
        }
    }
}