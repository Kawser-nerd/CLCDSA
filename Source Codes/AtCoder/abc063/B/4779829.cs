using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        var set = new HashSet<char>();
        for (int i = 0; i < s.Length; i++)
        {
            if (!set.Add(s[i]))
            {
                Console.WriteLine("no");
                return;
            }
        }
        Console.WriteLine("yes");
    }
}