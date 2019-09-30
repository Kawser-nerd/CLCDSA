using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        string[] cin = Console.ReadLine().Split();
        int n = int.Parse(cin[0]);
        int k = int.Parse(cin[1]);
        List<int> l = Console.ReadLine().Split().Select(i => int.Parse(i)).ToList();

        l.Sort();
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans += l[l.Count - i - 1];
        }
        Console.WriteLine(ans);
    }
}