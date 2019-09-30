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
        var result = new int[6];
        for(var i = 0; i < num; i++)
        {
            var temp = Array.ConvertAll(ReadLine().Split(' '), double.Parse);
            if (temp[0] >= 35) result[0]++;
            else if (temp[0] >= 30) result[1]++;
            else if (temp[0] >= 25) result[2]++;
            else if (temp[0] < 0) result[5]++;
            if (temp[1] >= 25) result[3]++;
            if (temp[1] < 0 && temp[0] >= 0) result[4]++;
        }
        WriteLine(string.Join(" ", result));
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}