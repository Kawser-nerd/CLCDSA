using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;
using System.Text;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        long[] a = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        Dictionary<long, long> map = new Dictionary<long, long>();

        long first_pair = 0;
        long second_pair = 0;

        for(long i = 0; i < n; i++)
        {
            if (map.ContainsKey(a[i]))
            {
                map[a[i]]++;
            }
            else
            {
                map[a[i]] = 1;
            }
        }

        map = map.OrderByDescending(i => i.Key).ToDictionary(i => i.Key, i => i.Value);

        foreach (var item in map)
        {
            long key = item.Key;
            long value = item.Value;

            if (first_pair != 0 && second_pair != 0)
            {
                Console.WriteLine(first_pair * second_pair);
                return;
            }
            if(first_pair == 0)
            {
                if(value >= 2)
                {
                    first_pair = key;
                    value -= 2;
                }
            }

            if(second_pair == 0)
            {
                if (value >= 2)
                {
                    second_pair = key;
                }
            }
        }
        Console.WriteLine(first_pair * second_pair);
    }
}