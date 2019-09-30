using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;


class Program {
    

    internal static void Main(string[] args)
    {
        int[] inp = ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int N = inp[0];
        int M = inp[1];
        int X = inp[2];
        int[] A = ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

        WriteLine(Math.Min(A.Where(i => i < X).Count(),
                           A.Where(i => i > X).Count()));
    }
}