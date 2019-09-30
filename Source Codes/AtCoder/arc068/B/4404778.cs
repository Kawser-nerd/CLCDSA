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
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var dic = new Dictionary<int, int>();
        for (var i = 0; i < num; i++)
            if (dic.ContainsKey(ar[i])) dic[ar[i]]++;
            else dic[ar[i]] = 1;
        WriteLine(dic.Keys.Count % 2 == 0 ? dic.Keys.Count-1 : dic.Keys.Count);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}