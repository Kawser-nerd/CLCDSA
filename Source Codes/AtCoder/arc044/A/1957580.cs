using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int a = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        Console.WriteLine((a == 2 || a == 3 || a == 5) || (a % 2 != 0 && a % 3 != 0 && a % 5 != 0 && a != 1)? "Prime" : "Not Prime");
    }
}