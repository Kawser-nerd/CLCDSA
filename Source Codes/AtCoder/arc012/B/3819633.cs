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
        var nabl = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        double dif = nabl[3];
        for(var i = 0; i < nabl[0]; i++)
        {
            var time = dif / nabl[1];
            dif = nabl[2] * time;
        }
        WriteLine(string.Format("{0:f7}", dif));
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}