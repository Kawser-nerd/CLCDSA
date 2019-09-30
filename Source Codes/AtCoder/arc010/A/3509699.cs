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
        var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var num = input[0];
        var day = input[1];
        var min = input[2];
        var sup = input[3];
        var da = new int[day];
        for (var i = 0; i < day; i++) da[i] = ToInt32(ReadLine());
        var result = -1;
        for(var i = 0; i < day; i++)
        {
            if (num <= min) num += sup;
            num -= da[i];
            if (num < 0) { result = i+1;break; }
        }
        WriteLine(result==-1?"complete":result.ToString());
    }
}