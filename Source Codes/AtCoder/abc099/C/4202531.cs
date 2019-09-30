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
        var res = num;
        for(var i = 0; i <= num; i++)
        {
            var cc = 0;
            var t = i;
            while (t > 0)
            {
                cc += t % 6;
                t /= 6;
            }
            t = num - i;
            while (t > 0)
            {
                cc += t % 9;
                t /= 9;
            }
            res = Min(res, cc);
        }
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}