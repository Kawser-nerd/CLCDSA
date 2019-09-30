using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProgrammingContest_CSharp
{
    class Program
    {
        struct Node
        {
            public int No { get; set; }
            public int InEdges { get; set; }
            public int OutEdges { get; set; }
        }

        static int n, m;
        static Node[] N;
        static long?[,] save;

        static long Solve()
        {
            save = new long?[n, 1 << n];

            return N.Where(node => node.InEdges == 0)
                    .Select(node => Solve(node.No, 1 << node.No))
                    .Sum();
        }

        static long Solve(int no, int bit)
        {
            if (save[no, bit].HasValue)
                return save[no, bit].GetValueOrDefault();
            if (bit == (1 << n) - 1)
                return 1;

            Node current = N[no];
            long ans = 0;

            for (int i = 0; i < n; i++)
            {
                if ((bit & (1 << i)) != 0)
                    continue;

                int nextBit = bit | (1 << i);

                if ((N[i].InEdges & ~nextBit) == 0)
                    ans += Solve(i, nextBit);
            }

            save[no, bit] = ans;
            return ans;
        }

        static void Main(string[] args)
        {
            var e = Console.ReadLine().Split().Select(int.Parse).ToArray();
            n = e[0]; m = e[1];
            N = Enumerable.Range(0, n).Select(no => new Node() { No = no }).ToArray();

            for (int i = 0; i < m; i++)
            {
                e = Console.ReadLine().Split().Select(int.Parse).ToArray();
                int x = e[0] - 1, y = e[1] - 1;
                N[x].OutEdges |= 1 << y;
                N[y].InEdges |= 1 << x;
            }

            long ans = Solve();
            Console.WriteLine(ans);
        }
    }
}