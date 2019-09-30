using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int a = Console.ReadLine().Split().Select(int.Parse).ToArray()[1];
        string s = Console.ReadLine();
        int res = 0;
        int tab = 1;
        foreach (char c in s)
        {
            if (c == '+') tab++;
            if (c == '-') tab--;
            if (tab > a)
            {
                res++;
                tab = 1;
            }
        }
        Console.WriteLine(res);
    }
}