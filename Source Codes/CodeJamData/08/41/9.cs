using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static int[,] mintochange;
        static int[] gates;
        static int M;
        const int INF = 100000;
        static int minchange(int node, int val)
        {
            if (mintochange[node, val] != -1)
                return mintochange[node, val];
            int g = gates[node];
            if (node >= (M - 1) / 2)
            {
                if (val == g)
                    return 0;
                return INF;
            }
            int rtn = INF;
            if (g / 2 == 1)  //AND gate
            {
                int and;
                if (val == 1)
                    and = minchange(node * 2 + 1, 1) + minchange(node * 2 + 2, 1);
                else
                    and = Math.Min(minchange(node * 2 + 1, 0), minchange(node * 2 + 2, 0));
                if (and < rtn)
                    rtn = and;
                if (g % 2 == 1)
                {
                    int or;
                    if (val == 1)
                        or = Math.Min(minchange(node * 2 + 1, 1), minchange(node * 2 + 2, 1)) + 1;
                    else
                        or = minchange(node * 2 + 1, 0) + minchange(node * 2 + 2, 0) + 1;
                    if (or < rtn)
                        rtn = or;
                }
            }
            else
            {
                int or;
                if (val == 1)
                    or = Math.Min(minchange(node * 2 + 1, 1), minchange(node * 2 + 2, 1));
                else
                    or = minchange(node * 2 + 1, 0) + minchange(node * 2 + 2, 0);
                if (or < rtn)
                    rtn = or;

                if (g % 2 == 1)
                {
                    int and;
                    if (val == 1)
                        and = minchange(node * 2 + 1, 1) + minchange(node * 2 + 2, 1)+1;
                    else
                        and = Math.Min(minchange(node * 2 + 1, 0), minchange(node * 2 + 2, 0))+1;
                    if (and < rtn)
                        rtn = and;
                }
            }
            mintochange[node, val] = rtn;
            return rtn;
        }
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(args[0]);
            int N = int.Parse(sr.ReadLine());
            for (int t = 1; t <= N; t++)
            {
                string[] split = sr.ReadLine().Split();
                M = int.Parse(split[0]);
                int V = int.Parse(split[1]);
                gates = new int[M];
                mintochange = new int[M, 2];
                for (int i = 0; i < M; i++)
                {
                    mintochange[i, 0] = mintochange[i, 1] = -1;
                }
                for (int i = 0; i < (M - 1) / 2; i++)
                {
                    split = sr.ReadLine().Split();
                    gates[i] = 2 * int.Parse(split[0]) + int.Parse(split[1]);
                }
                for (int i = (M - 1) / 2; i < M; i++)
                {
                    gates[i] = int.Parse(sr.ReadLine());
                }
                int n = minchange(0, V);
                if (n != INF)
                    Console.WriteLine("Case #{0}: {1}", t, minchange(0, V));
                else
                    Console.WriteLine("Case #{0}: IMPOSSIBLE", t);
            }
        }
    }
}
