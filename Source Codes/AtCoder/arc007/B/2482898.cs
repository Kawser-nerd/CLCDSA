using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int currentDisc = 0;
        List<int> disclist = Enumerable.Range(1, nm[0]).ToList();
        for (int i = 0; i < nm[1]; i++)
        {
            int disc = int.Parse(Console.ReadLine());
            if (disc == currentDisc) continue;
            int index = disclist.IndexOf(disc);
            disclist[index] = currentDisc;
            currentDisc = disc;
        }
        Console.WriteLine(string.Join("\n",disclist));
    }
}