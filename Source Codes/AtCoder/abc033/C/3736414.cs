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
        var str = ReadLine();
        var affi = str.Split('+');
        var result = 0;
        for(var i = 0; i < affi.Length; i++)
        {
            var nums = affi[i].Split('*');
            var isZero = false;
            for(var j=0;j<nums.Length;j++)
                if (nums[j][0] == '0') { isZero = true;break; }
            if (!isZero) result ++;
        }
        WriteLine(result);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}