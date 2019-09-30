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
        var res = "";
        while (num != 0)
            if (num % 2 != 0)
            {
                res = "1" + res;
                num = (num - 1) / -2;
            }
            else
            {
                res = "0" + res;
                num /= -2;
            }
        WriteLine(res==""?"0":res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}