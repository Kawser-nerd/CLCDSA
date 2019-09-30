using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] NCK = Console.ReadLine().Split().Select(int.Parse).ToArray();
        List<int> tourist = new List<int>();
        for (int i = 0; i < NCK[0]; i++) tourist.Add(int.Parse(Console.ReadLine()));
        tourist.Sort();
        int buslim = -1;
        int busnin = 0;
        int res = 0;
        foreach (var i in tourist)
        {
            if (buslim < i || busnin == NCK[1])
            {
                buslim = i + NCK[2];
                busnin = 1;
                res++;
            }
            else
            {
                busnin++;
            }
        }

        Console.WriteLine(res);
    }
}