using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        string[] cin = Console.ReadLine().Split();

        int a = int.Parse(cin[0]);
        int b = int.Parse(cin[1]);
        int k = int.Parse(cin[2]);

        int cnt = 0;
        int ans = 0;
        for (int i = 100; 0 < i; i--)
        {
            if (a % i == 0 && b % i == 0) cnt++;
            if (cnt == k)
            {
                ans = i;
                break;
            }
        }
        Console.WriteLine(ans);
    }
}