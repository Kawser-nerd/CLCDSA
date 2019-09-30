using System;
using System.Linq;

namespace abc016_3
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            bool[,] edge = new bool[x[0],x[0]];
            for (int i = 0; i < x[1]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                a[0]--; a[1]--;
                edge[a[0],a[1]] = true; edge[a[1],a[0]] = true;
            }
            for (int i = 0; i < x[0]; i++)
            {
                int ret = 0;
                for (int j = 0; j < x[0]; j++)
                {
                    for (int k = 0; k < x[0]; k++)
                    {
                        if (i != j && j != k && !edge[i,j] && edge[i,k] && edge[j,k])
                        {
                            ret++;
                            break;
                        }
                    }
                }
                Console.WriteLine(ret);
            }
        }
    }
}