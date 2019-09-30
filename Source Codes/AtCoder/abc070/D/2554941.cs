using System;
using System.Collections;
using System.Collections.Generic;

namespace Abc070d
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            List<Branch> branches = new List<Branch>();
            for (int i = 0; i < n - 1; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                branches.Add(new Branch(int.Parse(input[0]), int.Parse(input[1]), int.Parse(input[2])));
            }

            string[] query = Console.ReadLine().Split(' ');
            int qNum = int.Parse(query[0]);
            int k = int.Parse(query[1]);

            Point[] points = new Point[n + 1];
            for (int i = 0; i < n; i++)
            {
                points[i + 1] = new Point();
            }
            foreach (Branch branch in branches)
            {
                points[branch.From].Add(branch);
                points[branch.To].Add(branch);
            }

            long[] dp = new long[n + 1];
            dp[k] = 0;
            List<int> queue = new List<int>();
            queue.Add(k);
            
            while (queue.Count > 0)
            {
                int current = queue[0];
                queue.RemoveAt(0);
                Point found = points[current];
                foreach (Branch branch in found)
                {
                    int other = branch.other(current);
                    if (dp[other] != 0)
                    {
                        continue;
                    }
                    dp[other] = dp[current] + branch.Distance;
                    queue.Add(other);
                }
            }

            for (int i = 0; i < qNum; i++)
            {
                string[] q = Console.ReadLine().Split(' ');
                int x = int.Parse(q[0]);
                int y = int.Parse(q[1]);

                Console.WriteLine(dp[x] + dp[y]);
            }
        }
    }

    class Point : List<Branch>
    {
    }

    class Branch
    {
        public readonly int From;
        public readonly int To;
        public readonly int Distance;

        public Branch(int from, int to, int distance)
        {
            From = from;
            To = to;
            Distance = distance;
        }

        public int other(int current)
        {
            if (current == From)
            {
                return To;
            }

            if (current == To)
            {
                return From;
            }

            throw new Exception();
        }
    }
}