using System;
using System.Collections.Generic;
using System.Linq;

namespace agc013_b
{
    class Program
    {
        static List<int>[] d;
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            x[0]++;
            d = new List<int>[x[0]];
            for (int i = 0; i < x[0]; i++) d[i] = new List<int>();
            for (int i = 0; i < x[1]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                d[a[0]].Add(a[1]); d[a[1]].Add(a[0]);
            }
            LinkedList<int> ret = new LinkedList<int>();
            ret.AddFirst(1);
            int search = 1;
            bool[] visited = new bool[x[0]];
            while (!visited[search])
            {
                visited[search] = true;
                foreach (var item in d[search])
                {
                    if (!visited[item])
                    {
                        search = item;
                        ret.AddFirst(item);
                        break;
                    }
                }
            }
            search = 1; visited[1] = false;
            while (!visited[search])
            {
                visited[search] = true;
                foreach (var item in d[search])
                {
                    if (!visited[item])
                    {
                        search = item;
                        ret.AddLast(item);
                        break;
                    }
                }
            }
            Console.WriteLine(ret.Count);
            Console.WriteLine(string.Join(" ", ret));
        }
    }
}