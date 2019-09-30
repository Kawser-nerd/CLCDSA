using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        HashSet<string> set = new HashSet<string>();
        string s = Console.ReadLine();
        int k = int.Parse(Console.ReadLine());
        for (int i = 0; i <= s.Length - k; i++)
        {
            set.Add(s.Substring(i, k));
        }
        Console.WriteLine(set.Count);
    }
}