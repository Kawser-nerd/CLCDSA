using System;
using System.Collections.Generic;

namespace arc035_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            Dictionary<int, int> dic = new Dictionary<int, int>();
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                int x = int.Parse(Console.ReadLine());
                a[i] = x;
                if (!dic.ContainsKey(x)) dic[x] = 0;
                dic[x]++;
            }
            Array.Sort(a);
            long time = 0; long sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += a[i];
                time += sum;
            }
            Console.WriteLine(time);
            long ret = 1;
            foreach (var item in dic)
            {
                for (int i = 1; i <= item.Value; i++)
                {
                    ret *= i; ret %= (int)Math.Pow(10, 9) + 7;
                }
            }
            Console.WriteLine(ret);
        }
    }
}