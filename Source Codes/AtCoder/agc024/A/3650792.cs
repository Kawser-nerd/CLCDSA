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
        var abck = Array.ConvertAll(ReadLine().Split(' '), long.Parse);
        if (abck[3] % 2 == 0) WriteLine(abck[0] - abck[1]);
        else WriteLine(abck[1] - abck[0]);

    }

    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}