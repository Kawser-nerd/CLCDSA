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
        var csf = new int[num-1][];
        for (var i = 0; i < num-1; i++)
            csf[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        for(var i = 0; i < num; i++)
        {
            var time = 0;
            for(var j = i; j < num-1; j++)
            {
                if (time < csf[j][1]) time = csf[j][1];
                else if (time % csf[j][2] != 0) time += csf[j][2] - time % csf[j][2];
                time += csf[j][0];
            }
            WriteLine(time);
        }
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}