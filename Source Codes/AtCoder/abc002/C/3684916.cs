using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var abc = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        for(var i = 2; i < 6; i++)
        {
            abc[i] -= abc[i % 2];
        }
        WriteLine((double)Abs(abc[2] * abc[5] - abc[3] * abc[4]) / 2);
    }
    
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}