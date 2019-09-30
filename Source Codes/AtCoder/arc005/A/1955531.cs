using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();
        string[] choku = { "TAKAHASHIKUN", "Takahashikun", "takahashikun" };
        Console.WriteLine(s.Substring(0,s.Length - 1).Split().Count(x => choku.Contains(x)));
    }
}