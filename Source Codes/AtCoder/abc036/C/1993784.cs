using System;
using System.Collections.Generic;

namespace abc036_c
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] zaatu = new int[n];
            SortedList<int,int> list = new SortedList<int,int>();
            for (int i = 0; i < n; i++)
            {
                int now = int.Parse(Console.ReadLine());
                zaatu[i] = now;
                if (!list.ContainsKey(now)) list.Add(now,0);
            }
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine(list.IndexOfKey(zaatu[i]));
            }
        }
    }
}