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
        int[] a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        Dictionary<int, int> map = new Dictionary<int, int>();

        for (int i = -1; i < 100002; i++)
        {
            map[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (map.ContainsKey(a[i])) {
                map[a[i]]++;
            }
            else
            {
                map[a[i]] = 1;
            }
        }

        long ans = map.Values.Max();

        for(int i = 0; i < n; i++)
        {
            ans = Math.Max(ans, map[i - 1] + map[i] + map[i + 1]);
        }

        Console.WriteLine(ans);
    }
}