using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        for (int i = 0; i < s.Length; i++)
        {
            if (a.Contains(i)) Console.Write("\"");
            Console.Write(s[i]);
        }
        if (a.Contains(s.Length)) Console.Write("\"");
        Console.WriteLine();
    }
}