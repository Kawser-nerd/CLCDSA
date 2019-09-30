using System;
using System.Linq;
using System.Collections.Generic;

class Atcoder110
{
    public static void Main()
    {
        int i, j, min;
        int n = int.Parse(Console.ReadLine());

        var List = new List<int>();

        for (i = 0; i < n; i++)
        {
            j = int.Parse(Console.ReadLine());
            List.Add(j);
        }

        min = List.Min();
        Console.WriteLine(min);
    }
}