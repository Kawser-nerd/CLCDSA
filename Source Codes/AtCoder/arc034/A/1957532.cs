using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        double max = 0;
        for (int i = 0; i < n; i++)
        {
            int[] point = Console.ReadLine().Split().Select(int.Parse).ToArray();
            max = Math.Max(point.Sum() - point[4] * 0.8777777777777777777777777,max);
        }
        Console.WriteLine(max);

    }
}