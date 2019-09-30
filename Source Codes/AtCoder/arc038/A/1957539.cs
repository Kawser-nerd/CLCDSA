using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.ReadLine();
        //int[] n = Console.ReadLine().Split().Select(int.Parse).OrderByDescending(x => x).Where((_, ind) => ind % 2 == 0).Sum();
        //int n = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        Console.WriteLine(Console.ReadLine().Split().Select(int.Parse).OrderByDescending(x => x).Where((_, ind) => ind % 2 == 0).Sum());

    }
}