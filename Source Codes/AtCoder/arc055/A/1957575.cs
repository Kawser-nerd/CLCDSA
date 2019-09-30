using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
        //int a = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        Console.WriteLine($"1{"".PadLeft(int.Parse(Console.ReadLine()) - 1,'0')}7");
    }
}