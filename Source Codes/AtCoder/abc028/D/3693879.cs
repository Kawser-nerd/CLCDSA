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
        var nk = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        WriteLine(((double)(nk[0]-nk[1])*(nk[1]-1)*6+3*(nk[0]-1)+1)/Pow(nk[0],3));

    }

    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}