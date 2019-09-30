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
        if (num == 1) { WriteLine(1);return; }
        var hei = new int[num];
        for (var i = 0; i < num; i++)
            hei[i] = ToInt32(ReadLine());
        var dif = new int[num];
        for (var i = 1; i < num; i++)
            if (hei[i] - hei[i - 1] == 0) dif[i] = 0;
            else if (hei[i] - hei[i - 1] > 0) dif[i] = 1;
            else dif[i] = -1;
        var result = 0;
        var cou = 1;
        for(var i =2; i < num; i++)
        {
            cou++;
            if ((dif[i - 1] == -1 && dif[i] == 1) || dif[i] == 0) cou = 1;
            result = Max(result, cou + 1);
        }
        WriteLine(result);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}