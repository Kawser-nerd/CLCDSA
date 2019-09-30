using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] NT = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int sec = 0;
        int lastsec = int.Parse(Console.ReadLine());
        for (int i = 1; i < NT[0]; i++)
        {
            int a = int.Parse(Console.ReadLine());
            sec += Math.Min(NT[1],a - lastsec);
            lastsec = a;
        }
        sec += NT[1];
        Console.WriteLine(sec);
    }
}