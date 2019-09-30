using System;
using System.Linq;
using System.Collections.Generic;
class c
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        bool judge = true;
        var list = new List<string>();
        for (int i = 0; i < n; i++)
        {
            list.Add(Console.ReadLine());
        }
        for (int i = 1; i < n; i++)
        {
            if (list[i - 1].Last() != list[i].First()) judge = false;
        }
        if (list.Count() != list.Distinct().Count()) judge = false;
        Console.WriteLine(judge ? "Yes" : "No");
    }
}