using System;
using System.Linq;
using System.Collections.Generic;
 
class P
{
    static void Main(string[] _)
    {
        int n = int.Parse(Console.ReadLine());
        string[] s = new string[n];
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            s[i] = Console.ReadLine();
        }
        for (char c = 'a'; c <= 'z' ; c++)
        {
            int small = int.MaxValue;
            for (int i = 0; i < n; i++)
            {
                int cnt = 0;
                for (int j = 0; j < s[i].Length; j++)
                {
                    if (c == s[i][j])
                    {
                        cnt++;
                    }
                }
                small = Math.Min(cnt, small);
            }
            for (int i = 0; i < small; i++)
            {
                ans += c;
            }
        }
        Console.WriteLine(ans);
    }
}