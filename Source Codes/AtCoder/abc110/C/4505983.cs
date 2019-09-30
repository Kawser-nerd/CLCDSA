using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        var t = Console.ReadLine();

        var a = new Dictionary<char, char>();
        var b = new Dictionary<char, char>();

        for (int i = 0; i < s.Length; i++)
        {
            if (a.ContainsKey(s[i]) && a[s[i]] != t[i])
            {
                Console.WriteLine("No");
                return;
            }
            else if (b.ContainsKey(t[i]) && b[t[i]] != s[i])
            {
                Console.WriteLine("No");
                return;
            }
            else
            {
                a[s[i]] = t[i];
                b[t[i]] = s[i];
            }
        }

        Console.WriteLine("Yes");
    }
}