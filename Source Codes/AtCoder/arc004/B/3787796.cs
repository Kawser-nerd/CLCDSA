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
        var num = ToInt32(ReadLine());
        var diff = new int[num];
        for (var i = 0; i < num; i++)
            diff[i] = ToInt32(ReadLine());
        WriteLine(diff.Sum());
        WriteLine(Max(0, 2 * diff.Max() - diff.Sum()));
        /*
        max???sum????????????0??????
        ???i??i+1???????????????.
        max>sum???????????
         */
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}