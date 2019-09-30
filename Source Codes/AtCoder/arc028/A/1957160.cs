using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] nab = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Console.WriteLine(nab[0] % (nab[1] + nab[2]) <= nab[1] && nab[0] % (nab[1] + nab[2]) != 0? "Ant" : "Bug");
    }
}