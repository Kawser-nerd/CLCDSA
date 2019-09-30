using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;

class Solution
{
    static void Main(string[] args)
    {
        int[] nab = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        Console.WriteLine((nab[2] - nab[1]) % 2 == 0 ? "Alice" : "Borys");
    }
}