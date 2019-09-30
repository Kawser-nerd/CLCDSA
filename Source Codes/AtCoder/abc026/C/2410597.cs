using System;
using System.Collections.Generic;

namespace abc026_c
{
    class Program
    {
        static List<int>[] list;
        static int hoge(int x)
        {
            if (list[x].Count == 0) return 1;
            int max = 0; int min = 1000000000;
            foreach (var item in list[x])
            {
                max = Math.Max(max, hoge(item));
                min = Math.Min(min, hoge(item));
            }
            return max + min + 1;
        }
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            list = new List<int>[n];
            for (int i = 0; i < n; i++) list[i] = new List<int>();
            for (int i = 1; i < n; i++)
            {
                list[int.Parse(Console.ReadLine()) - 1].Add(i);
            }
            Console.WriteLine(hoge(0));
        }
    }
}