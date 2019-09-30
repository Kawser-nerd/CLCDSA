using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.ReadLine();
        int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
        //int n = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        int res = 0;
        for (int i = 0; i < n.Length; i++)
        {
            res += Math.Max(80 - n[i], 0);
        }
        Console.WriteLine(res);

    }
}