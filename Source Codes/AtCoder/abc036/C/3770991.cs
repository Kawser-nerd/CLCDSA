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
        var a = new int[num];
        var s = new SortedSet<int>();
        for (var i = 0; i < num; i++)
        {
            a[i] = ToInt32(ReadLine());
            s.Add(a[i]);
        }
        var dic = new Dictionary<int, int>();
        var index = 0;
        foreach(var val in s)
        {
            dic[val] = index;
            index++;
        }
        for(var i = 0; i < num; i++)
        {
            WriteLine(dic[a[i]]);
        }
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}