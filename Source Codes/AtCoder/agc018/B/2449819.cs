using System;
using System.Collections.Generic;
using System.Linq;

namespace agc018_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            List<int>[] list = new List<int>[x[0]];
            for (int i = 0; i < x[0]; i++) list[i] = new List<int>();
            for (int i = 0; i < x[0]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                for (int j = 0; j < x[1]; j++) list[i].Add(a[j]);
            }
            int ret = int.MaxValue;
            while (list[0].Count > 0)
            {
                Dictionary<int, int> dic = new Dictionary<int, int>();
                for (int i = 0; i < x[0]; i++)
                {
                    if (!dic.ContainsKey(list[i][0])) dic[list[i][0]] = 0;
                    dic[list[i][0]]++;
                }
                int max = 0;
                List<int> remove = new List<int>();
                foreach (var item in dic)
                {
                    if (item.Value > max)
                    {
                        remove.Clear();
                    }
                    if (item.Value >= max)
                    {
                        max = item.Value;
                        remove.Add(item.Key);
                    }
                }
                ret = Math.Min(ret, max);
                for (int i = 0; i < x[0]; i++)
                {
                    foreach (var item in remove) list[i].Remove(item);
                }
            }
            Console.WriteLine(ret);
        }
    }
}