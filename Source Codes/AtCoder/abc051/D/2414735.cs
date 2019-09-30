using System;
using System.Linq;

namespace abc051_d
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[,] d = new int[x[0], x[0]];
            int[,] edge = new int[x[1], 3];
            for (int i = 0; i < x[0]; i++)
            {
                for (int j = 0; j < x[0]; j++)
                {
                    if (i == j) continue;
                    d[i, j] = 10000000;
                }
            }
            for (int i = 0; i < x[1]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                a[0]--; a[1]--;
                d[a[0], a[1]] = a[2]; d[a[1], a[0]] = a[2];
                for (int j = 0; j < 3; j++) edge[i, j] = a[j];
            }
            for (int k = 0; k < x[0]; k++)
                for (int i = 0; i < x[0]; i++)
                    for (int j = 0; j < x[0]; j++)
                        d[i, j] = Math.Min(d[i, j], d[i, k] + d[k, j]);
            int ret = x[1];
            for (int i = 0; i < x[1]; i++)
            {
                bool flag = false;
                for (int j = 0; j < x[0] && !flag; j++)
                {
                    for (int k = 0; k < x[0] && !flag; k++)
                    {
                        if (j != edge[i, 0] && k != edge[i, 1])
                        {
                            if (d[j, k] == d[j, edge[i, 1]] + edge[i, 2] + d[edge[i, 0], k])
                                flag = true;
                        }
                        if (j != edge[i, 1] && k != edge[i, 0])
                        {
                            if (d[j, k] == d[j, edge[i, 0]] + edge[i, 2] + d[edge[i, 1], k])
                                flag = true;
                        }
                    }
                }
                if (flag) ret--;
            }
            Console.WriteLine(ret);
        }
    }
}