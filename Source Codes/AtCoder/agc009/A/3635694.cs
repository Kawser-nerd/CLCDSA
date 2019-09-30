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
        var ar = new int[num][];
        for (var i = 0; i < num; i++)
            ar[i] =Array.ConvertAll(ReadLine().Split(' '),int.Parse);
        var dif = 0L;
        for (var i = num - 1; i >= 0; i--)
        {
            dif += (ar[i][0]+dif)%ar[i][1]!=0?ar[i][1] - (ar[i][0]+dif) % ar[i][1]:0;
        }
        WriteLine(dif);
    }
}