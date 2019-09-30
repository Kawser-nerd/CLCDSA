using System;
using System.Linq;
using System.Collections.Generic;
class c
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var list = new List<int> { 105, 135, 165, 189, 195 };
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            if (list.Contains(i)) ans++;
        }
        Console.WriteLine(ans);
    }
}