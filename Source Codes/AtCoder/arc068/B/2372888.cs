using System;
using System.Collections.Generic;
using System.Linq;

namespace arc068_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 0; i < n; i++)
            {
                if (!dic.ContainsKey(x[i])) dic[x[i]] = 0;
                dic[x[i]]++;
            }
            int ret = dic.Count();
            int even = ret;
            foreach (var item in dic)
            {
                even -= item.Value % 2;
            }
            Console.WriteLine(ret - even % 2);
        }
    }
}