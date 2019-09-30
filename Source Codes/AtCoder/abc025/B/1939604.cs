using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] NAB = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int pos = 0;
        for (int i = 0; i < NAB[0]; i++)
        {
            string[] sd = Console.ReadLine().Split();
            pos += Math.Min(Math.Max(NAB[1], int.Parse(sd[1])), NAB[2]) * (sd[0] == "East" ? -1 : 1);
        }
        if (pos > 0)
        {
            Console.Write("West ");
        }
        else if(pos < 0)
        {
            Console.Write("East ");
        }

        Console.WriteLine(Math.Abs(pos));
    }
}