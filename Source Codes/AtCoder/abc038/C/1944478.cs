using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        List<int> count = new List<int>();
        int last = a[0];
        int nowstreak = 1;
        for (int i = 1; i < a.Length; i++)
        {
            if (last >= a[i])
            {
                count.Add(nowstreak);
                nowstreak = 0;
            }
            nowstreak++;
            last = a[i];
        }
        count.Add(nowstreak);
        Console.WriteLine(count.Sum(x => (long)x * (x + 1) / 2));
    }
}