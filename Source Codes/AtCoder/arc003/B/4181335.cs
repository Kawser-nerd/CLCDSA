using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        var N = int.Parse(Console.ReadLine());
        var list = new SortedSet<string>();
        for (int i = 0; i < N; i++)
        {
            list.Add(new string(Console.ReadLine().ToCharArray().Reverse().ToArray()));
        }

        foreach (var word in list)
        {
            Console.WriteLine(new string(word.ToCharArray().Reverse().ToArray()));
        }
    }
}