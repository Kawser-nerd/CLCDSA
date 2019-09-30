using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] hw = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Console.WriteLine((hw[0] - 1) * hw[1] + (hw[1] - 1) * hw[0]);

    }
}