using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //int[] hm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        Console.WriteLine(n * (n + 1) / 2);

    }
}