using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

public static class Program
{
    static void Main()
    {
        char[] s = Console.ReadLine().ToCharArray();
        char[] t = Console.ReadLine().ToCharArray();
        Dictionary<char,char> S_pair = new Dictionary<char, char>();
        Dictionary<char, char> T_pair = new Dictionary<char, char>();
        String ans = "Yes";
        for (int i = 0; i < s.Length; i++)
        {
            if (S_pair.ContainsKey(s[i]) && S_pair[s[i]] != t[i])
            {
                ans = "No";
            }
            else if (T_pair.ContainsKey(t[i]) && T_pair[t[i]] != s[i])
            {
                ans = "No";
            }
            else
            {
                S_pair[s[i]] = t[i];
                T_pair[t[i]] = s[i];
            }
        }
        Console.WriteLine(ans);
    }
}