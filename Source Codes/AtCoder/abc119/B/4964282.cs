using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            string[] cin = Console.ReadLine().Split();
            if (cin[1] == "JPY") ans += double.Parse(cin[0]);
            else ans += double.Parse(cin[0]) * 380000.0;
        }
        Console.WriteLine(ans);
    }
}