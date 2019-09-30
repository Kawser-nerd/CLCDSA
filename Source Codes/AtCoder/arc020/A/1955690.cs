using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] ab = Console.ReadLine().Split().Select(x => Math.Abs(int.Parse(x))).ToArray();
        Console.WriteLine(ab[0] == ab[1] ? "Draw" :(ab[0] < ab[1] ? "Ant" : "Bug"));
    }
}