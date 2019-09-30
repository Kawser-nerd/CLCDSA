using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //string a = Console.ReadLine();
        int t = int.Parse(Console.ReadLine());
        //int[] NQ = Console.ReadLine().Split().Select(int.Parse).ToArray();
        //string[] s = new string[a].Select(_ => Console.ReadLine()).ToArray();
        Console.WriteLine(t + (t % 2 == 0 ? -1 : 1));
    }
}