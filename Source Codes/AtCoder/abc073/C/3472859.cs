using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> list = new List<int>();
        
        for (int i = 0; i < n; i++){
            list.Add(int.Parse(Console.ReadLine()));
        }

        Console.WriteLine(
            list.GroupBy(x => x)
            .Select(x => x.Count())
            .Where(x => x % 2 == 1)
            .Count());
    }
}