using System;
using System.Linq;
using System.Collections.Generic;
class c
{
    static void Main()
    {
        var inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var list = new List<int>();
        for (int i = 0; i < inp[0]; i++) list.Add(int.Parse(Console.ReadLine()));
        list = list.OrderBy(f => f).ToList();
        int bus = 1;
        int first = list[0];
        int ans = 0;
        for (int i = 1; i < inp[0]; i++)
        {
            if (first + inp[2] < list[i] || bus == inp[1])
            {
                bus = 1;
                first = list[i];
                ans++;
            }
            else bus++;
        }
        Console.WriteLine(ans + 1);
    }
}