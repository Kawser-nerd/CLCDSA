using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        string s = Console.ReadLine();
        int ans = 0;
        int cur = 0;
        for (var i = 0; i < s.Length; i++)
        {
            string c = s[i].ToString();
            if (c == "A" || c == "T" || c == "G" || c == "C")
            {
                cur += 1;
            }
            else
            {
                ans = Math.Max(cur, ans);
                cur = 0;
            }
        }
        ans = Math.Max(cur, ans);
        Console.WriteLine(ans);
    }
}