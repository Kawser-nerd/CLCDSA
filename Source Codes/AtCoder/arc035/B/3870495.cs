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
        var time = new int[num];
        var dic = new Dictionary<int, int>();
        for (var i = 0; i < num; i++)
        {
            time[i] = ToInt32(ReadLine());
            if (dic.ContainsKey(time[i])) dic[time[i]]++;
            else dic[time[i]] = 1;
        }
        Array.Sort(time);
        var t = 0L;
        var pe = 0L;
        for(var i = 0; i < num; i++)
        {
            t += time[i];
            pe += t;
        }
        var re = 1L;
        foreach(var co in dic.Values)
        {
            for (var i = 2; i <= co; i++)
            {
                re *= i;
                re %= MOD;
            }
        }
        WriteLine($"{pe}\n{re}");
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}