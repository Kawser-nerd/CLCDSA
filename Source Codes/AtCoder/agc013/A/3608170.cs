using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var result = 1;
        var isIncrease = true;
        var i = 0;
        Get(ref i, ref isIncrease, ar);
        for(var j = i + 1; j < num-1; j++)
            if (isIncrease)
            {
                if (ar[j] <= ar[j + 1]) continue;
                else { result++;Get(ref j, ref isIncrease, ar); }
            }
            else
            {
                if (ar[j] >= ar[j + 1]) continue;
                else { result++;Get(ref j, ref isIncrease, ar); }
            }
        WriteLine(result);
    }

    private static void Get(ref int j,ref bool isIncrease,int[] ar)
    {
        for (var i = j==0?0:j+1; i < ar.Length-1; i++)
            if (ar[i] == ar[i + 1]) continue;
        else if (ar[i] < ar[i + 1]) { isIncrease = true;break; }
        else { isIncrease = false;break; }
    }
}