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
        var s = ReadLine();
        var k = ToInt64(ReadLine());
        for (var i = 0; i < s.Length; i++)
            if (s[i] != '1')
            {
                WriteLine(s.Substring(i, 1));
                break;
            }else if (i+1 == k)
            {
                WriteLine("1");
                break;
            }
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}