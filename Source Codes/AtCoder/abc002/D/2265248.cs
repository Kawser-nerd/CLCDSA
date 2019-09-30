using System;
using System.Collections.Generic;
using System.Linq;

namespace abc002_4
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
            int ret = 0;
            for (int i = 1; i < Math.Pow(2,x[0]); i++)
            {
                List<int> now = new List<int>();
                int aa = i;
                for (int j = 0; j < x[0]; j++)
                {
                    if (aa % 2 == 1) now.Add(j);
                    aa /= 2;
                }
                bool flag = true;
                for (int j = 0; j < now.Count(); j++)
                {
                    for (int k = j + 1; k < now.Count(); k++)
                    {
                        if (!edge[now[j],now[k]]) flag = false;
                    }
                }
                if (flag) ret = Math.Max(ret,now.Count());
            }
            Console.WriteLine(ret);
        }
    }
}