using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var str1 = ReadLine();
        var str2 = ReadLine();
        var res = 3L;
        for(var i = 0; i < num-1; i++)
        {
            if (i > 1 && str1[i] == str1[i + 1] && str1[i - 1] == str1[i - 2])
                res *= 3;
            else if (str1[i] == str1[i + 1])
                res *= 2;
            else if ((i==0&&str1[1]==str2[1])||(i>0&&str1[i]!=str1[i-1]&&str1[i+1]==str2[i+1]))
                res *= 2;
            res %= MOD;
        }
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}